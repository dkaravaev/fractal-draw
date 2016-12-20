#include "FractalDFS.hpp"


void make_matrix(std::vector<matrix<std::complex<ldouble>>> & gens, const abTrans & rgens)
{
    gens[0] = rgens.first;
    gens[1] = rgens.second;

    InvertMatrix<std::complex<ldouble>>(gens[0], gens[2]);
    InvertMatrix<std::complex<ldouble>>(gens[1], gens[3]);
}

FractalDFS::FractalDFS() {}

FractalDFS::FractalDFS(const std::unique_ptr<FractalRecipe> & recipe, int levmax, ldouble epsilon, const std::string & mode) :
        gens(GROUP_SIZE),
        rept(GROUP_SIZE),
        fp(GROUP_SIZE),
        word(GROUP_SIZE * levmax),
        tags(GROUP_SIZE * levmax),
        levmax(levmax),
        epsilon(epsilon),
        points(0),
        compute_time(0),
        mode(mode)
{

    for(uint i = 0; i < gens.size(); ++i)
    {
        gens[i] = matrix<std::complex<ldouble>>(2, 2);
    }

    for(uint i = 0; i < word.size(); ++i)
    {
        word[i] = matrix<std::complex<ldouble>>(2, 2);
    }

    make_matrix(gens, recipe->trans());
    /*gens[0](0, 0) = std::complex<ldouble>(1, 0);
    gens[0](0, 1) = std::complex<ldouble>(0, 0);
    gens[0](1, 0) = std::complex<ldouble>(0.05, 0.93);
    gens[0](1, 1) = std::complex<ldouble>(1, 0);

    gens[1](0, 0) = std::complex<ldouble>(1, 0);
    gens[1](0, 1) = std::complex<ldouble>(2, 0);
    gens[1](1, 0) = std::complex<ldouble>(0, 0);
    gens[1](1, 1) = std::complex<ldouble>(1, 0);

    InvertMatrix<std::complex<ldouble>>(gens[0], gens[2]);
    InvertMatrix<std::complex<ldouble>>(gens[1], gens[3]);*/

    for(uint j = 0; j < rept.size(); ++j)
    {
        if(mode == "p")
        {
            complete_reps_parabol(rept[j], j);
        }
        else
        {
            complete_reps_semiparabol(rept[j], j);
        }
    }

    for(uint i = 0; i < rept.size(); ++i)
    {
        for(uint j = 0; j < rept[i].size(); ++j)
        {
            fp[i].push_back(fixed_point(rept[i][j]));
        }
    }

    lev = 0;
    tags[0] = 0;
    word[0] = gens[0];
}

int FractalDFS::epsilon_check(const std::vector<std::complex<ldouble>> & z)
{
    int ans = 0;

    for(uint i = 0; i < z.size() - 1; ++i)
    {
        ans += (std::abs(z[i] - z[i + 1]) <= epsilon);
    }

    return(ans/(z.size() - 1));
}

void FractalDFS::explore_tree(matrix<std::complex<ldouble>> x, int level)
{
    for(int k = level - 1; k <= level + 1; ++k)
    {
        auto y = prod(x, gens[mod(k, 4)]);
        for(uint j = 0; j < rept[mod(k, 4)].size(); ++j)
        {
            z.push_back(mobius_on_point(y, fp[mod(k, 4)][j]));
        }

        if (epsilon_check(z))
        {
            glBegin(GL_LINE_STRIP);
            glVertex2d((GLdouble)tailpoint.real(), (GLdouble)tailpoint.imag());
                for(auto & i : z)
                {
                     glVertex2d((GLdouble)i.real(), (GLdouble)i.imag());
                }
            glEnd();

            lastpoint = tailpoint = z.back();
            z.clear();
        }
        else
        {
            z.clear();
            explore_tree(y, k);
        }
    }
}


void FractalDFS::render_fractal_recurs()
{
    auto t1 = timeCurrentMilliseconds();

    for(int k = 0; k < GROUP_SIZE; ++k)
    {
        explore_tree(gens[k], k);
    }
    close_lim_set();

    auto t2 = timeCurrentMilliseconds();
    compute_time = t2 - t1;
}

void FractalDFS::render_fractal()
{
    auto t1 = timeCurrentMilliseconds();

    while(true)
    {
        while(!branch_termination())
        {
            go_forward();
        }

        do
        {
            go_backward();
        }
        while((lev != -1) && !available_turn());

        if((lev != -1) || (tags[0] != 1))
        {
            turn_and_go_forward();
        }
        else
        {
            break;
        }
    }
    close_lim_set();

    auto t2 = timeCurrentMilliseconds();
    compute_time = t2 - t1;
}

void FractalDFS::go_forward()
{
    lev++;
    tags[lev] = mod(tags[lev - 1] + 1, 4);
    word[lev] = prod(word[lev - 1], gens[tags[lev]]);
}

void FractalDFS::go_backward()
{
    lev--;
}

