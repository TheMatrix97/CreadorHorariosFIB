OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x
program.exe: test.o diccionari.o mihorario.o comparador.o
	g++ -o program.exe test.o diccionari.o mihorario.o comparador.o $(OPTIONS)
	rm *.gch
test.o:
	g++ -c test.cc $(OPTIONS)
diccionari.o:
	g++ -c diccionari.cc diccionari.hh $(OPTIONS)
mihorario.o:
	g++ -c mihorario.cc mihorario.hh $(OPTIONS)
comparador.o:
	g++ -c comparador.cc comparador.hh $(OPTIONS)
	
clean:
	rm *.o
	rm *.exe
	
	
