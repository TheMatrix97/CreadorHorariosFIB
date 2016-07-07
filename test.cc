#include "diccionari.hh"
using namespace std;



int main(){
	diccionari test;
	cout << "num archius: " << endl;
	int n;
	cin >> n;
	vector<string> vec(n);
	for(int i = 0; i < n; i++) cin >> vec[i];
	test.llegir(vec);
	test.escriure_grups();
}
