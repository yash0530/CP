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

class WeightedUF {
    private:
        vector<int> arr;
        vector<int> size;

        int __root(int a) {
            while (arr[a] != a) {
                arr[a] = arr[arr[a]];
                a = arr[a];
            }
            return a;
        }

    public:
        WeightedUF(int v) {
            arr = vector<int>(v + 1);
            size = vector<int>(v + 1);
            for (int i = 0; i <= v; i++) {
                size[i] = 1;
                arr[i] = i;
            }
        }

        bool _union(int a, int b) {
            int rootA = __root(a);
            int rootB = __root(b);

            if (rootA == rootB) return false;
            
            if (size[rootA] < size[rootB]) {
                arr[rootA] = rootB;
                size[rootB] += size[rootA];
            } else {
                arr[rootB] = rootA;
                size[rootA] += size[rootB];
            }
            return true;
        }

        bool _find(int a, int b) {
            return __root(a) == __root(b);
        }
};

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m, k, u, v, w;
		cin >> n >> m >> k;
		vector<array<int, 3>> edges(m);
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> w;
			edges.pb({ w, u, v });
		}
		sort(_all(edges));
		WeightedUF uf(n);
		vector<array<int, 3>> mst;
		for (auto e : edges) {
			if (uf._union(e[1], e[2])) {
				mst.pb(e);
			}
		}
		int ans = 0;
		if (mst.back()[0] < k) {
			int near = INF;
			int loc, i = 0;
			for (auto e : edges) {
				if (near > abs(k - e[0])) {
					near = abs(k - e[0]);
					loc = i;
				}
				i++;
			}
			ans += abs(k - edges[loc][0]);
		} else {
			for (auto m : mst) {
				if (m[0] > k) {
					ans += m[0] - k;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}