-- Haskell sum program

import Prelude hiding (sum)

sum :: [Int] -> Int
sum [] = 0
sum (h:t) = h + sum t

main = print (sum [5,6,1,8,3,7])
