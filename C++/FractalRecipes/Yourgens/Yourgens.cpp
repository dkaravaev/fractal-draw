#include "Yourgens.hpp"

YourgensRecipe::YourgensRecipe(ldouble tar, ldouble tai, ldouble tbr, ldouble tbi) :
        FractalRecipe()
{
    ta = std::complex<ldouble>(tar, tai);
    tb = std::complex<ldouble>(tbr,tbi);
    tab = solve_markov_equation(ta, tb);
}



abTrans YourgensRecipe::trans()
{
    /*if(det(a) != 1 || det(b) != 1)
    {
        std::cerr << "Warning : determinants are not equal to 1!" << std::endl;
    }*/


    a(0, 0) = ta - (tb / tab);
    a(0, 1) = ta / (tab * tab);
    a(1, 0) = ta;
    a(1, 1) = tb / tab;

    b(0, 0) = tb - (ta / tab);
    b(0, 1) = -tb / (tab * tab);
    b(1, 0) = -tb;
    b(1, 1) = ta / tab;

    return(std::pair<matrix<std::complex<ldouble>>, matrix<std::complex<ldouble>>>(a, b));
}
