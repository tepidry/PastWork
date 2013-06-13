/*checks to see if all elements being printed are valid*/
valid(X) :- member(X,[1,2,3,4,5,6,7,8,9]), !.

empty(X) :- X = e.

valid_ele(X) :- X < 10, X > 0.

/*helper to actually print each element*/
pe(X) :- var(X), tab(1), write('_'), tab(1).
pe(X) :- valid_ele(X), tab(1), write(X), tab(1).

/*pretty prints the puzzle*/
print_puzzle([],_).
print_puzzle([A,B,C|T], X) :-
  not(0 is mod(X,4)) ,pe(A), pe(B), pe(C), write('|'), print_puzzle(T,(X+1)).
print_puzzle(Y,X) :-
  (0 is mod(X,4)), not(0 is mod(X,12)), nl, print_puzzle(Y,(X+1)).
print_puzzle(Y,X) :-
  (0 is mod(X,12)), X < 36 , nl, write('--+---+--|--+---+--|--+---+--'), nl, !, print_puzzle(Y,(X+1)).

puzz(X) :- X = [e,7,2, e,e,9, e,e,3,
9,e,e, 2,e,e, e,8,7,
e,3,e, e,7,5, 2,9,4,
6,e,5, e,2,e, e,e,e,
e,e,e, 5,e,8, e,e,e,
e,e,e, e,1,e, 9,e,6,
7,6,9, 3,8,e, e,2,e,
4,5,e, e,e,2, e,e,8,
2,e,e, 4,e,e, 6,1,e].

puzz1(X) :- X = [e,4,3,e,8,e,2,5,e,
6,e,e,e,e,e,e,e,e,
e,e,e,e,e,1,e,9,4,
9,e,e,e,e,4,e,7,e,
e,e,e,6,e,8,e,e,e,
e,1,e,2,e,e,e,e,3,
8,2,e,5,e,e,e,e,e,
e,e,e,e,e,e,e,e,5,
e,3,4,e,9,e,7,1,e].

puzz2(X) :- X = [e,e,e,8,2,3,1,9,e,
e,4,e,6,e,e,e,e,5,
e,2,e,4,e,e,8,e,e,
6,3,8,e,e,e,5,e,e,
4,e,5,2,e,8,3,e,7,
e,e,7,e,e,e,4,8,9,
e,e,4,e,e,2,e,5,e,
3,e,e,e,e,5,e,1,e,
e,6,1,3,8,7,e,e,e].

puzz3(X) :- X = [1,5,e,e,7,e,4,6,e,
e,4,e,e,e,6,e,9,e,
e,9,7,e,e,e,8,e,e,
e,9,7,e,e,e,8,e,e,
e,e,e,3,e,5,e,8,e,
e,e,1,6,9,7,2,e,e,
e,6,e,4,e,2,e,e,e,
e,e,9,e,e,e,6,4,e,
e,1,e,5,e,e,e,2,e,
e,3,6,e,4,e,e,7,1].

test(A) :- puzz(A), puzzle(A), puzz1(B), puzzle(B), puzz2(C), puzzle(C), puzz3(D), puzzle(D).

/*define puzzle here*/
puzzle(P) :- 
	nl, write('PUZZLE:'), nl, print_puzzle(P,1), nl, 
	nl,  write('SOLUTION:'), 
	nl, solutions(P, P1), !, changeBack(P1, P2), print_puzzle(P2, 1), nl.

/*finds solution*/
solutions(Z, P) :-  createVars(Z, X), 
	get_Col(X,C), 
	%get_Row(X,R1,R2,R3,R4,R5,R6,R7,R8,R9),
	get_Block(X, B), change(X,P), [R1,R2,R3,R4,R5,R6,R7,R8,R9] = P, 
	checkBlock(R1,P,C,B,1,1,1), checkBlock(R2,P,C,B,2,1,1), checkBlock(R3,P,C,B,3,1,1),
	checkBlock(R4,P,C,B,4,1,4), checkBlock(R5,P,C,B,5,1,4), checkBlock(R6,P,C,B,6,1,4),
	checkBlock(R7,P,C,B,7,1,7), checkBlock(R8,P,C,B,8,1,7), checkBlock(R9,P,C,B,9,1,7).


/*This will take all the e's and make them _ non variables*/
/*I did this to make it easy to swap in and out new attempts with member*/
createVars([],[]).
createVars([e|Xs], [_|NewT]) :- !,  createVars(Xs, NewT).
createVars([X|Xs], [X|NewT]) :- createVars(Xs, NewT).

