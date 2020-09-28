#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		vector<int> chunks;
		int prev = 1;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (i == 0) chunks.pb(1);
			else if (__gcd(prev, arr[i]) > 1) {
				chunks[size(chunks) - 1]++;
			} else {
				chunks.pb(1);
			}
			prev = arr[i];
		}
		if ((__gcd(arr[0], arr.back()) > 1) and size(chunks) == 1) {
			for (int i = 2; i <= n; i++) {
				cout << ((n + i - 2) / (i - 1)) << " ";
			} cout << endl;
			continue;
		}
		if (__gcd(arr[0], arr.back()) > 1) {
			chunks[0] += chunks.back();
			chunks.pop_back();
		}
		vector<int> res(n + 5);
		for (auto curr : chunks) {
			for (int i = 2; i <= curr; i++) {
				res[i] += ((curr - 1) / (i - 1));
			}
		}
		for (int i = 2; i <= n; i++) {
			cout << res[i] << " ";
		} cout << endl;
	}
	return 0;
}