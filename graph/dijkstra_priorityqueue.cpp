#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

const int V = 1001;
vector<pair<int, int> > v[V];    //adjacency list.. first element of pair is neighbour and second is edge weight
vector<int> dist(V, INT_MAX);

void dijkstra(int source){
    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(make_pair(0, source));
    dist[source] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(int i=0; i<v[u].size(); i++){
            int x = v[u][i].first, weight = v[u][i].second;
            if(dist[x] > dist[u] + weight){
                dist[x] = dist[u] + weight;
                pq.push(make_pair(dist[x], x));
            }
        }
    }

}

int main(){

    return 0;
}
