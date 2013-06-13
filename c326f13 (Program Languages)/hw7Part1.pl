player(1).
player(2).
rock_paper_scissors(W, scissors, paper) :- player(W).
rock_paper_scissors(W, paper, rock) :- player(W).
rock_paper_scissors(W, rock, scissors) :- player(W).


