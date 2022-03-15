import Data.Array (array, (!))
import Text.Printf (printf)

main :: IO ()
main =
  getLine >>= \line ->
    let n = read line
     in getLine >>= \line ->
          let heights = array (0, n) (zip [0 ..] ((map read . words) line :: [Double]))
           in getLine >>= \line ->
                let widths = array (0, n - 1) (zip [0 ..] ((map read . words) line :: [Double]))
                 in let ans =
                          map
                            ( \i ->
                                let height_l = heights ! i
                                 in let height_r = heights ! (i + 1)
                                     in let width = widths ! i
                                         in let shorter = min height_l height_r
                                             in let taller = max height_l height_r
                                                 in (shorter * width)
                                                      + (width * (taller - shorter) / 2.0)
                            )
                            (take n [0 ..])
                     in printf "%.6f\n" (sum ans)
