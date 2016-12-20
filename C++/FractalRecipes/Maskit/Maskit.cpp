#include "Maskit.hpp"

MaskitRecipe::MaskitRecipe(ldouble mr, ldouble mi) :
        FractalRecipe(),
        m(mr, mi)
{
    ta = -i * m;
    tb = std::complex<ldouble>(2, 0);
}



abTrans MaskitRecipe::trans()
{
    a(0, 0) = ta;
    a(0, 1) = -i;
    a(1, 0) = -i;
    a(1, 1) = 0;

    b(0, 0) = 1;
    b(0, 1) = 2;
    b(1, 0) = 0;
    b(1, 1) = 1;

    return(std::pair<matrix<std::complex<ldouble>>, matrix<std::complex<ldouble>>>(a, b));
}
