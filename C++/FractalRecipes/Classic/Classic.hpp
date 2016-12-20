#ifndef CLASSIC_HPP
#define CLASSIC_HPP

#include "../FractalRecipe.hpp"

class ClassicRecipe : public FractalRecipe
{
public:
    ClassicRecipe(ldouble ar, ldouble ai, ldouble br, ldouble bi);

    abTrans trans() override;

private:
    std::complex<ldouble> tab;

private:
    std::complex<ldouble> calc_z0(const std::complex<ldouble> & ta, const std::complex<ldouble> & tb,
            const std::complex<ldouble> & tab);
};

#endif