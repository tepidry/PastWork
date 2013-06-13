rev([], []).
rev([H|T], P) :- rev(T,NP), append(NP, [H], P).

app([], X, X).
app([H|T], P, [H|NewT]) :- app(T, P, NewT).

leng([], 0).
leng([_|T], NL) :- leng(T, L), NL is (L + 1).

sum([X], X).
sum([X|T], S) :- sum(T, N), S is (X + N).