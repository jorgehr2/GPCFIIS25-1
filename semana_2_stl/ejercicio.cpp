#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
typedef long double ld;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 5, MX2 = 3e5 + 2;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

int main() {
    inic;
    inic2;
    string s;
    getline(cin, s);
    s += ' ';
    map<string, ll> ma;
    // hola    mundo   hola
    string cadena = "";
    ll mayor = 0;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (cadena.size() > 0) {
                ma[cadena]++;
                mayor = max(mayor, ma[cadena]);
                cadena = "";
            }
        } else {
            cadena += s[i];
        }
    }
    cout << mayor << endl;
    return 0;
}