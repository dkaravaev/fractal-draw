#ifndef FRACTAL_RECIPE_HPP
#define FRACTAL_RECIPE_HPP

#include "../utils/util.hpp"

using abTrans = std::pair<matrix<std::complex<ldouble>>, matrix<std::complex<ldouble>>>;

class FractalRecipe
{
public:
    FractalRecipe();

    virtual abTrans trans() = 0;

    virtual ~FractalRecipe();

protected:
    /* traces */
    std::complex<ldouble> ta;
    std::complex<ldouble> tb;

    /* Group Genesis */
    matrix<std::complex<ldouble>> a;
    matrix<std::complex<ldouble>> b;

    /* Numbers */
    std::complex<ldouble> i;
};
#endif