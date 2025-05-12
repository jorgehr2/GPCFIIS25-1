#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i , n) for(Long i = 0; i < (Long)n ; i++)
#define pb push_back
 
using namespace std;
 
typedef long long Long;

Long fibo[100];

const Long MOD = 1e9 + 7;

Long f(Long x) {
	if(x == 0) return 0;
	if(x == 1) return 1;
	return (f(x - 1) + f(x - 2)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cout << f(70) << endl;
	fibo[0] = 0;
	fibo[1] = 1;
	
	for(Long i = 2 ; i < 70; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2])% (MOD);
	}
	

	return 0;
}
