#include <iostream>
#include <map>
#include <fstream>
struct horari{
	string dia;
	int h_inici;
	int h_fi;
};


class diccionari{
	public:
		diccionari();
		void llegir(const vector<string> &data);
		horari consulta(string assig, int grup);
		void escriure();
		
		
	private:
		map<string, map<int,vector<horari> > > contenidor;
		
		
};
