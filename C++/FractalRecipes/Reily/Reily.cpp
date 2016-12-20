#include "Reily.hpp"

ReilyRecipe::ReilyRecipe(ldouble cr, ldouble ci) :
        FractalRecipe(),
        c(cr, ci)
{
    ta = std::complex<ldouble>(2, 0);
    tb = std::complex<ldouble>(2, 0);
}



abTrans ReilyRecipe::trans()
{
    a(0, 0) = 1;
    a(0, 1) = 0;
    a(1, 0) = c;
    a(1, 1) = 1;

    b(0, 0) = 1;
    b(0, 1) = 2;
    b(1, 0) = 0;
    b(1, 1) = 1;

    return(std::pair<matrix<std::complex<ldouble>>, matrix<std::complex<ldouble>>>(a, b));
}
