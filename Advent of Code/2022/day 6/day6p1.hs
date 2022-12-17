import qualified Data.Set (fromList, size)

solve :: String -> Int -> Int
solve s answer =
  let prefix = take 4 s
   in if Data.Set.size (Data.Set.fromList prefix) == 4
        then answer
        else
          let head : rest = s
           in solve rest (answer + 1)

main :: IO ()
main =
  interact
    ( \full_input ->
        show (solve full_input 4)
          ++ "\n"
    )
