#include "mihorario.hh"
using namespace std;


mihorario::mihorario(){ //inicializamos todo a no valido
	string dias[5] = {"dl","dm","dc","dj","dv"};
	int hora_start = 8;
	int hora_fin = 21;	
	for(int i = 0; i < 5; i++){
		map<string, bool> aux;
		for(int j = hora_start; j < hora_fin; j++){
			string ini = std::to_string(j);
			string fin = std::to_string(j + 1);
			string res = ini + '-' + fin;
			aux.insert(make_pair(res,false));
		}
		table.insert(make_pair(dias[i],aux));
	}
}

bool mihorario::insert_nuevo_evento(string dia, string franja_h){
	map<string, map<string, bool> >::iterator it;
	map<string, bool>::iterator it2;
	it = table.find(dia);
	if(it != table.end()){
		it2 = it->second.find(franja_h);
		if(it2 != it->second.end() and not it2->second){
			it2->second = true;
			return true;
		}
		else return false;
	}else return false;
}



