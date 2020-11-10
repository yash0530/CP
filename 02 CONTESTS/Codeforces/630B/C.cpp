#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

void solve() {
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	int count = 0;
	int x = n / k;
	int low = 0, high = k - 1;
	while (low <= high) {
		vector<int> freq(26);
		for (int i = low; i < n; i += k) {
			freq[s[i] - 'a']++;
		}
		for (int i = high; i < n; i += k) {
			freq[s[i] - 'a']++;
		}
		int m = *max_element(freq.begin(), freq.end());
		if (low == high) {
			count += ((x * 2) - m) / 2;	
		} else {
			count += ((x * 2) - m);
		}
		
		low++; high--;
	}
	cout << count << endl;
}

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}