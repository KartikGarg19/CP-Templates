#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;                       

#define ll long long
#define pb push_back

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

void lifting(vector<vector<int>> &lift, vector<int> &par){
    int n = par.size()-1;
    for(ll exp = 0; exp <20; exp++){
        for(int i=1; i<=n; i++){
            if(exp == 0) lift[i][exp] = par[i];
            else{
                if(lift[i][exp-1] == -1) lift[i][exp] = -1;
                else lift[i][exp] = lift[lift[i][exp-1]][exp-1];
            }
        }
    }
}

int kth_par(vector<vector<int>> &lift, int u, int k){
    if(k == 0 || u == -1) return u;
    if(k == 1) return lift[u][0];
    while(k > 0){
        for(int exp = 19; exp>=0; exp--){
            int p = pow(2, exp);
            if(p <= k){
                k -= p;
                u = lift[u][exp];
                if(u == -1) return u;
                break;
            }
        }
    }
    return u;
}

void dfs(vector<vector<int>> &g, vector<int> &par, vector<int> &tin, vector<int> &tout, int &timer, int u){
    tin[u] = timer++;
    for(auto v: g[u]){
        dfs(g, par, tin, tout, timer, v);
    }
    tout[u] = timer++;
}

bool is_ancestor(vector<int> &tin, vector<int> &tout, int u, int v){
    if(u == -1) return true;
    if(v == -1) return true;
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(vector<vector<int>> &lift, vector<int> &tin, vector<int> &tout, int u, int v){
    if(is_ancestor(tin, tout, u, v)) return u;
    if(is_ancestor(tin, tout, v, u)) return v;
    for(int i=19; i>=0; i--){
        if(!is_ancestor(tin, tout, lift[u][i], v)){
            u = lift[u][i];
        }
    }
    return lift[u][0];
}


int main(){
    fastio;
    int n;
    cin>>n;
    vector<vector<int>> g(n+1, vector<int>());
    vector<int> par(n+1, -1);
    for(int i=2; i<=n; i++){
        cin>>par[i];
        g[par[i]].pb(i);
    }
    vector<vector<int>> lift(n+1, vector<int>(20, -1));
    lifting(lift, par);
    vector<int> tin(n+1, -1), tout(n+1, -1);
    int timer = 0;
    dfs(g, par, tin, tout, timer, 1);
    int u, v;
    lca(lift, tin, tout, u, v);
    return 0;
}