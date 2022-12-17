import qualified Data.List (lines)

split :: Char -> String -> [String]
split c [] = []
split c s =
  let (prefix, suffix) = span (/= c) s
   in prefix : split c (drop 1 suffix)

main :: IO ()
main =
  interact
    ( \full_input ->
        let lines = Data.List.lines full_input
         in show
              ( foldr
                  ( \line accumulator ->
                      let [[a_, b_], [c_, d_]] = map (split '-') (split ',' line)
                       in let [a, b, c, d] = map (read :: String -> Int) [a_, b_, c_, d_]
                           in if a <= c && c <= b || c <= a && a <= d
                                then accumulator + 1
                                else accumulator
                  )
                  0
                  lines
              )
              ++ "\n"
    )
