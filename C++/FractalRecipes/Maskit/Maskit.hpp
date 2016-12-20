#ifndef MASKIT_HPP
#define MASKIT_HPP

#include "../FractalRecipe.hpp"

class MaskitRecipe : public FractalRecipe
{
public:
    MaskitRecipe(ldouble mr, ldouble mi);

    abTrans trans() override;

private:
    std::complex<ldouble> m;
};

#endif