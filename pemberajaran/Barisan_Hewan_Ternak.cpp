#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll nilai[100000];

void cari(ll L,ll R,ll &hasil, ll target){
    if(L <= R){
        ll mid = (L+R)/2;
        if(nilai[mid] == target){
            hasil = mid;
        }else if(nilai[mid] > target){
            hasil = mid;
            cari(L,mid - 1,hasil,target);
        }else if(nilai[mid] < target){
            cari(mid + 1,R,hasil,target);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N,K;
    cin >> N;
    nilai[0] = 0;
    for(ll i=1; i<=N; i++){
        cin >> nilai[i];
        nilai[i] += nilai[i-1];
    }
    cin >> K;
    ll L,R;
    ll target;
    for(ll i = 0;i < K; i++){
        cin >> target;
        ll hasil = 0;
        cari(1,N,hasil,target);
        cout << hasil << endl;
    }

    return 0;
}