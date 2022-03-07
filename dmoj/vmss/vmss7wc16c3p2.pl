:- assertz(edge(1, 1)).

main :- read_line_to_string(user_input, Line), 
        split_string(Line, " ", "", Args),
        [_, M_, A_ ,B_] = Args,
        number_string(M, M_), 
        number_string(A, A_), 
        number_string(B, B_), 
        readEdges(M),
        empty_nb_set(Visited),
        (connected(A, B, Visited) -> write("GO SHAHIR!\n") ; write("NO SHAHIR!\n")).

readEdges(0) :- !.
readEdges(I) :- read_line_to_string(user_input, Line), 
                split_string(Line, " ", "", Edge),
                [X_, Y_] = Edge,
                number_string(X, X_),
                number_string(Y, Y_),
                assertz(edge(X, Y)),
                assertz(edge(Y, X)),
                NextI is I-1,
                readEdges(NextI).

connected(U, V, _) :- edge(U, V).
connected(U, V, Visited) :- not(add_nb_set(number_string(U), Visited, false)),
                            edge(U, Z),
                            add_nb_set(number_string(U), Visited),
                            connected(Z, V, Visited).

:- initialization main, halt.
