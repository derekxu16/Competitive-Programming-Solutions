import std/os/readline
import std/num/decimal

fun solve(elves: list<list<int>>) : <div, console> () {
  with handler {
    ctl throw-exn(exn) {
      println(maximum(map(elves, sum)));
    }
  }
  val line = readline();
  if line == "" then {
    solve(Cons([], elves));
  } else {
    match elves {
      Cons(head, rest) -> {
        match parse-int(line) {
          Just(line_as_int) -> solve(Cons(Cons(line_as_int, head), rest))
          Nothing -> throw("Unreachable")
        }
      }
      Nil -> throw("Unreachable")
    }
  }
}

fun main() {
  solve([[]]);
}
