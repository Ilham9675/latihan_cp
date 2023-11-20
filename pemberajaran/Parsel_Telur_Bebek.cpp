#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n,m;
ll kel[1000001];
ll cek(ll nilai){
    ll total = 0;
    for(int i = 1;i <= n;i++){
        total += nilai/kel[i];
        if(nilai/kel[i] == 0){
            break;
        }
    }
    return total;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> kel[i];
    }
    
    sort(kel+1,kel+n+1);
    

    ll temp,L = kel[1],R = kel[1] * m;
    ll awal = 0,akhir = 0;
    while(L <= R){
        temp = (L+R)/2;
        ll tes = cek(temp);
        if(tes == m){
            akhir = temp;
            L = temp + 1;
        }
        if(tes > m){
            R = temp - 1;
        }
        if(tes < m){
            L = temp + 1;
        }
    }
    L = kel[1],R = akhir;
    while(L <= R){
        temp = (L+R)/2;
        ll tes = cek(temp);
        if(tes == m){
            awal = temp;
            R = temp - 1;
        }
        if(tes > m){
            R = temp - 1;
        }
        if(tes < m){
            L = temp + 1;
        }
    }
    if(awal == 0 && akhir == 0){
        cout << 0;
    }else{
        cout << akhir- awal+1;
    }
    

    return 0;
}