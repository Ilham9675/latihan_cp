#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


const ll mod = 1e6;
bool cek = false;

ll pangkat(ll a,ll b){
    if(b == 0) return 1;
    if(a == 0) return 0;
    if(b == 1) return a;
    ll x = pangkat(a,b/2);
    x *= x;
    ll y = x % mod * a;
    if(b & 1){
        if(!cek){
            if(x >= mod || y >= mod) cek = true;
        }
        return y % mod;
    }
    if(!cek){
        if(x >= mod) cek = true;
    }
    return x % mod;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a,b;
    cin >> a >> b;
    ll hasil = pangkat(a,b);
    if(hasil >= mod){
        cek = true;
        hasil %= mod;
    }

    int n = 1e5;
    while(hasil < n && n > 1 && cek){
        cout << '0';
        n /= 10;
    }
    cout << hasil;
    

    return 0;
}