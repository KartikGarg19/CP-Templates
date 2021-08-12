#include<bits/stdc++.h>
using namespace std;

const int V = 101;
int adj[V][V];
int dist[V][V];

void floydWarshall(){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i == j) dist[i][j] = 0;
            else if(adj[i][j] != 0) dist[i][j] = adj[i][j];
            else adj[i][j] = INT_MAX;
        }
    }
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){

    return 0;

}
