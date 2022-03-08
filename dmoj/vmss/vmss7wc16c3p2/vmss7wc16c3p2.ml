open Base

let buildGraph n m =
  let graph = Array.create ~len:(n + 1) [] in
  let () =
    for _ = 1 to m do
      let (u, v) = Stdlib.Scanf.scanf "%i %i\n" (fun u v -> (u, v)) in
      Array.set graph u (v :: graph.(u));
      Array.set graph v (u :: graph.(v))
    done
  in
  graph

let rec dfs graph u goal visited =
  (not visited.(u))
  && (phys_equal u goal
     ||
     let () = Array.set visited u true in
     List.fold_until ~init:false
       ~f:(fun accumulator v ->
         if accumulator then Stop true else Continue (dfs graph v goal visited))
       ~finish:Fn.id graph.(u))

let () =
  let (n, m, a, b) =
    Stdlib.Scanf.scanf "%i %i %i %i\n" (fun n m a b -> (n, m, a, b))
  in
  let graph = buildGraph n m in
  let visited = Array.create ~len:(n + 1) false in
  if dfs graph a b visited then Stdio.printf "GO SHAHIR!\n"
  else Stdio.printf "NO SHAHIR!\n"
