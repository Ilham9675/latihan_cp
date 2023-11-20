#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

ll mod;


ll pangkat(ll a,ll b){
    if(a == 0) return 0;
    if(a == 1 || b == 0) return 1;
    else{
        ll temp = pangkat(a,b/2);
        if(b % 2 == 0) return (temp * temp)%mod;
        if(b % 2 == 1) return (((temp * temp) % mod) * a) % mod;
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll A,B,C,N;
    cin >> A >> B >> C >> N;
    mod = N;
    for(int i = 0;i < C;i++){
        ll hasil = B;
        A = pangkat(A,hasil) % mod;
    }
    cout << A + 1;
    

    return 0;
}