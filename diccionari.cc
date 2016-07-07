#include "diccionari.hh"
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int convertir_str_int(const string &a){
	return std::stoi(a);
}

string eliminar_extension(string a){
	a.erase(a.end() - 4, a.end());
	return a;
}
diccionari::diccionari(){
	
}

void diccionari::llegir(const vector<string> &data){
	map<string, map<int, vector<horari> > >::iterator it = contenidor.begin();
	for(int i = 0; i < data.size(); i++){
		string line;
		ifstream file(data[i]);
		while(getline(file,line) and line != "END"){
		//	cout << "he leido: " << line << endl;
			string basura;
			int grupo = convertir_str_int(line);
			if(grupo >= 10 and grupo <= 45){
				string line2;
				getline(file,line2); //leemos el {
				vector<horari> aux;
				while(getline(file, line2) and line2 != "}"){
					horari aux2;
					istringstream iss(line2);
					iss >> aux2.dia;
					iss >> aux2.h_inici;
					iss >> aux2.h_fi;
				//	cout << "dia: " << aux2.dia << endl;
				//	cout << aux2.h_inici << ' ' << aux2.h_fi << endl;
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
	map<int, vector<horari> >::iterator it2;
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

void diccionari::escriure_grups(){
	map<string, map<int, vector<horari> > >::iterator it;
	map<int, vector<horari> >::iterator it2;
	for(it = contenidor.begin(); it != contenidor.end(); it++){
		cout << it->first << ":";
		for(it2 = it->second.begin(); it2 != it->second.end(); it2++){
			cout << ' ' << it2->first;
		}
		cout << endl;
	}
}
	
	
vector<horari> diccionari::consulta(string assig, int grup){ //per fer
	vector<horari> aux;
	map<string, map<int, vector<horari> > >::iterator it;
	map<int, vector<horari> >::iterator it2;
	it = contenidor.find(assig);
	if(it != contenidor.end()){
		it2 = it->second.find(grup);
		if(it2 != it->second.end()){
			for(int i = 0; i < it2->second.size(); i++) aux.push_back(it2->second[i]);
		}
	}
	return aux;
}
