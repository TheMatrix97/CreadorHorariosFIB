#include "comparador.hh"
using namespace std;
void all_combinaciones_2(map<string, vector<grup> > &a, vector< map<string, grup> > &b){
	map<string, vector<grup> >::iterator it;
	map<string, vector<grup> >::iterator it2;
	it = a.begin();
	it2 = it;
	it2++;
	for(int i = 0; i < it->second.size(); i++){
		for(int j = 0; j < it2->second.size(); j++){
		//	cout << it->first << ":" << it->second[i].gen << it->second[i].lab << endl;
		//	cout << it2->first << ":" << it2->second[j].gen << it2->second[j].lab << endl;
			map<string, grup> aux;
			aux.insert(make_pair(it->first,it->second[i]));
			aux.insert(make_pair(it2->first,it2->second[j]));
			b.push_back(aux);
		}
	}
}

void all_combinaciones_3(map<string, vector<grup> > &a, vector< map<string, grup> > &b){
	map<string, vector<grup> >::iterator it;
	map<string, vector<grup> >::iterator it2;
	map<string, vector<grup> >::iterator it3;
	it = a.begin();
	it2 = it;
	it2++;
	it3 = it2;
	it3++;
	for(int i = 0; i < it->second.size(); i++){
		for(int j = 0; j < it2->second.size();j++){
			for(int k = 0; k < it3->second.size(); k++){
				map<string, grup> aux;
				aux.insert(make_pair(it->first,it->second[i]));
				aux.insert(make_pair(it2->first,it2->second[j]));
				aux.insert(make_pair(it3->first, it3->second[k]));
				b.push_back(aux);
			}
		}
	}
}

void all_combinaciones_4(map<string, vector<grup> > &a, vector< map<string, grup> > &b){
	map<string, vector<grup> >::iterator it;
	map<string, vector<grup> >::iterator it2;
	map<string, vector<grup> >::iterator it3;
	map<string, vector<grup> >::iterator it4;
	it = a.begin();
	it2 = it;
	it2++;
	it3 = it2;
	it3++;
	it4 = it3;
	it4++;
	for(int i = 0; i < it->second.size(); i++){
		for(int j = 0; j < it2->second.size();j++){
			for(int k = 0; k < it3->second.size(); k++){
				for(int s = 0; s < it4->second.size(); s++){	
					map<string, grup> aux;
					aux.insert(make_pair(it->first,it->second[i]));
					aux.insert(make_pair(it2->first,it2->second[j]));
					aux.insert(make_pair(it3->first, it3->second[k]));
					aux.insert(make_pair(it4->first, it4->second[s]));
					b.push_back(aux);
				}
			}
		}
	}
}

void all_combinaciones_5(map<string, vector<grup> > &a, vector< map<string, grup> > &b){
	map<string, vector<grup> >::iterator it;
	map<string, vector<grup> >::iterator it2;
	map<string, vector<grup> >::iterator it3;
	map<string, vector<grup> >::iterator it4;
	map<string, vector<grup> >::iterator it5;
	it = a.begin();
	it2 = it++;
	it3 = it2++;
	it4 = it3++;
	it5 = it4++;
	for(int i = 0; i < it->second.size(); i++){
		for(int j = 0; j < it2->second.size();j++){
			for(int k = 0; k < it3->second.size(); k++){
				for(int s = 0; s < it4->second.size(); s++){
					for(int f = 0; f < it5->second.size(); f++){
						map<string, grup> aux;
						aux.insert(make_pair(it->first,it->second[i]));
						aux.insert(make_pair(it2->first,it2->second[j]));
						aux.insert(make_pair(it3->first, it3->second[k]));
						aux.insert(make_pair(it4->first, it4->second[s]));
						aux.insert(make_pair(it5->first, it5->second[f]));
						b.push_back(aux);
					}
				}
			}
		}
	}
}




