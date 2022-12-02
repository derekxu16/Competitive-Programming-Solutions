import Data.List (sort)
import qualified System.IO (isEOF)

solve :: [[Int]] -> IO ()
solve elves =
  System.IO.isEOF >>= \isEOF ->
    if isEOF
      then
        let first : second : third : rest = reverse (sort (map sum elves))
         in print (first + second + third)
      else
        getLine >>= \line ->
          if line == ""
            then solve ([] : elves)
            else
              let head : rest = elves
               in solve ((read line : head) : rest)

main :: IO ()
main = solve [[]]
