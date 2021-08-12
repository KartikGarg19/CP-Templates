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
#include<assert.h>
using namespace std;                       

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define sc second
#define V vector
#define vi vector<int>
#define vl vector<ll>


#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const ll M = 1e9 + 7;

ll add(ll a, ll b){
    (a += b)%=M;
    (a += M)%=M;
    return a;
}

ll mul(ll a, ll b){
    (a *= b)%=M;
    (a += M)%=M;
    return a;
}

ll fastpo(ll a, ll x){
    if(x == 0) return 1ll;
    if(x == 1) return a;
    ll y = fastpo(a, x/2);
    if(x%2 == 0){
        return mul(y, y);
    }
    return mul(y, mul(y, a));
}

ll inv(ll a, ll M){
    return fastpo(a, M-2);
}


ll gcd(ll a, ll b){
    if(a == 0){
        return b;
    }
    return gcd(b%a, a);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}

void print(vector<int> &a){
    int n = a.size();
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


void print(vector<ll> &a){
    int n = a.size();
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}



int main(){
//    clock_t time_req;
//     time_req = clock();
    fastio;
    int t;
    cin>>t;
    // t = 1;
    while(t--){

    }
    // time_req = clock()-time_req;
    // cout<<"Time taken: "<<(float)time_req/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}