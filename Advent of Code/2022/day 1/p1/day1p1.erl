-module(day1p1).
-export([main/0]).

solve(Elves) ->
    case io:get_line('') of
        eof ->
            io:fwrite("~B", [lists:max(lists:map(fun lists:sum/1, Elves))]);
        UnstrippedLine ->
            Line = string:trim(UnstrippedLine, trailing, "\n"),
            if
                Line == "" ->
                    solve([[] | Elves]);
                true ->
                    [Head | Rest] = Elves,
                    solve([[list_to_integer(Line) | Head] | Rest])
            end
    end.

main() ->
    solve([[]]).
