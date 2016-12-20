#ifndef YOURGENS_HPP
#define YOURGENS_HPP

#include "../FractalRecipe.hpp"

class YourgensRecipe : public FractalRecipe
{
public:
    YourgensRecipe(ldouble ar, ldouble ai, ldouble br, ldouble bi);

    abTrans trans() override;

private:
    std::complex<ldouble> tab;
};

#endif