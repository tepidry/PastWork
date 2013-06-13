]prog5: prog5.o cbstree.o cbintree.o citem.o ckey.o cexception.o
	g++ -o prog5 prog5.o cbstree.o cbintree.o citem.o ckey.o 
cexception.o
prog5.o: prog5.cpp cbstree.h cbintree.h citem.h ckey.h cexception.h
	g++ -c prog5.cpp

cbstree.o: cbstree.cpp cbstree.h cbintree.h citem.h ckey.h cexception.h
	g++ -c cbstree.cpp

cbintree.o: cbintree.cpp cbintree.h citem.h ckey.h
	g++ -c cbintree.cpp

citem.o: citem.cpp citem.h ckey.h
	g++ -c citem.cpp

ckey.o: ckey.cpp ckey.h
	g++ -c ckey.cpp
