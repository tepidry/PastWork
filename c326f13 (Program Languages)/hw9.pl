%Number 1 : minimum of three items
min3(A,B,C,X) :- minL([A,B,C], X). 

%Number 2 : minimum in a list
minL([X], X).    
minL([H|T], X) :- minL(T, Min), X is min(H, Min).

%Number 3 : sum of integers in a list
sumL([], X) :- X = 0.
sumL([H|T], X) :- sumL(T, Min), X is H + Min.

%Number 4 : the second list is a duplicated list of the first list and vice versa
dup_list([], []).
dup_list([Xh|Xt],[Xh,Xh|Yt]) :- dup_list(Xt,Yt).

%Number 5 : the list is a even list of matching pairs
dup_list([]).
dup_list([X,X|Xt]) :- even_size(Xt), dup_list(Xt).

%Number 6 : returns true if the List is a even or empty list
even_size([]).
even_size([_,_|Xt]) :- even_size(Xt).

%helper Remove
remove(_, [], []).
remove(Y, [Xh|Xt], NewT) :- Y = Xh, remove(Y,Xt,NewT).
remove(Y, [Xh|Xt], [Xh|NewT]) :- not(Y is Xh), remove(Y, Xt, NewT).

%Number 7 : returns the third list as a union of the first two lists
union_sets([Xh|Xt], Yt, [Xh|NewT]) :- remove(Xh,Xt,Xnew), remove(Xh,Yt,Ynew), union_sets(Xnew,Ynew,NewT).
union_sets([],[Zh|Zt],[Zh|Znew]) :- remove(Zh, Zt, Ztnew), union_sets([], Ztnew, Znew).
union_sets([],_,[]).

%Number 8 : reuturns in the third list a intersection of the first tow lists
intersects_sets([],_,[]).
intersects_sets([Xh|Xt],Y,[Xh|NewT]) :- member(Xh, Y), remove(Xh,Y,Ynew), intersects_sets(Xt, Ynew, NewT).
intersects_sets([Xh|Xt],Y,NewT) :- not(member(Xh,Y)), remove(Xh,Xt,NewX), intersects_sets(NewX,Y,NewT).

%Number 9 : reuturns if the two lists are of the same size
equal_sets([],[]).
equal_sets([Xh|Xt],[Xh|Yt]) :- equal_sets(Xt, Yt).

%Number 10 : returns in the second list all the subsets of the first list.
subset([], []).
subset([Xh|Xt], [Xh|Yt]):- subset(Xt, Yt).
subset([_|Xt], Yt):- subset(Xt, Yt).

