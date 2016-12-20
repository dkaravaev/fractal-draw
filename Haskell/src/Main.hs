import FractalDFS  
import Util
import FractalRecipe

import GHC.Float
import qualified Graphics.UI.GLUT as GLU
import Data.Complex
import qualified Data.Matrix as Matrix
import Data.Array
import System.Time

main :: IO ()
main = do
  GLU.initialWindowSize GLU.$= GLU.Size 1000 1000
  (_progName, _args) <- GLU.getArgsAndInitialize
  _window <- GLU.createWindow "Fractal Render 1.0"
  GLU.clearColor GLU.$= GLU.Color4 1 1 1 1
  GLU.displayCallback GLU.$= display
  GLU.mainLoop
  {-print $ z0
  where ta = 1.91 :+ 0.05
        tb = 1.91 :+ 0.05
        tab = solveMarkovEquation ta tb
        z0 = calcz0 ta tb tab-}

display :: GLU.DisplayCallback
display = do 
  GLU.clear [GLU.ColorBuffer]
  color3f 0 0 0
  GLU.renderPrimitive GLU.LineStrip $
         mapM_ (\compl -> GLU.vertex $ GLU.Vertex2 (realPart compl) (imagPart compl)) renderFractal 
  GLU.flush
  where color3f r g b = GLU.color $ GLU.Color3 r g (b :: GLU.GLfloat)
  {-GLU.renderPrimitive GLU.LineStrip $
         mapM_ (\branch -> 
                            mapM_ (\subbranch ->
                                                    mapM_ (\compl -> GLU.vertex $ GLU.Vertex2 (realPart compl) (imagPart compl)) subbranch) branch) renderFractal-}
