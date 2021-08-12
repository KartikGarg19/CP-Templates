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
#include<fstream>
using namespace std;                       

#define pb push_back

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

bool findCycle(int src, vector<vector<int>> &g, vector<bool> &visited, vector<bool> &recStack){
    if(!visited[src]){
        visited[src] = true;
        recStack[src] = true;
        for(auto u: g[src]){
            if(!visited[u] && findCycle(u, g, visited, recStack)) return true;
            if(recStack[u]) return true;
        }
    }
    recStack[src] = false;
    return false;
}