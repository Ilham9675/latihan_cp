#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    ll arr[n+1],nilai[n+1];
    for(ll i = 1;i <= n;i++) cin >> arr[i];
    nilai[1] = 0;
    nilai[2] = pow((arr[2]-arr[1]),2);
    for(ll i = 3;i <= n;i++){
        nilai[i] = min(pow(arr[i]-arr[i-1],2)+nilai[i-1] , 3*pow(arr[i]-arr[i-2],2)+nilai[i-2]);
        nilai[i-1] = min(nilai[i-1], (arr[i]-arr[i-1])* (arr[i]-arr[i-1])+nilai[i]);
        
    }
    cout << nilai[n];

    return 0;
}