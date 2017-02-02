OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: test.o diccionari.o mihorario.o comparador.o
	g++ -o program.exe test.o diccionari.o mihorario.o comparador.o $(OPTIONS)
	rm *.gch
test.o: test.cc
	g++ -c test.cc $(OPTIONS)
diccionari.o: diccionari.cc
	g++ -c diccionari.cc diccionari.hh $(OPTIONS)
mihorario.o: mihorario.cc
	g++ -c mihorario.cc mihorario.hh $(OPTIONS)
comparador.o: comparador.cc
	g++ -c comparador.cc comparador.hh $(OPTIONS)
	
clean:
	rm *.o
	rm *.exe
	
	