bool FractalDFS::available_turn()
{
    bool cond = (mod(tags[lev + 1]  - 1, 4) == mod(tags[lev] + 2, 4));
    return(!cond);
}

void FractalDFS::turn_and_go_forward()
{
    tags[lev + 1] = mod(tags[lev + 1] - 1, 4);

    if(lev == -1)
    {
        word[0] = gens[tags[0]];
    }
    else
    {
        word[lev + 1] = prod(word[lev], gens[tags[lev + 1]]);
    }

    lev++;
}


bool FractalDFS::branch_termination()
{
    for(uint j = 0; j < rept[tags[lev]].size(); ++j)
    {
        z.push_back(mobius_on_point(word[lev], fp[tags[lev]][j]));
    }

    if ((lev == levmax) || epsilon_check(z))
    {
        /* Check for entering here for the first time */
        if(points == 0)
        {
            firstpoint = tailpoint = *(std::begin(z));
        }

        points += z.size();

        glBegin(GL_LINE_STRIP);
             glVertex2d((GLdouble)tailpoint.real(), (GLdouble)tailpoint.imag());
             for(auto & i : z)
             {
                 glVertex2d((GLdouble)i.real(), (GLdouble)i.imag());
             }
        glEnd();

        lastpoint = tailpoint = z.back();
        z.clear();

        return(true);
    }
    else
    {
        z.clear();
        return(false);
    }
}

void FractalDFS::close_lim_set()
{
    glBegin(GL_LINE_STRIP);
        glVertex2d((GLdouble)firstpoint.real(), (GLdouble)firstpoint.imag());
        glVertex2d((GLdouble)lastpoint.real(), (GLdouble)lastpoint.imag());
    glEnd();
}

void FractalDFS::complete_reps_semiparabol(std::vector<matrix<std::complex<ldouble>>> & rep, int j)
{
    switch(j) {
        case 0: {
            rep.push_back(quad_mult(gens[1], gens[2], gens[3], gens[0]));
            rep.push_back(triple_mult(gens[0], gens[3], gens[0]));
            rep.push_back(triple_mult(gens[3], gens[0], gens[0]));
            rep.push_back(quad_mult(gens[3], gens[2], gens[1], gens[0]));
            break;
        }
        case 1: {
            rep.push_back(quad_mult(gens[2], gens[3], gens[0], gens[1]));
            rep.push_back(triple_mult(gens[2], gens[2], gens[1]));
            rep.push_back(quad_mult(gens[0], gens[3], gens[2], gens[1]));
            break;
        }
        case 2: {
            rep.push_back(quad_mult(gens[3], gens[0], gens[1], gens[2]));
            rep.push_back(triple_mult(gens[2], gens[1], gens[2]));
            rep.push_back(triple_mult(gens[1], gens[2], gens[2]));
            rep.push_back(quad_mult(gens[1], gens[0], gens[3], gens[2]));
            break;
        }
        case 3: {
            rep.push_back(quad_mult(gens[0], gens[1], gens[2], gens[3]));
            rep.push_back(triple_mult(gens[0], gens[0], gens[3]));
            rep.push_back(quad_mult(gens[2], gens[1], gens[0], gens[3]));
            break;
        }
        default:
            break;
    }
}


void FractalDFS::complete_reps_parabol(std::vector<matrix<std::complex<ldouble>>> &rep, int j)
{
    switch(j) {
        case 0: {
            rep.push_back(quad_mult(gens[1], gens[2], gens[3], gens[0]));
            rep.push_back(gens[0]);
            rep.push_back(quad_mult(gens[3], gens[2], gens[1], gens[0]));
            break;
        }
        case 1: {
            rep.push_back(quad_mult(gens[2], gens[3], gens[0], gens[1]));
            rep.push_back(gens[1]);
            rep.push_back(quad_mult(gens[0], gens[3], gens[2], gens[1]));
            break;
        }
        case 2: {
            rep.push_back(quad_mult(gens[3], gens[0], gens[1], gens[2]));
            rep.push_back(gens[2]);
            rep.push_back(quad_mult(gens[1], gens[0], gens[3], gens[2]));
            break;
        }
        case 3: {
            rep.push_back(quad_mult(gens[0], gens[1], gens[2], gens[3]));
            rep.push_back(gens[3]);
            rep.push_back(quad_mult(gens[2], gens[1], gens[0], gens[3]));
            break;
        }
        default:
            break;
    }
}

void FractalDFS::info()
{
    std::cout << "Info :" << std::endl;
    std::cout << "\tImage has : " << points << " complex points." << std::endl;
    std::cout << "\tComputation Time : " << compute_time << " mls." << std::endl;
    std::cout << "\tUsing " << mode << " repetisions." << std::endl;
    std::cout << "\t\tTrace of a : " << trace(gens[0]) << std::endl;
    std::cout << "\t\tTrace of b : " << trace(gens[1]) << std::endl;
}