/*change and changeBack make the list of elements into lists of lists,*/
/*and vice versa.  I did this as a more efficient way to grab col and row.*/
change(
[A1, A2, A3, B1, B2, B3, C1, C2, C3,
 A4, A5, A6, B4, B5, B6, C4, C5, C6,
 A7, A8, A9, B7, B8, B9, C7, C8, C9,
 D1, D2, D3, E1, E2, E3, F1, F2, F3,
 D4, D5, D6, E4, E5, E6, F4, F5, F6,
 D7, D8, D9, E7, E8, E9, F7, F8, F9,
 G1, G2, G3, H1, H2, H3, I1, I2, I3,
 G4, G5, G6, H4, H5, H6, I4, I5, I6,
 G7, G8, G9, H7, H8, H9, I7, I8, I9],

 [[A1, A2, A3, B1, B2, B3, C1, C2, C3],
 [A4, A5, A6, B4, B5, B6, C4, C5, C6],
 [A7, A8, A9, B7, B8, B9, C7, C8, C9],
 [D1, D2, D3, E1, E2, E3, F1, F2, F3],
 [D4, D5, D6, E4, E5, E6, F4, F5, F6],
 [D7, D8, D9, E7, E8, E9, F7, F8, F9],
 [G1, G2, G3, H1, H2, H3, I1, I2, I3],
 [G4, G5, G6, H4, H5, H6, I4, I5, I6],
 [G7, G8, G9, H7, H8, H9, I7, I8, I9]]
).

changeBack(
[[A1, A2, A3, B1, B2, B3, C1, C2, C3],
 [A4, A5, A6, B4, B5, B6, C4, C5, C6],
 [A7, A8, A9, B7, B8, B9, C7, C8, C9],
 [D1, D2, D3, E1, E2, E3, F1, F2, F3],
 [D4, D5, D6, E4, E5, E6, F4, F5, F6],
 [D7, D8, D9, E7, E8, E9, F7, F8, F9],
 [G1, G2, G3, H1, H2, H3, I1, I2, I3],
 [G4, G5, G6, H4, H5, H6, I4, I5, I6],
 [G7, G8, G9, H7, H8, H9, I7, I8, I9]],
[A1, A2, A3, B1, B2, B3, C1, C2, C3,
 A4, A5, A6, B4, B5, B6, C4, C5, C6,
 A7, A8, A9, B7, B8, B9, C7, C8, C9,
 D1, D2, D3, E1, E2, E3, F1, F2, F3,
 D4, D5, D6, E4, E5, E6, F4, F5, F6,
 D7, D8, D9, E7, E8, E9, F7, F8, F9,
 G1, G2, G3, H1, H2, H3, I1, I2, I3,
 G4, G5, G6, H4, H5, H6, I4, I5, I6,
 G7, G8, G9, H7, H8, H9, I7, I8, I9] 
).

/*This will check whether the element is a e or a valid element*/
checkBlock([],_,_,_,_,_,_).
checkBlock([X|Xs],P,C,B,RowNum,ColNum,BlockNum) :- 
	nonvar(X),
	tryNextPos(RowNum,ColNum,BlockNum,NRow,NCol,NBlock),
	member(X, [1,2,3,4,5,6,7,8,9]), 
	getEmpty(Xs,Z),
	not(member(X,Z)),
	checkBlock(Xs,P,C,B,NRow,NCol,NBlock).
checkBlock([X|Xs],P,C,B,RowNum,ColNum,BlockNum) :- 
	var(X),
	tryNextPos(RowNum, ColNum,BlockNum, NRow, NCol,NBlock),
	findEle(P,C,B,RowNum,ColNum,BlockNum,Poss),
	member(X, Poss), 
	checkBlock(Xs,P,C,B,NRow,NCol,NBlock).


tryNextPos(RowNum, ColNum, BlockNum, RowNum, NewColNum, NewBlockNum) :-
		NewColNum is ColNum + 1, ((NewColNum =:= 4, NewBlockNum is BlockNum + 1);
								 (NewColNum =:= 7, NewBlockNum is BlockNum + 1);
								 (NewColNum \=4, NewColNum \= 7, NewBlockNum is BlockNum)).

/*finds element 1 - 9 that are not in R, C, or B*/							 
findEle(R,C,B,RowNum,ColNum,BlockNum,Z) :-
	getElem(R,RowNum, Row),
	getElem(C, ColNum, Col),
	getElem(B, BlockNum, Grid),
	find_ele(Row, Col, Grid, Z). 

