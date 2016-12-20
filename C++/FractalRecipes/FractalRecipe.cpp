#include "FractalRecipe.hpp"

FractalRecipe::FractalRecipe() :
        a(matrix<std::complex<ldouble>>(2, 2)),
        b(matrix<std::complex<ldouble>>(2, 2)),
        i(0, 1)
{

}

FractalRecipe::~FractalRecipe()
{

}