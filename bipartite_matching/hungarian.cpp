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
using namespace std;                       

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define sc second

//n jobs, m people
//vector a[n+1][m+1]: a[i][j] means cost of ith person doing jth job
vector<int> assignment;

ll hungarian(const vector<vector<ll>>& a) { 
	int n = a.size()-1, m = a[0].size()-1; 
    // assert(n <= m);
	vector<ll> u(n+1), v(m+1); // potentials to make edge weights >= 0
	vector<int> job(m+1);
	for(int i=1; i<=n; i++) { // find alternating path with job i
		const ll inf = numeric_limits<ll>::max();
		int w = 0; job[w] = i; // add "dummy" 0, find path to real worker
		vector<ll> dist(m+1,inf); vector<int> pre(m+1,-1); vector<bool> done(m+1);
		while (job[w]) { // dijkstra
			done[w] = 1; int j = job[w], nexW; ll delta = inf; 
			// fix dist[j], update dists from j
			for(int W=0; W<=m; W++) if (!done[W]) { // try all workers
				if (a[j][W]-u[j]-v[W] < dist[W]){
                    dist[W] = a[j][W]-u[j]-v[W];
                    pre[W] = w;
                }
				if (dist[W] < delta){
                    delta = dist[W];
                    nexW = W;
                }
			}
			for(int W=0; W<=m; W++) { // subtract constant from all edges going 
				// from done -> not done vertices, lowers all 
				// remaining dists by constant
				if (done[W]) u[job[W]] += delta, v[W] -= delta; 
				else dist[W] -= delta; 
			}
			w = nexW;
		} // potentials adjusted so all edge weights >= 0
		for (int W; w; w = W) job[w] = job[W = pre[w]];
	} // job[w] = 0, found alternating path 
	// assigment to return which job is done by which person
	// assignment = job;
	return -v[0]; // min cost
}

int main(){
    return 0;
}