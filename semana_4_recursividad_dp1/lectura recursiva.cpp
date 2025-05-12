#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

Long A[10];

void leer_ordenado(Long pos_ac, Long lim){
	if(pos_ac == lim){
		return;
	}
	cin >> A[pos_ac];
	leer_ordenado(pos_ac+1, lim);
	cout << "-> lee " << A[pos_ac] << endl;
	return;
}

void leer(Long pos_ac){
	if(pos_ac == -1){
		return;
	}
	cin >> A[pos_ac];
	leer(pos_ac-1);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// A[5] = 1 2 3 4 5
	
	Long n;
	cin >> n;
	/*for(Long i = 0; i < n; i++){
		cin >> A[i];
	}*/
	
	//leer_ordenado(0,n);
	
	leer(n-1);
	return 0;
}



