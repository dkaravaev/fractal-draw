module FractalRecipe where 

import Util

import GHC.Float
import qualified Graphics.UI.GLUT as GLU
import Data.Complex
import qualified Data.Matrix as Matrix
import Data.Array

calcz0::Complex GLU.GLfloat -> Complex GLU.GLfloat ->  Complex GLU.GLfloat -> Complex GLU.GLfloat
calcz0 ta tb tab = num / denom
                   where num = (tab - 2) * tb
                         denom = tb * tab - 2 * ta + (0 :+ 2) * tab
{-
    a(0, 0) = ta / 2;
    a(0, 1) = (ta * tab - 2 * tb + 4 * i) / ((2 * tab + 4) * z0);
    a(1, 0) = ((ta * tab - 2 * tb - 4 * i) * z0) / (2 * tab - 4);
    a(1, 1) = a(0, 0);
-}

abTrans::Complex GLU.GLfloat -> Complex GLU.GLfloat -> Array Int (Matrix.Matrix(Complex GLU.GLfloat))
abTrans ta tb = listArray (0, 3) [a, b, inverseMatrix $ a, inverseMatrix $ b] 
          where i = (0 :+ 1)
                tab = solveMarkovEquation ta tb
                z0 = calcz0 ta tb tab
                a = Matrix.fromList 2 2 [ta / 2, (ta * tab - 2 * tb + 4 * i) / ((2 * tab + 4) * z0), ((ta * tab - 2 * tb - 4 * i) * z0) / (2 * tab - 4), ta / 2]
                b = Matrix.fromList 2 2 [(tb - 2 * i) / 2 , tb / 2, tb / 2, (tb + 2 * i) / 2]

