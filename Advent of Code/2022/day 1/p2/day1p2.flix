use Console.readLine

def solve(elves: List[List[Int32]]): Unit \ IO = 
  match readLine() {
    case Err(_) => match List.reverse(List.sort(List.map(List.sum, elves))) {
      case Cons(first, Cons(second, Cons(third, _))) => {
        println(first + second + third)
      },
      case _ => unreachable!()
    },
    case Ok(line) => {
      if (line == "") {
        solve(Cons(Nil, elves)) 
      } else {
        let line_as_int32 = match Int32.fromString(line) {
          case Some(line_as_int32) => line_as_int32,
          case None() => unreachable!()
        };
        match elves {
          case Cons(head, rest) => solve(Cons(Cons(line_as_int32 , head), rest)),
          case Nil => unreachable!()
        }
      }
    }
  }

def main(): Unit \ IO =
  solve(Cons(Nil, Nil))
