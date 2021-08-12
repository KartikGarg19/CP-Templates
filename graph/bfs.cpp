#include<bits/stdc++.h>
using namespace std;

vector<int> v[10];
bool visited[10];

void bfs(int source){
    queue<int> q;
    visited[source] = true;
    q.push(source);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0; i<v[t].size(); i++){
            if(!visited[v[t][i]]){
                q.push(v[t][i]);
                visited[v[t][i]] = true;
            }
        }
    }
}

int main(){

    return 0;
}
