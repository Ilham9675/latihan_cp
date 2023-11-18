#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll N,X;
    cin >> N >> X;
    ll W[N];
    pair<double,ll> data[N];
    for(ll i = 0;i < N;i++){
        cin >> W[i];
    }
    for(ll i = 0;i < N;i++){
        cin >> data[i].first;
        data[i].first = data[i].first / W[i];
        data[i].second = i;
    }

    sort(data,data+N, greater<pair<double,ll>>());
    double jum_harga = 0;
    for(ll i = 0; i < N; i++){
        ll jenis = data[i].second;
        ll beras = W[jenis];
        for(ll j = 0; j <beras;j++){
            if(X>0){
                jum_harga += data[i].first;
                X--;
            }
        }
        if(X<=0){
            break;
        }
    }
    cout << fixed << setprecision(5) << jum_harga;

    return 0;
}