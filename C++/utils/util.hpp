#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <complex>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include <map>
#include <thread>

#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/io.hpp>

#define MATH_PI                 3.14159265358979323846

using namespace boost::numeric::ublas;

using ldouble = double;


std::complex<ldouble> mobius_on_point(const matrix<std::complex<ldouble>> & T, std::complex<ldouble> z);

std::complex<ldouble> det(const matrix<std::complex<ldouble>> & m);

int mod(int a, int b);

template<typename T>
bool InvertMatrix(const matrix<T>& input, matrix<T>& inverse)
{
        typedef permutation_matrix<std::size_t> pmatrix;

        // create a working copy of the input
        matrix<T> A(input);

        // create a permutation matrix for the LU-factorization
        pmatrix pm(A.size1());

        // perform LU-factorization
        int res = lu_factorize(A, pm);
        if (res != 0)
                return false;

        // create identity matrix of "inverse"
        inverse.assign(identity_matrix<T> (A.size1()));

        // backsubstitute to get the inverse
        lu_substitute(A, pm, inverse);

        return true;
}

std::complex<ldouble> fixed_point(const matrix<std::complex<ldouble>> & t);

std::complex<ldouble> trace(const matrix<std::complex<ldouble>> & t);

matrix<std::complex<ldouble>> quad_mult(const matrix<std::complex<ldouble>> & m1,
        const matrix<std::complex<ldouble>> & m2,
        const matrix<std::complex<ldouble>> & m3,
        const matrix<std::complex<ldouble>> & m4);

matrix<std::complex<ldouble>> triple_mult(const matrix<std::complex<ldouble>> & m1,
        const matrix<std::complex<ldouble>> & m2,
        const matrix<std::complex<ldouble>> & m3);

uint64_t timeCurrentMilliseconds();

std::complex<ldouble> solve_markov_equation(const std::complex<ldouble> & ta, const std::complex<ldouble> & tb);

#endif