#include <bits/stdc++.h>
typedef long long ll;
using namespace std;




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N,mod = 998244353;
    cin >> N;
    ll nilai[N];
    for(int i = 0;i < N;i++){
        cin >> nilai[i];
    }

    ll total = 1;
    for(ll i = 0;i < N;i++){
        for(ll j = i+1;j < N;j++){
            if(nilai[i] == nilai[j]){
                total = 0;
                break;
            }
            total = (total*((nilai[i]^nilai[j])%mod))%mod;
        }
        if(total == 0){
            break;
        }
    }
    cout << total;

    return 0;
}