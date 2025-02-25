// Examples of Using the C++ Template Macros and Functions
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define each(x, v) for (auto& x : v)

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;

// Example of using macros
void macro_examples() {
    vi v = {5, 3, 1, 4, 2};
    sort(all(v)); // Sort ascending
    each(x, v) cout << x << " "; // Iterate over vector and print
    cout << "\n";
    
    sort(rall(v)); // Sort descending
    each(x, v) cout << x << " ";
    cout << "\n";
}

// Example of modular arithmetic
ll mod_add(ll a, ll b, ll m = 1e9 + 7) {
    return ((a % m) + (b % m)) % m;
}
ll mod_mul(ll a, ll b, ll m = 1e9 + 7) {
    return ((a % m) * (b % m)) % m;
}
ll mod_pow(ll base, ll exp, ll m = 1e9 + 7) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = mod_mul(res, base, m);
        base = mod_mul(base, base, m);
        exp >>= 1;
    }
    return res;
}
void modular_examples() {
    cout << mod_add(3, 5) << "\n"; // Output: 8
    cout << mod_mul(3, 5) << "\n"; // Output: 15
    cout << mod_pow(2, 10) << "\n"; // Output: 1024
}

// Example of using pair and vector<pair>
void pair_examples() {
    pi p = mp(10, 20);
    cout << "First: " << p.f << ", Second: " << p.s << "\n";
    
    vpi vec;
    vec.pb(mp(1, 2));
    vec.pb(mp(3, 4));
    each(x, vec) cout << x.f << ", " << x.s << "\n";
}

int main() {
    macro_examples();
    modular_examples();
    pair_examples();
    return 0;
}

