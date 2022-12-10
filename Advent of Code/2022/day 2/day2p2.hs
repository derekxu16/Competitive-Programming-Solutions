import qualified Data.List (lines)

main :: IO ()
main =
  interact
    ( \full_input ->
        let lines = Data.List.lines full_input
         in show
              ( foldr
                  ( \line accumulator ->
                      let [them, outcome] = words line
                       in let score = case outcome of
                                "X" ->
                                  case them of
                                    "A" -> 3
                                    "B" -> 1
                                    "C" -> 2
                                    _ -> error "Unreachable"
                                "Y" ->
                                  3 + case them of
                                    "A" -> 1
                                    "B" -> 2
                                    "C" -> 3
                                    _ -> error "Unreachable"
                                "Z" ->
                                  6 + case them of
                                    "A" -> 2
                                    "B" -> 3
                                    "C" -> 1
                                    _ -> error "Unreachable"
                                _ -> error "Unreachable"
                           in score + accumulator
                  )
                  0
                  lines
              )
              ++ "\n"
    )
