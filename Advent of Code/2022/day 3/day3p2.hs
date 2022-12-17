import qualified Data.Char (ord)
import qualified Data.List (intersect, lines)

solve lines = case lines of
  [] -> 0
  (first : (second : (third : rest))) ->
    let common = head (Data.List.intersect (Data.List.intersect first second) third)
     in ( if 'a' <= common && common <= 'z'
            then Data.Char.ord common - Data.Char.ord 'a' + 1
            else Data.Char.ord common - Data.Char.ord 'A' + 27
        )
          + solve rest
  _ -> error "Unreachable!"

main :: IO ()
main =
  interact
    ( \full_input ->
        let lines = Data.List.lines full_input
         in show (solve lines) ++ "\n"
    )
