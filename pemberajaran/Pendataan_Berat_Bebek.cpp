#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    ll data[N];
    for(int i = 0; i < N;i++){
        cin >> data[i];
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        ll x,y,j = 0,jum = 0;
        cin >> x >> y;
        auto bawah = lower_bound(data, data+N,x+1) - data;
        auto atas = upper_bound(data, data+N,y) - data;
        
        cout << atas - bawah << endl;
    }
    

    return 0;
}