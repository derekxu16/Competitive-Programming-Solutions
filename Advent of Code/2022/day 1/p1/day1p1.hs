import qualified System.IO (isEOF)

solve :: [[Int]] -> IO ()
solve elves =
  System.IO.isEOF >>= \isEOF ->
    if isEOF
      then
        print
          ( maximum
              (map sum elves)
          )
      else
        getLine >>= \line ->
          if line == ""
            then solve ([] : elves)
            else
              let head : rest = elves
               in solve ((read line : head) : rest)

main :: IO ()
main = solve [[]]
