#include "diccionari.hh"
#include "mihorario.hh"
using namespace std;
struct error{
	bool validesa; //if true hi ha error
	string dia; //dia on es produeix l'error //on hi ha solapament
};

void mostrar_assigs_disp(){
	ifstream file("data/data.txt");
	string line;
	getline(file,line);
	istringstream iss(line);
	string aux;
	while(iss >> aux){
		cout << aux << ' ' << endl;
	}
}
string assig_grup(string assig, int num_grup){
	return assig + std::to_string(num_grup);
}
string crea_franja(int h_in, int h_fi){
	string aux = std::to_string(h_in);
	string aux2 = std::to_string(h_fi);
	return aux + '-' + aux2;
}

error op1(const vector<string> &vec, diccionari &a){
	error ret;
	ret.validesa = false;
	mihorario taula;
	vector<horari> aux2;
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << ": ";
		vector<int> aux_i(2);
		cout << "works" << vec[i] << endl;
		for(int j = 0; j < 2; j++) cin >> aux_i[j];
		a.consulta(vec[i], aux_i, aux2);
	}
	for(int i = 0; i < aux2.size(); i++) cout << aux2[i].dia << ' ' << aux2[i].h_inici  << ' ' << aux2[i].h_fi << endl;
	bool ok = true;
	string aux_dia;
	for(int i = 0; i < aux2.size() and ok; i++){
		string franja = crea_franja(aux2[i].h_inici, aux2[i].h_fi);
		ok = taula.insert_nuevo_evento(aux2[i].dia, franja);
		if(not ok){
			ret.validesa = true;
			ret.dia = aux2[i].dia;
		}
			
	}
	return ret;

}

		

void op2(){
}

int menu(){
	cout << "1.Comprobar solapamientos de assignaturas insertando el num de grupo" << endl;
	cout << "2.Buscar horarios possibles entre unos grupos" << endl;
	cout << "Selecciona un num: ";
	int op;
	bool valid = false;
	while(not valid and cin >> op){
		if(op == 1 or op == 2) valid = true;
	}
	cout << endl;
	return op;
}

int main(){
	diccionari test;
	cout << "WELCOME!" << endl;
	mostrar_assigs_disp();
	
	cout << "Cuantas assignaturas vas a matricular?";
	int n;
	cin >> n;
	cout << endl;
	vector<string> vec(n);
	vector<string> vec2(n);
	cout << "Que assignaturas vas a matricular? (EN MAYUS)" << endl;
	for(int i = 0; i < n; i++){
		string aux;
		cin >> aux;
		vec[i] = aux + ".txt";
		vec2[i] = aux;
	}
	test.llegir(vec);
	cout << "Estos son los grupos almacenados en data: " << endl;
	test.escriure_dades();
	cout << "------" << endl;
	int op = menu();
	if(op == 1){
		error ret;
		ret = op1(vec2, test);
		if(ret.validesa){
			cout << "hi ha un solapament al dia " << ret.dia << endl;
		}else cout << "no hi ha cap solapament" << endl;
	}
	else op2();
	
}
