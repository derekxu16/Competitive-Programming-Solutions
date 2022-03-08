import Data.Array

type AdjacencyList = Array Int [Int]

buildGraph :: Int -> AdjacencyList -> IO AdjacencyList
buildGraph 0 graph = return graph
buildGraph i graph =
  getLine >>= \s ->
    let [u, v] = (map read . words) s
     in let updatedGraph = graph // [(u, v : (graph ! u)), (v, u : (graph ! v))]
         in buildGraph (i - 1) updatedGraph

dfs :: AdjacencyList -> Int -> Int -> Array Int Bool -> Bool
dfs graph u goal visited =
  not (visited ! u)
    && ( u == goal
           || let updatedVisited = visited // [(u, True)]
               in foldr
                    ( \v accumulator ->
                        dfs graph v goal updatedVisited || accumulator
                    )
                    False
                    (graph ! u :: [Int])
       )

main :: IO ()
main =
  getLine >>= \line ->
    let [n, m, a, b] = (map read . words) line
     in buildGraph m (array (1, n) [(i, []) | i <- [1 .. n]])
          >>= \graph ->
            if dfs graph a b (array (1, n) [(i, False) | i <- [1 .. n]])
              then putStrLn "GO SHAHIR!"
              else putStrLn "NO SHAHIR!"
