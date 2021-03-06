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

struct Edge {
    int v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> dijkstra(int x, vector<vector<Edge>> &adj) {
    int n = size(adj);
    vector<int> distance(n + 1);
    vector<bool> processed(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= n; i++) {
        distance[i] = INF;
    }
    distance[x] = 0;
    q.push({ 0, x });
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.v, w = u.weight;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({ distance[b], b });
            }
        }
    }
    return distance;
}

int32_t main() { fastio;
	int n, k, a, b;
	cin >> n >> k;	
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<array<int, 2>> xs, ys, portals;
	vector<vector<Edge>> adj(k + 5);
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		portals.pb({ a, b });
		xs.pb({ a, i });
		ys.pb({ b, i });
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	for (int i = 1; i < k; i++) {
		adj[xs[i - 1][1] + 1].pb({ xs[i][1] + 1, xs[i][0] - xs[i - 1][0] });
		adj[xs[i][1] + 1].pb({ xs[i - 1][1] + 1, xs[i][0] - xs[i - 1][0] });

		adj[ys[i - 1][1] + 1].pb({ ys[i][1] + 1, ys[i][0] - ys[i - 1][0] });
		adj[ys[i][1] + 1].pb({ ys[i - 1][1] + 1, ys[i][0] - ys[i - 1][0] });
	}
	for (int i = 0; i < k; i++) {
		int th = i + 1;
		auto p = portals[i];

		adj[k + 1].pb({ th, min(abs(x1 - p[0]), abs(y1 - p[1])) });
		adj[th].pb({ k + 1, min(abs(x1 - p[0]), abs(y1 - p[1])) });

		adj[k + 2].pb({ th, abs(x2 - p[0]) + abs(y2 - p[1]) });
		adj[th].pb({ k + 2, abs(x2 - p[0]) + abs(y2 - p[1]) });
	}
	auto da = dijkstra(k + 1, adj);
	cout << min({ abs(x1 - x2) + abs(y1 - y2), da[k + 2] });
	return 0;
}