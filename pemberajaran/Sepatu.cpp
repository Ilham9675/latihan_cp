#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,m,temp,jum = 0;
    cin >> n >> m;
    ll data1[n],data2[n];
    for(ll i = 0;i < n;i++){
        cin >> data1[i];
    }
    for(ll i = 0;i < m;i++){
        cin >> data2[i];
    }
    sort(data1, data1+n);
    sort(data2, data2+m);
    
    ll i = 0,j = 0;
    while(i < n && j < m){
        if((data1[i] - data2[j] == 1) || (data1[i] == data2[j])){
            jum++;
            i++;
            j++;
        }else if(data1[i] < data2[j]){
            i++;
        }else{
            j++;
        }
    }
    cout << jum;

    return 0;
}