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
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

// SOLUTION IDEA GEOTHERMAL

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		deb(m);deb(n);
		vector<pii> cc(m);
		for (auto &c : cc) {
			cin >> c.sc >> c.fs;
		}
		sort(_all(cc));
		bool poss = true;
		if (m & 1) {
			poss = false;
		} else {
			for (int i = 0; i < m; i += 2) {
				if (((cc[i].fs + cc[i].sc) & 1) == ((cc[i + 1].fs + cc[i + 1].sc) & 1)) {
					poss = false; break;
				} else if (i and (cc[i].fs == cc[i - 1].fs)) {
					poss = false; break;
				}
			}
		}
		if (poss) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}