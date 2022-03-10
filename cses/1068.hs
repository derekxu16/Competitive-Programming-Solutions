import Data.List

weird :: Int -> [Int]
weird n
  | n == 1 = [1]
  | even n = n : weird (div n 2)
  | otherwise = n : weird (3 * n + 1)

main :: IO ()
main =
  getLine >>= \line ->
    let n = read line
     in putStrLn (unwords (map show (weird n)))
