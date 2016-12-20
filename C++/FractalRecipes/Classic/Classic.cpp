#include "Classic.hpp"

/* Function for classic recipe */
std::complex<ldouble> ClassicRecipe::calc_z0(const std::complex<ldouble> & ta, const std::complex<ldouble> & tb,
        const std::complex<ldouble> & tab)
{
    auto num = (tab - 2) * tb;
    auto denom = (tb * tab - 2 * ta + 2 * i * tab);

    return num/denom;
}

ClassicRecipe::ClassicRecipe(ldouble tar, ldouble tai, ldouble tbr, ldouble tbi) :
        FractalRecipe()
{
    ta = std::complex<ldouble>(tar, tai);
    tb = std::complex<ldouble>(tbr,tbi);
    tab = solve_markov_equation(ta, tb);
}



abTrans ClassicRecipe::trans()
{
    auto z0 = calc_z0(ta, tb, tab);

    std::cout << z0 << std::endl;
    b(0, 0) = (tb - 2 * i) / 2;
    b(0, 1) = tb / 2;
    b(1, 0) = b(0, 1);
    b(1, 1) = (tb + 2 * i) / 2;


    a(0, 0) = ta / 2;
    a(0, 1) = (ta * tab - 2 * tb + 4 * i) / ((2 * tab + 4) * z0);
    a(1, 0) = ((ta * tab - 2 * tb - 4 * i) * z0) / (2 * tab - 4);
    a(1, 1) = a(0, 0);

    return(std::pair<matrix<std::complex<ldouble>>, matrix<std::complex<ldouble>>>(a, b));
}

