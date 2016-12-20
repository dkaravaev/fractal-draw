module Paths_FractalGraph (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch


version :: Version
version = Version {versionBranch = [0,1,0,0], versionTags = []}
bindir, libdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/kartesius/.cabal/bin"
libdir     = "/home/kartesius/.cabal/lib/x86_64-linux-ghc-7.6.3/FractalGraph-0.1.0.0"
datadir    = "/home/kartesius/.cabal/share/x86_64-linux-ghc-7.6.3/FractalGraph-0.1.0.0"
libexecdir = "/home/kartesius/.cabal/libexec"
sysconfdir = "/home/kartesius/.cabal/etc"

getBinDir, getLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "FractalGraph_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "FractalGraph_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "FractalGraph_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "FractalGraph_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "FractalGraph_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
