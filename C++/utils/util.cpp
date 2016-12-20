#include "util.hpp"

int mod(int a, int b)
{
    int r = a % b;
    return r >= 0 ? r : r + std::abs(b);
}

std::complex<ldouble> det(const matrix<std::complex<ldouble>> & m)
{
    return(m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0));
}

std::complex<ldouble> mobius_on_point(const matrix<std::complex<ldouble>> & T, std::complex<ldouble> z)
{
    return(T(0,0) * z + T(0, 1)) / (T(1,0) * z + T(1, 1));
}

matrix<std::complex<ldouble>> quad_mult(const matrix<std::complex<ldouble>> & m1,
                                         const matrix<std::complex<ldouble>> & m2,
                                         const matrix<std::complex<ldouble>> & m3,
                                         const matrix<std::complex<ldouble>> & m4) {
    matrix<std::complex<ldouble>> p1 = prod(m1, m2);
    matrix<std::complex<ldouble>> p2 = prod(m3, m4);

    return(prod(p1, p2));
}

matrix<std::complex<ldouble>> triple_mult(const matrix<std::complex<ldouble>> & m1,
        const matrix<std::complex<ldouble>> & m2,
        const matrix<std::complex<ldouble>> & m3)
{
    matrix<std::complex<ldouble>> p1 = prod(m1, m2);
    return(prod(p1, m3));
}

std::complex<ldouble> trace(const matrix<std::complex<ldouble>> & t)
{
    return(t(0, 0) + t(1, 1));
}

std::complex<ldouble> fixed_point(const matrix<std::complex<ldouble>> & t)
{
    std::complex<ldouble> z;

    if(t(1, 0) != std::complex<ldouble>(0, 0))
    {
        auto tr = trace(t);

        z = (t(0, 0) - t(1, 1) + sqrt(tr * tr - std::complex<ldouble>(4, 0))) /
                std::complex<ldouble>(2, 0) * t(1, 0);
    }
    else
    {
        z = -t(0, 1) / (t(0, 0) - t(1, 1));
    }

    return(z);
}

uint64_t timeCurrentMilliseconds()
{
    return(std::abs(std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::system_clock::now().time_since_epoch()).count()));
}


std::complex<ldouble> solve_markov_equation(const std::complex<ldouble> & ta, const std::complex<ldouble> & tb)
{
    auto b = -ta * tb;
    auto c = ta * ta + tb * tb;
    std::complex<ldouble> det = b * b - 4 * c;

    if(tb.imag() != 0)
        return (-b + sqrt(det)) / 2;
    return (-b - sqrt(det)) / 2 ;
}