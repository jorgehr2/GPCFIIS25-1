#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

ull getBit(ull x, ull i) { // int
    return (x >> i) & 1;
}
struct datos {
    ll edad;
    string nombre, apellidos;
};

bool cmp(const datos &a, const datos &b) { // De menor a mayor
    if (a.edad != b.edad) return a.edad < b.edad;
    if (a.nombre != b.nombre) return a.nombre < b.nombre;
    return a.apellidos < b.apellidos;
}

map<string, ll> prioridad;
bool cmp2(string a, string b) {
    return prioridad[a] < prioridad[b];
}

int main() {
    vector<datos> vec;
    vec.push_back({20, "Jorge", "Huaman"});
    vec.push_back({20, "Miguel", "Hernandez"});
    vec.push_back({20, "Miguel", "Gutierrez"});
    vec.push_back({10, "Miguel", "Gutierrez"});
    sort(vec.begin(), vec.end(), cmp);
    for (ll i = 0; i < vec.size(); i++) {
        cout << "Edad: " << vec[i].edad << " Nombre " << vec[i].nombre << " Apellidos "
             << vec[i].apellidos << endl;
    }

    vector<string> vec2 = {"banana", "apple", "cherry", "date"};
    vector<string> orden = {"cherry", "banana", "apple", "date"};

    for (ll i = 0; i < orden.size(); i++) {
        prioridad[orden[i]] = i;
    }

    sort(vec2.begin(), vec2.end(), cmp);
    for (ll i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << endl;
    }

    return 0;
}