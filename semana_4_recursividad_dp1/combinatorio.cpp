#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i , n) for(Long i = 0; i < (Long)n ; i++)
#define pb push_back
 
using namespace std;
 
typedef long long Long;

const Long MX = 1e3;
Long dp[MX][MX];
bool used[MX][MX];

const Long MOD = 1e9 + 7;

Long comb(Long n, Long k){
	if(k == 0){
		return 1;
	}	
	if(n == k) {
		return 1;
	}
	
	if(used[n][k]){
		return dp[n][k];
	}
	used[n][k] = true;
	return dp[n][k] = (comb(n - 1 , k - 1) + comb(n - 1 , k) ) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cout << comb(7 , 2) << endl;
	
	return 0;
}
