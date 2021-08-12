#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long

const ll N = 200043;
const ll MOD = 998244353;
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

ll inv(ll x){
    return fastpo(x, MOD - 2);
}

ll divide(ll x, ll y){
    return mul(x, inv(y));
}

ll fact[N];

void precalc()
{
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

ll C(ll n, ll k)
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}


