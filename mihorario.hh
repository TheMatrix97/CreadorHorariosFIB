#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


class mihorario{
	public:
		mihorario();
		bool insert_nuevo_evento(string dia, string franja_h); //si ya hay un elemento en la franja devuelve false
		
	private:
		map<string, map<string, bool> > table; //por dias y cada dia por intervalor de hora e incluye quien ocupa esa hora
		
};
