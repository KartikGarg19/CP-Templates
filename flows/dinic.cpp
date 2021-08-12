#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<ctime>
#include<cmath>
#include<utility>
#include<cstdlib>
#include<bitset>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<assert.h>
using namespace std;                       

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define sc second
#define V vector
#define vi vector<int>
#define vl vector<ll>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//Time Complexity: O(Vˆ2 * E)
//However usually max-flow algorithms work much faster than advertised time complexity
//Because its very tough to make a worst-time case for them

struct Dinic {
	using F = ll; // flow type
	struct Edge { int to, rev; F flo, cap; };
	int N; V<V<Edge>> adj;
	void init(int _N) { N = _N; adj.resize(N); }
	/// void reset() { F0R(i,N) each(e,adj[i]) e.flo = 0; }
    // Add edge from a to b with capacity cap and reverse capacity rcap
	void ae(int a, int b, F cap, F rcap = 0) {
		adj[a].pb({b,adj[b].size(),0,cap});
		adj[b].pb({a,adj[a].size()-1,0,rcap});
	}
	vi lev, ptr;
	bool bfs(int s, int t) { // level = shortest distance from source
		lev = ptr = vi(N);
		lev[s] = 1; queue<int> q({s});
		while (q.size()) { int u = q.front(); q.pop();
			for(auto e : adj[u]) if (e.flo < e.cap && !lev[e.to])
				q.push(e.to), lev[e.to] = lev[u]+1;
		}
		return lev[t];
	}
	F dfs(int v, int t, F flo) {
		if (v == t) return flo;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i]; F dif = e.cap-e.flo;
			if (lev[e.to]!=lev[v]+1||!dif) continue;
			if (F df = dfs(e.to,t,min(flo,dif))) { 
				e.flo += df; adj[e.to][e.rev].flo -= df;
				return df; } // saturated >=1 one edge
		}
		return 0;
	}
    //Max Flow from source s to sink t
	F maxFlow(int s, int t) {
		F tot = 0; while (bfs(s,t)) while (F df = 
			dfs(s,t,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

int main(){
    Dinic g;
    int n;
    cin>>n;
    g.init(n);

}