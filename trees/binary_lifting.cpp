#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;                       


vector<vector<int>> up;

//LOG: log2 of maximum depth
void create_lifting(vector<int> &parent, int root, int LOG){
    int n = parent.size();
    up.resize(n, vector<int>(LOG, 0));
    for(int i=0; i<n; i++){
        up[i][0] = parent[i];
    }
    for(int i=1; i<LOG; i++){
        for(int j=0; j<n; j++){
            up[j][i] = up[ up[j][i-1] ][i-1];
        }
    }
}

//Jump by "jump" steps
int find_ancestor(int v, int jump){
    int a = 0;
    while(jump > 0){
        int r = jump%2;
        if(r == 1){
            v = up[v][a];
        }
        jump /= 2;
        a++;
    }
    return v;
}

int main(){
    int n, q;
    cin>>n>>q;
    vector<int> parent(n+1, 0);
    for(int i=1; i<=n; i++){
        cin>>parent[i];
    }
    create_lifting(parent, 0, 33);
    int que = 0;
    while(q--){
        int x, k;
        cin>>x>>k;
        cout<<find_ancestor(x, k)<<endl;
    }
    return 0;
}