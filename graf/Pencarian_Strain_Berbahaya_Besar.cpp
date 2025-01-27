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



ll n,s,p,arr[1000005],sum;
string a,ans;
ll b;
ll x,y,maksimum;
vector<pair<string,int>> virus;
vector<int> adj[1000005];
bool vis[1000005];

ll dfs(int q){
    vis[q] = true;
    ll mx = 0;
    ll sum = arr[q];
    for(int i = 0;i < adj[q].size();i++){
        int v = adj[q][i];
        if(!vis[v]){
            mx = max(mx,dfs(v));
        }
    }
    sum += mx;
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> p;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }

    for(int i = 1;i<=p;i++){
        cin >> a >> b;
        virus.pb({a,b});
    }

    for(int i = 0;i < n-p;i++){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    maksimum = 0;
    for(int i = 0;i < virus.size();i++){
        ll hasil = dfs(virus[i].second);
        //cout << hasil << endl;
        if(hasil > maksimum){
            maksimum = hasil;
            ans = virus[i].first;
        }
    }
    cout << ans << endl << maksimum;
    


    return 0;
}