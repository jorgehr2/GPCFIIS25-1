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

int main() {
    deque<ll> dq;
    deque<ll>::iterator it3 = dq.begin();
    dq.push_back(30);
    dq.push_front(10);
    dq.front();
    dq.back();
    cout << dq[0] << endl;
    dq.erase(it3);
    dq.pop_back();

    stack<ll> st;
    stack<pair<ll, ll>> st2;
    st2.push({20, 30});
    st2.push({30, 20});
    st.push(30);
    st.push(10);
    st.push(50);
    cout << st.top() << endl;
    st.pop();
    queue<ll> qq;
    qq.push(30);
    cout << qq.front() << endl;
    qq.pop();
    priority_queue<ll> pq;
    pq.push(20);
    pq.push(30);
    pq.push(10);
    cout << pq.top() << endl;
    pq.pop();

    return 0;
}