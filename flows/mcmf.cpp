/**
 * Description: Minimum-cost maximum flow, assumes no negative cycles. 
 	* It is possible to choose negative edge costs such that the first 
 	* run of Dijkstra is slow, but this hasn't been an issue in the past. 
 	* Edge weights $\ge 0$ for every subsequent run. To get flow through 
 	* original edges, assign ID's during \texttt{ae}.
 * Time: Ignoring first run of Dijkstra, $O(FM\log M)$ 
 	* if caps are integers and $F$ is max flow.
 */

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

struct MCMF { 
	using F = ll; using C = ll; // flow type, cost type
	struct Edge { int to; F flo, cap; C cost; };
	int N; V<C> p, dist; vi pre; V<Edge> eds; V<vi> adj;
	void init(int _N) { N = _N;
		p.resize(N), dist.resize(N), pre.resize(N), adj.resize(N); }
    //Add edge from u to v with Capacity cap and Cost cost
	void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
		adj[u].pb(eds.size()); eds.pb({v,0,cap,cost}); 
		adj[v].pb(eds.size()); eds.pb({u,0,0,-cost});
	} // use asserts, don't try smth dumb
	bool path(int s, int t) { // find lowest cost path to send flow through
		const C inf = numeric_limits<C>::max(); for(int i=0; i<N; i++) dist[i] = inf;
		using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo; 
		todo.push({dist[s] = 0,s}); 
		while (todo.size()) { // Dijkstra
			T x = todo.top(); todo.pop(); if (x.fi > dist[x.sc]) continue;
			for(auto e: adj[x.sc]) { const Edge& E = eds[e]; // all weights should be non-negative
				if (E.flo < E.cap && x.fi+E.cost+p[x.sc]-p[E.to] < dist[E.to]){
                    dist[E.to] = x.fi+E.cost+p[x.sc]-p[E.to];
					pre[E.to] = e, todo.push({dist[E.to],E.to});
                }
			}
		} // if costs are doubles, add some EPS so you 
		// don't traverse ~0-weight cycle repeatedly
		return dist[t] != inf; // return flow
	}
    //Returns {totFlow, totCost}
	pair<F,C> calc(int s, int t) { assert(s != t);
		for(int _=0; _<N; _++) for(int e=0; e<eds.size(); e++) { const Edge& E = eds[e]; // Bellman-Ford
			if (E.cap) {
                if(p[eds[e^1].to]+E.cost < p[E.to]){
                    p[E.to] = p[eds[e^1].to]+E.cost;
                }
            }
        }
		F totFlow = 0; C totCost = 0;
		while (path(s,t)) { // p -> potentials for Dijkstra
			for(int i=0; i<N; i++) p[i] += dist[i]; // don't matter for unreachable nodes
			F df = numeric_limits<F>::max();
			for (int x = t; x != s; x = eds[pre[x]^1].to) {
				const Edge& E = eds[pre[x]]; 
                if(E.cap-E.flo < df){
                    df = E.cap-E.flo;
                }
            }
			totFlow += df; totCost += (p[t]-p[s])*df;
			for (int x = t; x != s; x = eds[pre[x]^1].to)
				eds[pre[x]].flo += df, eds[pre[x]^1].flo -= df;
		} // get max flow you can send along path
		return {totFlow,totCost};
	}
};

int main(){
    int n;
    cin>>n;
    MCMF g;
    g.init(n);
    ll flow, cost;
    pll sol = g.calc(0, n);
    flow = sol.fi; cost = sol.sc;

}