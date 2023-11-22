#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

ll mod = 1e9+7;

ll cari(ll a,ll b){
    if(!b){
        return 1;
    }
    ll hasil = cari(a,b/2);
    hasil = hasil*hasil%mod;
    if(b%2){
        hasil = hasil*a%mod;
    }
    return hasil;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,hasil;
    cin >> n >> m;
    n%=mod;
    if(n == 1){
        cout << m%mod*(m%mod+1)/2%mod;
        return 0;
    }
    ll a = cari(n,m+1);
    ll b = cari(n-1,mod-2);
    hasil = (a*(m%mod)+mod-(a+mod-n)*b%mod)%mod*b%mod;
    cout << hasil;
    

    return 0;
}