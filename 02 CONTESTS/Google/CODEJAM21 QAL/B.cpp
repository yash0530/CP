#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
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
#define _mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _add(a, b) ((a % HELL) + (b % HELL)) % HELL
#define _sub(a, b) (((a % HELL) - (b % HELL)) % HELL + HELL) % HELL
#define _all(aa) aa.begin(), aa.end()

int n, x, y;
string s;
const int maxN = 1e3 + 5;
int dp[maxN][2];

int res(int pos, int last) {
	if (pos == n) return 0;
	int &ans = dp[pos][last];
	if (ans == -1) {
		ans = 0;
		if (s[pos] == 'C') {
			if (last == 1) {
				ans = y + res(pos + 1, 0);
			} else {
				ans = res(pos + 1, 0);
			}
		} else if (s[pos] == 'J') {
			if (last == 0) {
				ans = x + res(pos + 1, 1);
			} else {
				ans = res(pos + 1, 1);
			}
		} else {
			if (last == 1) {
				ans = min(res(pos + 1, 1), y + res(pos + 1, 0));
			} else {
				ans = min(x + res(pos + 1, 1), res(pos + 1, 0));
			}
		}
	}
	return ans;
}

void solve() {
	cin >> x >> y >> s;
	n = size(s);
	memset(dp, -1, sizeof dp);
	if (s[0] == 'C') {
		cout << res(1, 0) << endl;
	} else if (s[0] == 'J') {
		cout << res(1, 1) << endl;
	} else {
		cout << min(res(1, 0), res(1, 1)) << endl;
	}
}

signed main() { fastio;
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}