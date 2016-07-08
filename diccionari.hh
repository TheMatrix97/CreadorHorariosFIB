#ifndef _diccionari_HH_
#define _diccionari_HH_

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct horari{
	string dia;
	int h_inici;
	int h_fi;
};


class diccionari{
	public:
		diccionari();
		void escriure_dades();
		void llegir(const vector<string> &data);
		void consulta(string assig, vector<int> grup, vector<horari> &aux);
		void escriure();
			
	private:
		map<string, map<int,vector<horari> > > contenidor;
		
		
};
#endif
