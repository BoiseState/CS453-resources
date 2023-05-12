-- http://stackoverflow.com/questions/14157090/has-the-control-monad-state-api-changed-recently
-- ghc -o stack stack.hs && ./stack

import Control.Monad.State

type Stack = [Int]

pop :: State Stack Int
pop = do
 x:xs <- get
 put xs
 return x

push :: Int -> State Stack ()  
push a = do
 xs <- get
 put (a:xs)
 return ()

pop1 = runState pop [1..5]
push1 = runState (push 1) [2..5]

stackManip :: State Stack Int  
stackManip = do  
 push 3  
 a <- pop  
 pop  

stackManip1 = runState stackManip [5,8,2,1]  
stackManip2 = runState stackManip [1,2,3,4]  

main = do
    print (show (fst pop1))
    print pop1
    print push1
    print stackManip1
    print stackManip2
