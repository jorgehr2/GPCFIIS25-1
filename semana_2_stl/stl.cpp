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

vector<ll> vec;

int main() {
    // VECTOR
    vec.push_back(30);
    vec.push_back(20);
    vec.push_back(10);
    cout << vec[2] << endl;
    for (ll i = 0; i < vec.size(); i++) {
        cout << vec[i] << " sgte " << endl;
    }
    vec[1] = 30;
    for (vector<ll>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *(it) << " sgte " << endl;
    }
    vector<ll>::iterator it3 = vec.begin();
    vec.erase(it3); // O(n)

    sort(vec.begin(), vec.end(), greater<ll>());
    vector<ll>::iterator it2 = lower_bound(vec.begin(), vec.end(), 30); // mayor o igual
    cout << *(it2) << endl;
    if (*(it2) == 30) { // menor o igual
        cout << 30 << endl;
    } else {
        if (it2 != vec.begin()) {
            it2--;
            cout << *it2 << endl;
        } else {
            cout << "No existe" << endl;
        }
    }

    vector<ll>::iterator it3 = upper_bound(vec.begin(), vec.end(), 30); // mayor
    cout << *(it2) << endl;
    vector<ll>::iterator it4 = vec.begin() + 5;

    // SET
    set<ll> se = {10, 20, 20, 15, 30, 11, -20};
    se.insert(36);
    for (set<ll>::iterator it = se.begin(); it != se.end(); it++) {
        cout << *(it) << endl;
    }
    se.find(30);  // O(log(n))
    se.erase(50); // O(log(n))
    set<ll>::iterator itt = se.lower_bound(25);
    se.erase(itt);                         // O(log(n))
    se.lower_bound(15);                    // O(log(n))
    lower_bound(se.begin(), se.end(), 30); // O(n)

    // MULTISET
    multiset<ll> ms = {10, 20, 20, 15, 30, 11, -20};
    for (multiset<ll>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *(it) << endl;
    }
    ms.erase(20); // O(n)
    multiset<ll>::iterator mss = ms.lower_bound(30);
    ms.erase(mss); // O(log(n))
    ms.find(50);   // O(log(n))
    // MAP
    map<ll, ll> ma;
    ma[50] = 30;            // O(log(n))
    cout << ma[10] << endl; // O(log(n))
    ma[10] = 30;
    ma[20] = -15; // O(log(n))
    for (map<ll, ll>::iterator it = ma.begin(); it != ma.end(); it++) {
        cout << (it)->first << " " << (it)->second << endl; // O(1)
    }
    cout << (ma.lower_bound(21))->second << endl; // >= mayor o igual
    cout << (ma.upper_bound(21))->second << endl; // >= mayor
    cout << ma.size() << endl;
    map<ll, vector<ll>> ma2;
    ma2[1] = {20, 30, 50, 60};
    ma2[10] = ma2[1];
    map<ll, set<ll>> ma3;
    return 0;
}