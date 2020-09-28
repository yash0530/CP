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
		int n, q; cin >> n >> q;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if (n == 1) {
			cout << arr[0] << endl;
			continue;
		}
		vector<int> peaks;
		vector<int> val;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (arr[i] > arr[i + 1]) {
					peaks.pb(i);
				}
				if (arr[i] < arr[i + 1]) {
					val.pb(i);
				}
			} else if (i == n - 1) {
				if (arr[i] > arr[i - 1]) {
					peaks.pb(i);
				}
				if (arr[i] < arr[i - 1]) {
					val.pb(i);
				}
			} else {
				if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
					peaks.pb(i);
				}
				if (arr[i] < arr[i - 1] and arr[i] < arr[i + 1]) {
					val.pb(i);
				}
			}
		}
		vector<int> res(size(peaks) + size(val));
		if (peaks[0] > val[0]) {
			for (int i = 0, j = 0; i < size(res); i += 2, j++) {
				res[i] = arr[val[j]];
			}
			for (int i = 1, j = 0; i < size(res); i += 2, j++) {
				res[i] = arr[peaks[j]];
			}
		} else {
			for (int i = 1, j = 0; i < size(res); i += 2, j++) {
				res[i] = arr[val[j]];
			}
			for (int i = 0, j = 0; i < size(res); i += 2, j++) {
				res[i] = arr[peaks[j]];
			}
		}
		int ans = 0;
		if (size(res) == 1) {
			cout << res[0] << endl;
		} else {
			if (res[0] < res[1]) {
				ans = res[1];
				for (int i = 2; i < size(res) - 1; i += 2) {
					ans += res[i + 1] - res[i];
				}
			} else {
				ans = res[0];
				for (int i = 1; i < size(res) - 1; i += 2) {
					ans += res[i + 1] - res[i];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}