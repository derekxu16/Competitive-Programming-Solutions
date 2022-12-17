import qualified Data.Char (ord)
import qualified Data.List (intersect, length, lines, sort)

main :: IO ()
main =
  interact
    ( \full_input ->
        let lines = Data.List.lines full_input
         in show
              ( foldr
                  ( \line accumulator ->
                      let line_length = Data.List.length line
                       in let (first_half, second_half) = splitAt (div line_length 2) line
                           in let common = head (Data.List.intersect first_half second_half)
                               in accumulator
                                    + if 'a' <= common && common <= 'z'
                                      then Data.Char.ord common - Data.Char.ord 'a' + 1
                                      else Data.Char.ord common - Data.Char.ord 'A' + 27
                  )
                  0
                  lines
              )
              ++ "\n"
    )
