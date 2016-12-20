module Util where

import GHC.Float
import qualified Graphics.UI.GLUT as GLU
import Data.Complex
import qualified Data.Matrix as Matrix


mobiusOnPoint::Matrix.Matrix(Complex GLU.GLfloat)-> Complex GLU.GLfloat -> Complex GLU.GLfloat
mobiusOnPoint tm z = (Matrix.getElem 1 1 tm  * z + Matrix.getElem 1 2 tm )  / (Matrix.getElem 2 1 tm * z + Matrix.getElem 2 2 tm) 

fixedPoint:: Matrix.Matrix(Complex GLU.GLfloat) -> Complex GLU.GLfloat
fixedPoint tm = if Matrix.getElem 2 1 tm == (0 :+ 0) then 
                    -(Matrix.getElem 1 2 tm) / (Matrix.getElem 1 1 tm - Matrix.getElem 2 2 tm)
                else
                    (Matrix.getElem 1 1 tm - Matrix.getElem 2 2 tm + sqrt(disc)) / ((2 :+ 0) * Matrix.getElem 2 1 tm)
                where trace = Matrix.getElem 1 1 tm + Matrix.getElem 2 2 tm
                      disc = trace * trace - (4 :+ 0)
 

inverseMatrix::Matrix.Matrix(Complex  GLU.GLfloat) -> Matrix.Matrix(Complex  GLU.GLfloat)
inverseMatrix tm = Matrix.fromLists [[(Matrix.getElem 2 2 tm) / det, -(Matrix.getElem 1 2 tm) / det]
                                     , [-(Matrix.getElem 2 1 tm) / det, (Matrix.getElem 1 1 tm ) / det]]
                where det = Matrix.detLaplace tm 


quadMult::Matrix.Matrix(Complex GLU.GLfloat) -> Matrix.Matrix(Complex  GLU.GLfloat) -> 
          Matrix.Matrix(Complex GLU.GLfloat) -> Matrix.Matrix(Complex  GLU.GLfloat) -> Matrix.Matrix(Complex  GLU.GLfloat) 
quadMult m1 m2 m3 m4 = Matrix.multStd m1 m2
                       where p1 = Matrix.multStd m1 m2
                             p2 = Matrix.multStd m3 m4

solveMarkovEquation::Complex GLU.GLfloat -> Complex GLU.GLfloat -> Complex GLU.GLfloat
solveMarkovEquation ta tb = if (imagPart $ b) == 0 then
                                (-b - sqrt(det)) / 2
                            else (-b + sqrt(det)) / 2
                            where b = -ta * tb
                                  c = ta * ta + tb * tb
                                  det = b * b - 4 * c 
