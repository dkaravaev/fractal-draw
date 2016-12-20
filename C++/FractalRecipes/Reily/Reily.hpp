#ifndef REILY_HPP
#define REILY_HPP

#include "../FractalRecipe.hpp"

class ReilyRecipe : public FractalRecipe
{
public:
    ReilyRecipe(ldouble cr, ldouble ci);

    abTrans trans() override;

private:
    std::complex<ldouble> c;
};

#endif