/*finds all elements that are in the list 1-9*/
getElem([H|T],1,Row) :- getEmpty(H,Row).
getElem([H|T], RowNum,Row) :- NewRowNum is RowNum - 1, getElem(T, NewRowNum,Row).

/*finds all the valid elements in the first list and puts them in the second list.*/ 
/*similar to member other than it checks to see if an element is valid or empty*/
getEmpty([],[]).
getEmpty([X|Xs], Ys) :- var(X), getEmpty(Xs,Ys).
getEmpty([X|Xs], [X|Ys]) :- nonvar(X), getEmpty(Xs,Ys).

/*gets all the blocks colums, and rows for the entire 9x9*/
get_Block(P,B) :- obtain_block(P,1,B1), obtain_block(P,2,B2), obtain_block(P,3,B3), 
		obtain_block(P,4,B4), obtain_block(P,5,B5), obtain_block(P,6,B6),
		obtain_block(P,7,B7), obtain_block(P,8,B8), obtain_block(P,9,B9), 
		B = [B1,B2,B3,B4,B5,B6,B7,B8,B9].

get_Col(P,C) :- obtain_col(P,1,C1), obtain_col(P,2,C2), obtain_col(P,3,C3), 
		obtain_col(P,4,C4), obtain_col(P,5,C5), obtain_col(P,6,C6),
		obtain_col(P,7,C7), obtain_col(P,8,C8), obtain_col(P,9,C9), 
		C = [C1,C2,C3,C4,C5,C6,C7,C8,C9].

get_Row(P,R1,R2,R3,R4,R5,R6,R7,R8,R9) :-  obtain_row(P, 1, R1), obtain_row(P, 2, R2), 
obtain_row(P, 3, R3), obtain_row(P, 4, R4), obtain_row(P, 5, R5), 
obtain_row(P, 6, R6), obtain_row(P, 7, R7), obtain_row(P, 8, R8), obtain_row(P, 9, R9).

/*checks to see if there is only one number 1 - 9 that aren't in row col or block*/
find_ele(Row, Col, Bl, X) :- L = [1,2,3,4,5,6,7,8,9], find(L, Row, R), find(R, Col, C), find(C, Bl, X).
find([],_,[]) :- !.
find([L|T1], Item, NewT) :- member(L, Item), find(T1, Item, NewT).
find([L|T1], Item, [L|NewT]) :- not(member(L, Item)), find(T1, Item, NewT).

/*obtains the nth block*/
obtain_block([_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_|T], Bl, X) :- Bl > 3, NewBl is (Bl - 3), obtain_block(T, NewBl, X). 
obtain_block([_,_,_|T], Bl, X) :- Bl > 1, Bl =< 3, Bnew is (Bl - 1), obtain_block(T, Bnew, X).
obtain_block([A,B,C|T], 1, [A,B,C|NewT]) :- obtain_b(T,2,NewT).
obtain_b([_,_,_,_,_,_,A,B,C|T1], Bl, [A,B,C|T3]) :- Bl > 0, Bnew is (Bl - 1), obtain_b(T1, Bnew, T3).
obtain_b(_, 0, []).

/*obtains the nth row from the puzzle*/
obtain_col([],_, []) :- !.
obtain_col([X|T], 1, [X|NewT]) :- !, obtain_col(T, 9, NewT).
obtain_col([_|T], C, Z) :- C1 is C - 1, !, obtain_col(T, C1, Z). 

/*obtains the nth row from the puzzle*/
obtain_row([_,_,_,_,_,_,_,_,_|T], R, X) :- R > 1, R1 is (R - 1), obtain_row(T, R1, X).
obtain_row([A,B,C,D,E,F,B,H,I|_], 1, X) :- R = 1, X = [A,B,C,D,E,F,B,H,I].

/*all efferent items in the list*/
alldifferent([]). 
alldifferent([X|Xs]) :- not(new_member(X,Xs)), alldifferent(Xs). 

/*just like member but excepty ignores 'e'*/
new_member(X, [X|_]) :- not(X = 'e').
new_member(X,[_|Rest]):- new_member(X,Rest).

/*helper Remove*/
remove(_, [], []).
remove(Y, [Xh|Xt], NewT) :- Y = Xh, remove(Y,Xt,NewT).
remove(Y, [Xh|Xt], [Xh|NewT]) :- not(Y = Xh), remove(Y, Xt, NewT).


