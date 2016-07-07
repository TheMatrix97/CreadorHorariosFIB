#ifndef _diccionari_HH_
#define _diccionari_HH_

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct horari{
	string dia;
	int h_inici;
	int h_fi;
};


class diccionari{
	public:
		diccionari();
		void llegir(const vector<string> &data);
		vector<horari> consulta(string assig, int grup);
		void escriure();
		void escriure_grups();
		
		
	private:
		map<string, map<int,vector<horari> > > contenidor;
		
		
};
#endif
