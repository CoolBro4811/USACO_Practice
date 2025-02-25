
//
/** TEMPLATE 2/24
 * Enhanced C++ Template
 */
#include <bits/stdc++.h>
using namespace std;

// MACROS
#define f first // Access first element of a pair
#define s second // Access second element of a pair
#define all(x) begin(x), end(x) // Use with STL algorithms like sort(all(vec))
#define rall(x) rbegin(x), rend(x) // Reverse iteration for sorting in descending order
#define sz(x) (int)(x).size() // Get size of container as int
#define pb push_back // Append element to vector
#define eb emplace_back // Efficiently construct and append to vector
#define mp make_pair // Construct pair
#define rep(i, a, b) for (int i = (a); i < (b); ++i) // Forward loop
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i) // Reverse loop
#define each(x, v) for (auto& x : v) // Iterate over elements in a container

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using vpi = vector<pi>;

// DEBUGGING TOOLS
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << endl; // Print variable name and value
#else
#define debug(x)
#endif

// CONSTANTS
constexpr bool MULTI_TEST = false;
const string FILE_IO = "";
constexpr ll INF = 1e18; // Use as a large value for comparisons
constexpr int MOD = 1e9 + 7; // Common modulus for modular arithmetic
constexpr double EPS = 1e-9; // Epsilon for floating point comparisons

// UTILITY FUNCTIONS
template <typename T> void read(T& x) { cin >> x; } // Read single input
template <typename T> void read(vector<T>& v) { each(x, v) read(x); } // Read vector
template <typename T> void print(const T& x) { cout << x << '\n'; } // Print single output
template <typename T> void print(const vector<T>& v) { each(x, v) cout << x << ' '; cout << '\n'; } // Print vector

// MODULAR ARITHMETIC
ll mod_add(ll a, ll b, ll m = MOD) { return ((a % m) + (b % m)) % m; } // Modular addition
ll mod_sub(ll a, ll b, ll m = MOD) { return ((a % m) - (b % m) + m) % m; } // Modular subtraction
ll mod_mul(ll a, ll b, ll m = MOD) { return ((a % m) * (b % m)) % m; } // Modular multiplication
ll mod_pow(ll base, ll exp, ll m = MOD) { // Modular exponentiation
    ll res = 1; 
    while (exp) {
        if (exp & 1) res = mod_mul(res, base, m);
        base = mod_mul(base, base, m);
        exp >>= 1;
    } 
    return res; 
}

// I/O SETUP
void setupIO() {
    cin.tie(0)->sync_with_stdio(0); // Fast I/O
    if (!FILE_IO.empty()) {
        freopen((FILE_IO + ".in").c_str(), "r", stdin);
        freopen((FILE_IO + ".out").c_str(), "w", stdout);
    }
}

// SOLUTION FUNCTION
void solve() {
    int n; read(n); // Read an integer
    vi arr(n); read(arr); // Read an array
    sort(all(arr)); // Sort the array in ascending order
    print(arr); // Print the sorted array
}

int main() {
    setupIO(); // Setup input and output
    if (MULTI_TEST) {
        int t; read(t); // Read number of test cases
        while (t--) solve(); // Solve each test case
    } else {
        solve(); // Solve single test case
    }
}

