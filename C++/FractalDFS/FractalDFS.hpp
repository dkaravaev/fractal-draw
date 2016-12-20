#ifndef FRACTAL_DFS_HPP
#define FRACTAL_DFS_HPP

#include <future>
#include <map>

#include "../utils/util.hpp"
#include "../FractalRecipes/FractalRecipe.hpp"

enum
{
    GROUP_SIZE = 4,
};

using Group = std::vector<matrix<std::complex<ldouble>>>;

class FractalDFS
{
public:
    FractalDFS();

    FractalDFS(const std::unique_ptr<FractalRecipe> & recipe, int levmax, ldouble epsilon, const std::string & mode);

    void render_fractal();

    void render_fractal_recurs();

    void info();

private:
    /* For non-recursive version */
    void go_forward();

    void go_backward();

    bool available_turn();

    void turn_and_go_forward();

    bool branch_termination();

    /* Completing repetitions for tracking */
    void complete_reps_semiparabol(std::vector<matrix<std::complex<ldouble>>> & rep, int j);

    void complete_reps_parabol(std::vector<matrix<std::complex<ldouble>>> & rep, int j);

    /* For recursive version */
    void explore_tree(matrix<std::complex<ldouble>> x, int level);

    /* Checking for points for epsilon condition */
    int epsilon_check(const std::vector<std::complex<ldouble>> & z);

    /* Closing the limited set */
    void close_lim_set();
private:
    /* Elements of group */
    Group gens;

    /* Repetitions of elements of group */
    std::vector<Group> rept;

    /* Fixed points of repetitions */
    std::vector<std::vector<std::complex<ldouble>>> fp;

    /* Points to draw */
    std::vector<std::complex<ldouble>> z;

    /* Multiplications of groups and tags (for non-recursive algorithm) */
    std::vector<matrix<std::complex<ldouble>>> word;
    std::vector<int> tags;

    /* Point need for connecting separated parts of splines */
    std::complex<ldouble> tailpoint;

    /* Points need for closing the limited set*/
    std::complex<ldouble> firstpoint;
    std::complex<ldouble> lastpoint;

    /* max level and current level (for non-recursive algorithm)*/
    int levmax;
    int lev;

    /* Min distance between two points in Fractal */
    ldouble epsilon;

    /* Total points in Fractal */
    uint64_t points;
    /* Computation time */
    uint64_t compute_time;

    /* Mode : parabol or semiparabol */
    std::string mode;
};

#endif