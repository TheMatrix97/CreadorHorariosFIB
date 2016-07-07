#include "diccionari.hh"
using namespace std;
void diccionari::llegir(const vector<string> &data){
	map<string, map<int, vector<horari> > >::iterator it = contenidor.begin();
	for(int i = 0; i < data.size(); i++){
		string line;
		ifstream file(data[i]);
		while(getline(file,line) and line != "END"){
			string basura;
			int grup = convertir_str_int(line);
			if(grupo >= 10 and grupo <= 45){
				string line2;
				getline(file,line2) //leemos el {
				vector<horari> aux;
				while(getline(file, line2) and line2 != "}"){
					horari aux2;
					aux2.dia = line2.substr(0, 2);
					file >> aux2.h_inici >> aux2.h_fi;
					aux.push_back(aux2);
				}
				string assig = eliminar_extension(data[i]);
				it = contenidor.find(assig);
				if(it != contenidor.end()){ //si la assig existe existe
					it->second.insert(make_pair(grupo, aux));
				}else{ //si la assig no existe
					map<int, vector<horari> > map_aux;
					map_aux.insert(make_pair(grupo, aux));
					contenidor.insert(make_pair(assig, map_aux));
				}
			}else cout << "error" << endl;
			getline(file,basura); //leemos la linea en blanco de separacion
			
		}
	}
}

void diccionari::escriure(){
	map<string, map<int, vector<horari> > >::iterator it;
	map<int, vector<horari>::iterator it2;
	for(it = contenidor.begin(); it != contenidor.end(); it++){
		string a = it->first;
		cout << a << ":" << endl;
		for(it2 = it->second.begin(); it2 != it->second.end(); it2++){
			int b = it2->first;
			cout << b << " -> ";
			for(int i = 0; i < it2->second.size(); i++){
				cout << "dia " << it2->second[i].dia << "inici: " << it2->second[i].h_inici << "/ final: " << it2->second[i].h_fi << "//";
			}
			cout << endl;
		}
	}
}

	
	
horari diccionari::consulta(string assig, int grup){ //per fer
	
}
	
int convertir_str_int(const string &a){
	return std::stoi(a);
}

string eliminar_extension(string a){
	a.erase(a.end() - 3, a.end());
	return a;
}
