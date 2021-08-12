//Strongly Connected Component

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

stack<int> s;

void dfs(vector<vector<int>> &graph, vector<bool> &done, int source){
    done[source] = true;
    for(auto v: graph[source]){
        if(!done[v]){
            dfs(graph, done, v);
        }
    }
    s.push(source);
}

void dfsUtil(vector<vector<int>> &graph, vector<bool> &done, int source){
    done[source] = true;
    cout<<source<<" ";
    for(auto v: graph[source]){
        if(!done[v]){
            dfsUtil(graph, done, v);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n, vector<int>());
    vector<vector<int>> graphT(n, vector<int>());
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graphT[y].push_back(x);
    }
    vector<bool> done(n, false);
    for(int i=0; i<n; i++){
        if(!done[i]){
            dfs(graph, done, i);
        }
    }
    for(int i=0; i<n; i++){
        done[i] = false;
    }
    int t = 1;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!done[u]){
            cout<<"Component "<<t<<": ";
            dfsUtil(graphT, done, u);
            cout<<endl;
            t++;
        }
    }
    return 0;
}