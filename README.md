# fractal-draw

*In the glistening surface of each pearl are reflected all the other pearls ... In each reflection, again are reflected all the infinitely many other pearls, so that by this process, reflections of reflections continue without end.*

## Why it exists?
This program reflects my small interest in group theory, complex analysis, fractal geomtry and Haskell programming.

Too draw "your" fractal you need to propose to complex numbers representing the traces of Mebius transformations A and B. 

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

Changing the epsilon (render level). Made in Haskell version.

1. epsilon = 0.1

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/Haskell/results/0.1c.png)

2. epsilon = 0.01

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/Haskell/results/0.01c.png)

3. epsilon = 0.001

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/Haskell/results/0.001c.png)

4. epsilon = 0.0005

![alt text](https://github.com/dkaravaev/fractal-draw/blob/master/Haskell/results/0.0005c.png)

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

