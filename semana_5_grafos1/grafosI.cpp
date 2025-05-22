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
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

ll getBit(ll x, ll i) {
    return (x >> i) & 1LL;
}
vector<pair<ll, ll>> adj[MX];
bool usado[MX];
ll padre[MX], profundidad[MX], hijos[MX], tiempo_entrada[MX], tiempo_salida[MX], cont = 0;
ll suma_padre[MX];
void dfs(ll nodoAct, ll pap, ll prof) {
    usado[nodoAct] = true;
    padre[nodoAct] = pap;
    profundidad[nodoAct] = prof;
    hijos[nodoAct] = 1;
    cont++;
    tiempo_entrada[nodoAct] = cont;
    for (ll i = 0; i < adj[nodoAct].size(); i++) {
        if (usado[adj[nodoAct][i].first] == false) {
            dfs(adj[nodoAct][i].first, nodoAct, prof + 1);
            suma_padre[adj[nodoAct][i].first] = adj[nodoAct][i].second;
            hijos[nodoAct] += hijos[adj[nodoAct][i].first];
        }
    }
    cont++;
    tiempo_salida[nodoAct] = cont;
}

ll ancestros[MX][20], sumas[MX][20];
void calcular(ll nodos) {
    Rep1(i, nodos) {
        ancestros[i][0] = padre[i];
        sumas[i][0] = suma_padre[i];
    }
    Rep1(i, 20) {
        Rep1(j, nodos) {
            ancestros[j][i] = ancestros[ancestros[j][i - 1]][i - 1];
            sumas[j][i] = sumas[j][i - 1] + sumas[ancestros[j][i - 1]][i - 1];
        }
    }
}

bool esAncestro(ll primer, ll segundo) { // si es ancestro el nodo "primer" del nodo "segundo"
    return tiempo_entrada[primer] <= tiempo_entrada[segundo] &&
           tiempo_salida[primer] >= tiempo_salida[segundo];
}

ll lca(ll primer, ll segundo) {
    if (esAncestro(primer, segundo)) {
        return primer;
    }
    for (ll i = 20; i >= 0; i--) {
        if (!esAncestro(ancestros[primer][i], segundo)) {
            primer = ancestros[primer][i];
        }
    }
    return padre[primer];
}

int main() {
    inic;
    inic2;
    ll nodos, aristas;
    cin >> nodos;
    aristas = nodos - 1;
    while (aristas--) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    dfs(4, 4, 1);
    Rep1(i, nodos) {
        cout << "Para i: " << i << " " << profundidad[i] << endl;
    }
    return 0;
}
