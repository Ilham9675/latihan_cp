#include <bits/stdc++.h>
typedef long long ll;
using namespace std;




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N,K;
    cin >> N >> K;
    ll data[N+1];
    data[0] = 0;
    for(ll i = 1;i <= N;i++){
        cin >> data[i];
        data[i] += data[i-1];
    }
    for(ll i = 0;i < K;i++){
        
        int jarak;
        cin >> jarak;
        int jum = 0,j=1;
        while(jarak >= data[j]){
            jum++;
            j++;
        }
        cout << jum << endl;
    
    }

    return 0;
}