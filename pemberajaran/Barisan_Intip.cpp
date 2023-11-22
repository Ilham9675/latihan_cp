#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,jum = 0;
    cin >> n;
    ll data[n],jarak[n];
    for(ll i = 0;i < n;i++){
        cin >> data[i];
        jarak[i] = 1;
        for(ll j = i -1;j >= 0;j -= jarak[j]){
            if(data[i] >= data[j]){
                jarak[i] += jarak[j];
            }else{
                break;
            }
        }
        jum += jarak[i];
    }
    
    cout << jum;

    return 0;
}