#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
// #define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

signed main() { fastio;
	int n; cin >> n;
	int a[n + 1], b[n + 1];
	int val = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> b[i];
		val += b[i];
	}
	int dp[n + 5][10005];
	for (int j = 0; j <= n; j++) {
		for (int k = 0; k <= 10000; k++) {
			dp[j][k] = -1000000;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 10000; k >= 0; k--) {
			for (int j = 1; j <= i; j++) {
				if ((k - a[i]) >= 0) {
					dp[j][k] = max(dp[j][k], dp[j - 1][k - a[i]] + b[i]);
				}
			}
		}
	}
	for (int j = 1; j <= n; j++) {
		double ans = 0;
		for (int k = 0; k <= 10000; k++) {
			ans = max(ans, min((double)k, ((double)dp[j][k] / 2.0) + ((double)val / 2.0)));
		}
		pout << ans << " ";
	} cout << endl;
	return 0;
}