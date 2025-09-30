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
const ll MX = 2e5 + 5, MX2 = 1024 * 1024 + 2, MX3 = 5e2 + 2;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

vector<ll> adj[MX], cdTree[MX];
struct CentroidD {
    ll n, val_vis = 0;
    vector<ll> cparent, szt, vis;

    // CentroidD() {}
    // CentroidD(ll n) : n(n) {
    //     val_vis = 0;
    //     vis.resize(n, -1);
    //     cparent.resize(n, -1);
    //     szt.resize(n, 0);
    // }

    void init_centroid(ll n) {
        vis.resize(n + 1, -1);
        cparent.resize(n + 1, -1);
        szt.resize(n + 1, 0);
    }

    void clear(ll n) {
        vis.resize(n + 1, -1);
        cparent.resize(n + 1, -1);
        szt.resize(n + 1, 0);
        for (ll i = 0; i <= n; i++) {
            cdTree[i].clear();
        }
    }

    ll dfs(ll u, ll p) {
        szt[u] = 1;
        vis[u] = val_vis;
        for (ll v : adj[u]) {
            if (v != p && cparent[v] == -1 && vis[v] != val_vis) szt[u] += dfs(v, u);
        }
        return szt[u];
    }

    void decompotition(ll u, ll p, ll sz, ll pc) {
        for (ll v : adj[u]) {
            if (v != p && cparent[v] == -1 && (szt[v] << 1ll) > sz) {
                decompotition(v, u, sz, pc);
                return;
            }
        }
        cparent[u] = pc;

        if (pc != -2) {
            cdTree[u].push_back(pc);
            cdTree[pc].push_back(u);
        }
        for (ll v : adj[u]) {
            if (cparent[v] == -1) {
                dfs(v, -1);
                val_vis++;
                decompotition(v, -1, szt[v], u);
            }
        }
    }

    void build(ll u, ll n) {
        init_centroid(n);
        dfs(u, -1);
        val_vis++;
        decompotition(u, -1, szt[u], -2);
    }
} C;

vector<pair<ll, ll>> distancias;
bool vis_centroid[MX];
vector<vector<pair<ll, ll>>> dist_tots;
// map<ll, ll> ma;
ll ma[MX];
ll ans = 0;
vector<ll> vec;
void dfs3(ll ini, ll dist, ll pap) {
    distancias.pb({ini, dist});
    ma[dist]++;
    vec.pb(dist);
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (vis_centroid[adj[ini][i]] == false && pap != adj[ini][i]) {
            dfs3(adj[ini][i], dist + 1, ini);
        }
    }
}

void query_centroid(ll ini, ll k) {
    // for (ll i = 0; i < dist_tots.size(); i++) {
    //     dist_tots[i].clear();
    // }
    // vector<vector<pair<ll, ll>>> dist_tots;
    dist_tots.clear();
    // ma.clear();
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (vis_centroid[adj[ini][i]] == false) {
            distancias.clear();
            dfs3(adj[ini][i], 1, ini);
            dist_tots.pb(distancias);
        }
    }
    ans += 2 * ma[k];
    // cout << "El answer para distancias =k es: " << 2 * ma[k] << endl;
    for (ll i = 0; i < dist_tots.size(); i++) {
        for (ll j = 0; j < dist_tots[i].size(); j++) {
            ma[dist_tots[i][j].second]--;
        }
        for (ll j = 0; j < dist_tots[i].size(); j++) {
            ll need = k - dist_tots[i][j].second;
            if (need <= 0) {
                continue;
            }
            ans += ma[need];
        }
        for (ll j = 0; j < dist_tots[i].size(); j++) {
            ma[dist_tots[i][j].second]++;
        }
    }
}

void dfs(ll ini, ll k) {
    vis_centroid[ini] = true;
    for (ll i = 0; i < vec.size(); i++) {
        ma[vec[i]] = 0;
    }
    vec.clear();
    query_centroid(ini, k);
    for (ll i = 0; i < cdTree[ini].size(); i++) {
        if (vis_centroid[cdTree[ini][i]] == false) {
            dfs(cdTree[ini][i], k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    Rep1(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    C.build(1, n);
    ll centroid = -1;
    for (ll i = 1; i <= n; i++) {
        if (C.cparent[i] == -2) {
            centroid = i;
            break;
        }
    }
    // cout << "El centroid es: " << centroid << endl;
    dfs(centroid, k);
    cout << ans / 2 << endl;
    return 0;
}