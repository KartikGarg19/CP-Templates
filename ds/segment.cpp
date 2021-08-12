#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

struct segtree{
    int size;
    vector<ll> a;

    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        a.assign(2*size, 0ll);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            a[x] = v;
            return ;
        }
        int m = (lx + rx)/2;
        if(i < m){
            set(i, v, 2*x+1, lx, m);
        }
        else{
            set(i, v, 2*x+2, m, rx);
        }
        a[x] = a[2*x+1]+a[2*x+2];
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return 0;        //Neutral Value
        if(lx >= l && rx <= r){
            return a[x];
        }
        int m = (lx + rx)/2;
        ll s1 = sum(l, r, 2*x+1, lx, m);
        ll s2 = sum(l, r, 2*x+2, m, rx);
        return s1+s2;
    }
    ll sum(int l, int r){           //Finds sum from l to r
        return sum(l, r, 0, 0, size);
    }

};

int main(){
    segtree s;
    int n, m;
    cin>>n>>m;
    s.init(n);
    for(int i=0; i<n; i++){
        int v;
        cin>>v;
        s.set(i, v);
    }
    while(m--){
        int op;
        cin>>op;
        if(op == 1){
            int i, v;
            cin>>i>>v;
            s.set(i, v);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout<<s.sum(l, r)<<endl;
        }
    }
    return 0;
}