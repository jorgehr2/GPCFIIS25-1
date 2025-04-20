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

struct {
    string nombre, apellido;
    ll edad;
} jorge, juan;

vector<int> vec(20, 30);
int main() {
    inic;
    inic2;
    jorge.nombre = "Jorge";
    vec.push_back(2); // 21 elementos
    cout << vec[0] << " 1: " << vec[1] << " 2: " << vec[2] << endl;
    vec[5] = 10;
    vec.end();
    vector<int> vec2;
    vec2.push_back(10);
    vector<int>::iterator it = vec2.begin();
    ll primer = vec2[0];
    while (it != vec2.end()) {
        cout << (*it) << endl;
        it++;
    }
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << endl;
    }
    lower_bound(vec.begin(), vec.end(), 20);
    pair<string, ll> par1;
    vector<pair<ll, ll>> vpa;
    vector<set<ll>> vse;
    vpa.push_back({20, 30});
    vpa.push_back({-20, 100});
    cout << vpa[1].first << " 2do: " << vpa[1].second;
    set<ll> se = {10, 20};
    vse.push_back(se);

    // par1 = {"20", 30};
    // tupla1 = {20, 30, 100};
    // cout<<tupla1<<endl;
    // set<int> se;
    // se.insert(20);
    // se.insert(30);
    // se.insert(10);
    // se.insert(25);
    // set<int>::iterator it = se.begin();
    // cout << *it << endl;
    // for (set<int>::iterator it = se.begin(); it != se.end(); it++) {
    //     cout << *(it) << endl;
    // }
    // cout << "Hola Mundo" << '\n';
    // int d, e, f;
    // ll a, b, c;
    // cin >> a;
    // Rep1(i, a) {
    //     cout << a * 10 << '\n';
    // }
    // bool(10);
    // cout << 20 / 2 + bool(20 % 2) << '\n';
    char aa = 'a';
    ll d = aa - '0';
    for (char i = 'a'; i <= 'z'; i++) {
        cout << i << " caracter" << endl;
    }
    cout << d << '\n';
    return 0;
}