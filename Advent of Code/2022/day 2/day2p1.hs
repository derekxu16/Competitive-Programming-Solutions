import qualified Data.List (lines)

main :: IO ()
main =
  interact
    ( \full_input ->
        let lines = Data.List.lines full_input
         in show
              ( foldr
                  ( \line accumulator ->
                      let [them, you] = words line
                       in let score = case you of
                                "X" ->
                                  1 + case them of
                                    "A" -> 3
                                    "B" -> 0
                                    "C" -> 6
                                    _ -> error "Unreachable"
                                "Y" ->
                                  2 + case them of
                                    "A" -> 6
                                    "B" -> 3
                                    "C" -> 0
                                    _ -> error "Unreachable"
                                "Z" ->
                                  3 + case them of
                                    "A" -> 0
                                    "B" -> 6
                                    "C" -> 3
                                    _ -> error "Unreachable"
                                _ -> error "Unreachable"
                           in score + accumulator
                  )
                  0
                  lines
              )
              ++ "\n"
    )
