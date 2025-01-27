#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    vector<pii> adj[15001];
    int dp[15001];
    int n, m = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[b].pb({a,c});
        m = max(m,b);
    }
    dp[0] = 0;
    for(int i = 1;i <= m;i++){
        dp[i] = dp[i-1];
        for(auto j : adj[i]){
            dp[i] = max(dp[i],dp[j.fi-1] + j.se);
        }
    }
    cout << dp[m];

    return 0;
}