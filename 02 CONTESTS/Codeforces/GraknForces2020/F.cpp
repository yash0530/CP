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

int np2(int n) {
	int val = 1;
	while (n) {
		val *= 2;
		n /= 2;
	}
	return val / 2;
}

vector<array<int, 2>> gen(int n) {
	if (n == 1) {
		return {};
	}
	vector<array<int, 2>> r1 = gen(n / 2);
	vector<array<int, 2>> r2 = gen(n / 2);
	for (auto r : r2) {
		r1.pb({ r[0] + (n / 2), r[1] + (n / 2) });
	}
	for (int i = 1; i <= (n / 2); i++) {
		r1.pb({ i, i + (n / 2) });
	}
	return r1;
}

int32_t main() { fastio;
	int n; cin >> n;
	int loc = np2(n);
	auto x = gen(loc);
	cout << 2 * size(x) << endl;
	for (auto xx : x) cout << xx[0] << " " << xx[1] << endl;
	for (auto xx : x) cout << xx[0] + (n - loc) << " " << xx[1] + (n - loc) << endl;
	return 0;
}