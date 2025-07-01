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

ull getBit(ull x, ull i) {
    return (x >> i) & 1ULL;
}
vector<ll> adj[MX];
bool usado[MX];
ll padre[MX], distancias[MX];
void bfs(vector<ll> root) {
    queue<ll> qq;
    for (auto x : root) {
        qq.push(x);
        usado[x] = true;
        distancias[x] = 0;
    }
    while (!qq.empty()) {
        ll nodoActual = qq.front();
        qq.pop();
        for (ll i = 0; i < adj[nodoActual].size(); i++) {
            if (usado[adj[nodoActual][i]] == false) {
                usado[adj[nodoActual][i]] = true;
                padre[adj[nodoActual][i]] = nodoActual;
                distancias[adj[nodoActual][i]] = distancias[nodoActual] + 1;
                qq.push(adj[nodoActual][i]);
            }
        }
    }
}

set<pair<ll, ll>> se;
vector<pair<ll, ll>> adj2[MX];
ll distancia_dijkstra[MX];
void dijkstra(ll root, ll nodos) {
    for (ll i = 0; i <= nodos; i++) {
        distancia_dijkstra[i] = INF;
    }
    distancia_dijkstra[root] = 0;
    se.insert({0, root});
    while (!se.empty()) {
        set<pair<ll, ll>>::iterator it = se.begin();
        ll nodoActual = (*it).first;
        se.erase(it);
        for (ll i = 0; i < adj2[nodoActual].size(); i++) {
            if (distancia_dijkstra[nodoActual] + adj2[nodoActual][i].second <
                distancia_dijkstra[adj2[nodoActual][i].first]) {
                se.erase({distancia_dijkstra[adj2[nodoActual][i].first],
                          adj2[nodoActual][i].first});
                se.insert({distancia_dijkstra[nodoActual] + adj2[nodoActual][i].second,
                           adj2[nodoActual][i].first});
                distancia_dijkstra[adj2[nodoActual][i].first] =
                    distancia_dijkstra[nodoActual] + adj2[nodoActual][i].second;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    Rep1(i, m) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj2[a].pb({b, w});
        adj2[b].pb({a, w});
    }
    return 0;
}
