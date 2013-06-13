prog7: prog7.o cmerge.o cheap.o cexception.o
	g++ -o prog7 prog7.o cmerge.o cheap.o cexception.o

prog7.o: prog7.cpp cmerge.h cheap.h cexception.h
	g++ -c prog7.cpp

cmerge.o: cmerge.cpp cmerge.h
	g++ -c cmerge.cpp

cheap.o: cheap.cpp cheap.h
	g++ -c cheap.cpp

cexception.o: cexception.cpp cexception.h
	g++ -c cexception.cpp
