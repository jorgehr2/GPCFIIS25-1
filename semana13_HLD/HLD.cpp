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

ll combine(ll a, ll b) {
    // return a + b;
    return max(a, b);
}

struct SegmentTree {
    ll t[2 * MX];
    ll lazy[2 * MX];
    ll n;

    void clear(ll n) {
        for (ll i = 0; i <= 2 * n; i++) {
            t[i] = 0;
            lazy[i] = 0;
        }
        this->n = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        lazy[id] = 0;
        if (tl == tr) {
            t[id] = a[tl - 1];
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    void push(ll id, ll tl, ll tr) { // O(1)
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        ll szLeft = tm - tl + 1;
        ll szRight = tr - tm;
        // Apply the lazy value of the node to the children
        // t[left] += lazy[id] * szLeft;
        t[left] += lazy[id];
        // t[right] += lazy[id] * szRight;
        t[right] += lazy[id];
        // Aggregate the lazy value
        lazy[left] += lazy[id];
        lazy[right] += lazy[id];

        // Restart the lazy value
        lazy[id] = 0;
    }

    ll query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        if (tr < l || tl > r || l > r) return 0;
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        push(id, tl, tr);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combine(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    ll query(ll l, ll r) {
        assert(n > 0);
        return query(l, r, 1, 1, n);
    }

    void update(ll l, ll r, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (l > r) return;
        if (tr < l || tl > r) return;
        if (l <= tl && tr <= r) {
            ll sz = tr - tl + 1;
            // Apply the lazy value
            // t[id] += val * sz;
            t[id] += val;
            // Aggregate the lazy value
            lazy[id] += val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            push(id, tl, tr);
            update(l, r, val, left, tl, tm);
            update(l, r, val, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void update(ll l, ll r, ll val) {
        assert(n > 0);
        update(l, r, val, 1, 1, n);
    }
} st;

struct Graph {
    vector<ll> adj[MX];
    ll parent[MX];
    ll depth[MX];
    ll heavy[MX];
    ll head[MX];
    ll pos[MX];
    ll curPos = 0;
    ll conteo = 1;
    ll posEntrada[MX], posSalida[MX];

    void clear(ll n) { // O(n)
        conteo = 1;
        for (ll i = 0; i <= n; i++) {
            adj[i].clear();
            parent[i] = -1;
            heavy[i] = -1;
            depth[i] = head[i] = pos[i] = 0;
        }
        curPos = 0;
    }

    void addEdge(ll u, ll v) { // O(1)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll dfs(ll u = 1) { // O(V + E)
        ll sz = 1;
        ll maxSize = 0;
        heavy[u] = -1;
        for (ll v : adj[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                ll szV = dfs(v);
                sz += szV;
                if (szV > maxSize) {
                    maxSize = szV;
                    heavy[u] = v;
                }
            }
        }
        return sz;
    }

    void decompose(ll u, ll h) { // O(V + E)
        posEntrada[u] = conteo;
        head[u] = h;
        pos[u] = ++curPos;
        if (heavy[u] != -1) {
            conteo++;
            decompose(heavy[u], h);
        }
        for (ll v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                conteo++;
                decompose(v, v);
            }
        }
        posSalida[u] = conteo;
    }

    void build(ll root = 1) {
        curPos = 0;
        depth[root] = 0;
        parent[root] = -1;
        dfs(root);
        decompose(root, root);
    }
    void update(ll u, ll val) {
        st.update(pos[u], pos[u], val);
    }
    void update(ll l, ll r, ll val) {
        while (head[l] != head[r]) {
            if (depth[head[l]] > depth[head[r]]) {
                swap(l, r);
            }
            st.update(pos[head[r]], pos[r], val);
            r = parent[head[r]];
        }
        if (depth[l] > depth[r]) {
            swap(l, r);
        }
        st.update(pos[l], pos[r], val);
    }
    ll query(ll u, ll v) { // O(O(|query|) log V)
        ll ans = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                swap(u, v);
            }
            ll curHeavyVal = st.query(pos[head[v]], pos[v]);
            ans = combine(ans, curHeavyVal);
            // cout << "Respuesta: " << ans << " Nodos: " << head[v] << " " << v << endl;
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        // u = heavy[u];          // when weight are on edges
        // if (u == -1) return 0; // when weight are on edges

        // last heavy path
        ll lastVal = st.query(pos[u], pos[v]);
        ans = combine(ans, lastVal);
        return ans;
    }

} G;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll nodos, aristas;
    cin >> nodos >> aristas;
    while (aristas--) {
        ll a, b;
        cin >> a >> b;
        G.addEdge(a, b);
    }
    vector<ll> vec2;
    for (ll i = 1; i <= nodos; i++) {
        vec2.pb(i * 10);
    }
    st.build(vec2); // CONSTRUYO EL SEGMENT TREE EN BASE A QUE CADA NODO TENGA COMO VALOR i*10
                    // (LINEA 244)
    G.build();      // LLENO LOS ARREGLOS NECESARIO DE HEAVY LIGHT
    for (ll i = 1; i <= nodos; i++) {
        cout << "Posicion de nodo en segment tree: " << i << " : " << G.pos[i] << endl;
    }
    for (ll i = 1; i <= nodos; i++) {
        cout << "Posicion incial en el subarbol de i: " << i << " : " << G.posEntrada[i]
             << " . Posicion final en dicho subarbol: " << G.posSalida[i] << endl;
    }
    ll a = 2, b = 5;
    cout << "La suma de valores a lo largo del camino de 2 a 5 es: " << G.query(a, b) << endl;
    return 0;
}

// 26 25
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 4 16
// 16 17
// 16 18
// 16 19
// 18 24
// 19 21
// 19 20
// 24 25
// 24 26
// 21 22
// 22 23
// 3 7
// 3 8
// 3 9
// 7 14
// 7 15
// 8 13
// 9 10
// 9 11
// 11 12