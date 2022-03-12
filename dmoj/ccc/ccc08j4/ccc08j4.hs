data Expression
  = Add Expression Expression
  | Sub Expression Expression
  | Num String

instance (Show Expression) where
  show (Add lhs rhs) = show lhs ++ " " ++ show rhs ++ " +"
  show (Sub lhs rhs) = show lhs ++ " " ++ show rhs ++ " -"
  show (Num s) = s

parseExpression :: [String] -> (Expression, [String])
parseExpression terms =
  case terms of
    [] -> error "Unreachable"
    (token : rest) ->
      if token == "+" || token == "-"
        then
          let constructor = if token == "+" then Add else Sub
           in let (lhs_node, lhs_tokens) = parseExpression rest
               in let (rhs_node, rhs_tokens) = parseExpression lhs_tokens
                   in (constructor lhs_node rhs_node, rhs_tokens)
        else (Num token, rest)

solve :: String -> String
solve line =
  let terms = words line
   in let _ = print terms
       in ( case terms of
              ["0"] -> ""
              terms ->
                let (expression, _) = parseExpression terms
                 in show expression
          )

main :: IO ()
main =
  interact
    ( \full_input ->
        let lines_list = lines full_input
         in (unlines (map solve lines_list) ++ "\n")
    )
