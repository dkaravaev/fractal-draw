{-# LANGUAGE DoAndIfThenElse #-} 
module FractalDFS where 

import Util
import FractalRecipe

import GHC.Float
import qualified Graphics.UI.GLUT as GLU
import Data.Complex
import qualified Data.Matrix as Matrix
import System.IO.Unsafe
import Data.Array


createCom::Int -> Array Int (Matrix.Matrix(Complex GLU.GLfloat)) 
createCom i 
    | i == 0 = listArray (0, 2) [quadMult g1 g2 g3 g0, 
                g0,
                quadMult g3 g2 g1 g0]
    | i == 1 = listArray (0, 2) [quadMult g2 g3 g0 g1, 
                g1,
                quadMult g0 g3 g2 g1]
    | i == 2 = listArray (0, 2) [quadMult g3 g0 g1 g2, 
                g2,
                quadMult g1 g0 g3 2]
    | i == 3 = listArray (0, 2) [quadMult g0 g1 g2 g3, 
                g1,
                quadMult g2 g1 g0 g3]
    | otherwise = listArray (0, 2) []
    where groups = abTrans (1.91 :+ 0.05) (1.91 :+ 0.05)
          g0 = groups ! 0
          g1 = groups ! 1
          g2 = groups ! 2
          g3 = groups ! 3 
          

completeRepts::Array Int(Array Int (Matrix.Matrix(Complex GLU.GLfloat)))
completeRepts = listArray (0, 3) [createCom k | k <- [0 .. 3]]

getTrans::Int -> Int -> Matrix.Matrix(Complex GLU.GLfloat)
getTrans g v = rep ! v
            where repts = completeRepts
                  rep = repts ! g

genFp::Int -> Array Int (Complex GLU.GLfloat) 
genFp g = listArray (0, 2) [fixedPoint $ getTrans g v | v <- [0 .. 2]]

fixedPoints::Array Int(Array Int (Complex GLU.GLfloat))
fixedPoints = listArray (0, 3) [genFp g | g <- [0..3]]


getFp::Int -> Int -> Complex GLU.GLfloat
getFp i j = elem
            where conFp = fixedPoints ! i
                  elem = conFp ! j

exploreTree::Matrix.Matrix(Complex GLU.GLfloat) -> Array Int (Matrix.Matrix(Complex GLU.GLfloat)) -> Int -> [[Complex GLU.GLfloat]]
exploreTree x gens level = do 
                    lev <- [level - 1 .. level + 1] 
                    let index = (mod lev 4) 
                        right = gens ! index
                        y = Matrix.multStd x right
                        z0 = mobiusOnPoint y (getFp index 0)
                        z1 = mobiusOnPoint y (getFp index 1)
                        z2 = mobiusOnPoint y (getFp index 2)
                        dz0 = magnitude(z1 - z0)
                        dz1 = magnitude(z2 - z1)
                        epsilon = 0.1

                    if dz0 <= epsilon &&  dz1 <= epsilon then
                        return [z0, z1, z2]
                    else 
                        exploreTree y gens lev  
                                  
renderFractal::[Complex GLU.GLfloat]
renderFractal =  limitSet 
                where limitSet = concat $ concat $ [exploreTree (gens ! k) gens k | k <- [0 .. 3]]
                      gens = abTrans (1.91 :+ 0.05)  (1.91 :+ 0.05)


