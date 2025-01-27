#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

ll n,dsu[200069];

vector<ll> al[200069];

inline void ae(ll x,ll y){
    al[x].pb(y);
    al[(y+n-1)%(n*2)+1].pb((x+n-1)%(n*2)+1);
}

ll fd(ll x){
    if(dsu[x] != x){
        dsu[x] = fd(dsu[x]);
    }
    return dsu[x];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    



    return 0;
}