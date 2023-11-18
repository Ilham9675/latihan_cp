#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n ,x;
    cin >> n >> x;
    ll kupon;
    ll temp = INT_MAX,pemenang;
    for(int i = 0; i < n; i++){
        cin >> kupon;
        if(temp == abs(kupon - x)){
            if(kupon < pemenang){
                pemenang = kupon;
            }
        }
        if(temp > abs(kupon - x)){
            temp = abs(kupon - x);
            pemenang = kupon;
        }
    }
    cout << pemenang;
    return 0;
}