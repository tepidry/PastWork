 solve_sudoku(Cells):-
 % Declare the 4x4 Sudoku Puzzle Board as Cells 
  % where Rows are defined by [A-D] and Columns by [1-4] 
  Cells = [A1, A2, A3, A4, A5, A6, A7, A8, A9, 
         B1, B2, B3, B4, B5, B6, B7, B8, B9, 
         C1, C2, C3, C4, C5, C6, C7, C8, C9, 
         D1, D2, D3, D4, D5, D6, D7, D8, D9, 
         E1, E2, E3, E4, E5, E6, E7, E8, E9, 
         F1, F2, F3, F4, F5, F6, F7, F8, F9, 
         G1, G2, G3, G4, G5, G6, G7, G8, G9, 
         H1, H2, H3, H4, H5, H6, H7, H8, H9, 
         I1, I2, I3, I4, I5, I6, I7, I8, I9], 

  % Define Bounds for Cell Values 
    
  Possible = [1,2,3,4,5,6,7,8,9], 
  
  % Select consistent values for first row (A1-A4) 
  
  pick_value(Possible,Possible, A1, RowA_234, Col1_BCD), 
  pick_value(RowA_234,Possible, A2, RowA__34, Col2_BCD), 
  pick_value(RowA__34,Possible, A3, RowA___4, Col3_BCD), 
  pick_value(RowA___4,Possible, A4, _RowA___, Col4_BCD), 
  pick_value(Possible,Possible, A5, RowA_234, Col1_BCD), 
  pick_value(RowA_234,Possible, A6, RowA__34, Col2_BCD), 
  pick_value(RowA__34,Possible, A7, RowA___4, Col3_BCD), 
  pick_value(RowA___4,Possible, A8, _RowA___, Col4_BCD),
  pick_value(RowA___4,Possible, A9, _RowA___, Col4_BCD),

  
  % Select consistent values for second row (B1-B4) 
    
  pick_value(Possible,Col1_BCD, B1, RowB_234, Col1__CD), not(A2=B1), 
  pick_value(RowB_234,Col2_BCD, B2, RowB__34, Col2__CD), not(A1=B2), 
  pick_value(RowB__34,Col3_BCD, B3, RowB___4, Col3__CD), not(A4=B3), 
  pick_value(RowB___4,Col4_BCD, B4, _RowB___, Col4__CD), not(A3=B4), 
  pick_value(Possible,Col1_BCD, B5, RowB_234, Col1__CD), not(A6=B5), 
  pick_value(RowB_234,Col2_BCD, B6, RowB__34, Col2__CD), not(A5=B6), 
  pick_value(RowB__34,Col3_BCD, B7, RowB___4, Col3__CD), not(A8=B7), 
  pick_value(RowB___4,Col4_BCD, B8, _RowB___, Col4__CD), not(A7=B8), 
  pick_value(RowB___4,Col4_BCD, B9, _RowB___, Col4__CD), not(A9=B9), 

  % Select consistent values for third row (C1-C4) 
    
  pick_value(Possible,Col1__CD, C1, RowC_234, Col1___D), 
  pick_value(RowC_234,Col2__CD, C2, RowC__34, Col2___D), 
  pick_value(RowC__34,Col3__CD, C3, RowC___4, Col3___D), 
  pick_value(RowC___4,Col4__CD, C4, _RowC___, Col4___D),
  pick_value(Possible,Col1__CD, C5, RowC_234, Col1___D), 
  pick_value(RowC_234,Col2__CD, C6, RowC__34, Col2___D), 
  pick_value(RowC__34,Col3__CD, C7, RowC___4, Col3___D), 
  pick_value(RowC___4,Col4__CD, C8, _RowC___, Col4___D), 
  pick_value(RowC___4,Col4__CD, C9, _RowC___, Col4___D), 

  % Select consistent values for fourth row (D1-D4) 
    
  pick_value(Possible,Col1___D, D1, RowD_234, _), not(C2=D1), 
  pick_value(RowD_234,Col2___D, D2, RowD__34, _), not(C1=D2), 
  pick_value(RowD__34,Col3___D, D3, RowD___4, _), not(C4=D3), 
  pick_value(RowD___4,Col4___D, D4, _RowD___, _), not(C3=D4), 
  pick_value(Possible,Col1___D, D5, RowD_234, _), not(C5=D5), 
  pick_value(RowD_234,Col2___D, D6, RowD__34, _), not(C6=D6), 
  pick_value(RowD__34,Col3___D, D7, RowD___4, _), not(C8=D7), 
  pick_value(RowD___4,Col4___D, D8, _RowD___, _), not(C7=D8), 
  pick_value(Possible,Col1___D, D9, RowD_234, _), not(C9=D9), 

  true. 

%%% Pick a value Val from the set of possible RowVals and ColVals. 
%%% Reduce the possible values accordingly to RowValRest and 
%%% ColValRest. 

pick_value(RowVals,ColVals, BlockVal Value, RowValRest, ColValRest, BlockValRest) :- 
   pickValue(RowVals,Value,RowValRest), 
   pickValue(ColVals,Value,ColValRest). 
    
%%% Pick a possible value and return the remaining ones %%% 
%%% pickValue(Possible,Picked,Rest) -> Possible - Picked = Rest 

pickValue([H|Rest],H, Rest). 
pickValue([H|Tail],Picked,[H|Rest]):- pickValue(Tail,Picked,Rest).   


%%% Sudoku Test %%% 
go1(L):- 
    L = [e,7,2, e,e,9, e,e,3,
    9,e,e, 2,e,e, e,8,7,
    e,3,e, e,7,5, 2,9,4,
    6,e,5, e,2,e, e,e,e,
    e,e,e, 5,e,8, e,e,e,
    e,e,e, e,1,e, 9,e,6,
    7,6,9, 3,8,e, e,2,e,
    4,5,e, e,e,2, e,e,8,
    2,e,e, 4,e,e, 6,1,e], write(1), 
    solve_sudoku(L). 

go2(L,N):- 
   findall(L, solve_sudoku(L), ALL), 
   length(ALL,N). 
    