#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

void solve() {
    int n; cin >> n;
    vector<int> arr(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    

}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}