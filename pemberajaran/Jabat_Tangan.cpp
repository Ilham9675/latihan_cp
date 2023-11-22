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
    
    int t;
    cin >> t;
    ll temp[t+1];
    temp[0] = 1;
    temp[1] = 0;
    for(int i = 2;i <= t;i++){
        temp[i] = 0;
        for(int j = 2;j <= i;j++){
            temp[i] += temp[j-2] * temp[i-j];
        }
    }
    cout << temp[t];

    return 0;
}