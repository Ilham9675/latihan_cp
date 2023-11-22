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
    
    int k,n;
    cin >> k >> n;
    int w[n+1],h[n+1];
    for(int i=1; i<=n; i++){
        cin >> w[i] >> h[i];
    }
    int nilai[n+2][k+1];
    memset(nilai,0,sizeof(nilai));
    for(int i = n;i >= 1;i--){
        for(int j = 0;j <= k;j++){
            nilai[i][j] = nilai[i+1][j];
            if(j >= w[i]){
                nilai[i][j] = max(nilai[i][j],nilai[i+1][j-w[i]] + h[i]);
            }
        }
    }

    int berat_min = k;
    for(int i = k;i >= 0;i--){
        if(nilai[1][i] == nilai[1][k]){
            berat_min = i;
        }
    }
    for(int i = 1;i <= n;i++){
        if(nilai[i][berat_min] == nilai[i+1][berat_min-w[i]]+h[i]){
            cout << i << endl;
            berat_min -= w[i];
        }
    }

    return 0;
}