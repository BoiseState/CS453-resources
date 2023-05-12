-- ghc -o label label.hs && ./label

import Control.Monad.State

type Label = (Int,String)

newLabel :: Label
newLabel = (0,"")

getLabel :: State Label Int
getLabel = do
    (label,output) <- get
    put (label,output++"label"++(show label)++":\n")
    return label

incLabel :: State Label ()
incLabel = do
    (label,output) <- get
    put (label+1,output)
    return ()

doit :: State Label Int
doit = do
    getLabel
    getLabel
    incLabel ; getLabel
    incLabel ; getLabel
    incLabel ; getLabel
    incLabel ; getLabel

main = putStr (snd (snd (runState doit newLabel)))
