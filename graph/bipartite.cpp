#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartite(vector<vector<int>> &graph, vector<int> &color, int src){
    int n = color.size();
    queue<int> q;
    color[src] = 1;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: graph[u]){
            if(color[v] == color[u]) return false;
            if(color[v] == -1){
                color[v] = 1-color[u];
                q.push(v);
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n, vector<int>());
    vector<int> color(n, -1);
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=0; i<n; i++){
        if(color[i] == -1){
            if(!isBipartite(graph, color, i)){
                cout<<"False"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}