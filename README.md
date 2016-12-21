# fractal-draw

*In the glistening surface of each pearl are reflected all the other pearls ... In each reflection, again are reflected all the infinitely many other pearls, so that by this process, reflections of reflections continue without end.*

Spiral Out...

## Why it exists?
This program reflects my small interest in group theory, complex analysis, fractal geomtry and Haskell programming.

Too draw "your" fractal you need to propose two complex numbers representing the traces of Mebius transformations A and B. 

All algorithms and math were taken from book [Indra's Pearls](https://en.wikipedia.org/wiki/Indra's_Pearls_(book)).

## Some results

Dynamic fractal creation. Made in C++ version.

1. TrA = TrB = 1.98 + 0.05i

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3Dtb%3D1.98%2B0.05.png)

2. TrA = TrB = 1.95 + 0.05i

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3Dtb%3D1.95%2B0.05.png)

3. TrA = TrB = 1.93 + 0.05i 

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3Dtb%3D1.93%2B0.05.png)

4. TrA = TrB = 1.9 + 0.05i

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3Dtb%3D1.9%2B0.05.png)

5. TrA = 1.95 + 0.02i, TrB = 3

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3D1.95%2B0.02tb%3D3.png)

6. TrA = 1.889 + 0.05i, TrB = 2

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3D1.889%2B0.05tb%3D2.png)

7. TrA = 1.888 + 0.05i, TrB = 2

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3D1.888%2B0.05tb%3D2.png)

8. TrA = 1.887 + 0.05i, TrB = 2

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3D1.887%2B0.05tb%3D2.png)

9. TrA = 1.886 + 0.05i, TrB = 2

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/C%2B%2B/results/ta%3D1.886%2B0.05tb%3D2.png)

## Requirements
C++:

1. [CMake](https://cmake.org/)
2. [GLUT](http://freeglut.sourceforge.net/)
3. [Boost](http://www.boost.org/)
4. [OpenGL](https://www.opengl.org/)

Haskell:

1. [Cabal](https://www.haskell.org/cabal/)
2. [matrix](https://hackage.haskell.org/package/matrix-0.3.5.0/docs/Data-Matrix.html)
3. [GLUT](https://hackage.haskell.org/package/GLUT)
4. [array](https://hackage.haskell.org/package/array-0.5.1.1/docs/Data-Array.html)
5. [old-time](https://hackage.haskell.org/package/old-time)

