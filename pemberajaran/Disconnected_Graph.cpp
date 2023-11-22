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
    while(t--){
        int n,e,q,r;
        cin >> n >> e >> q >> r;
        pair<int,int> edge[e+1];
        for(int i = 1;i <= e;i++){
            cin >> edge[i].fi >> edge[i].se;
        }
        bool gone[e+1];
        memset(gone,0,sizeof(gone));
        bool khusus[n+1];
        memset(khusus,0,sizeof(khusus));
        for(int i = 1;i <= q;i++){
            int temp;
            cin >> temp;
            khusus[temp] = 1;
        }
        for(int i = 1;i <= r;i++){
            int temp;
            cin >> temp;
            gone[temp] = 1;
        }
        vector<int> list[n+1];
        for(int i = 1;i <= e;i++){
            if(!gone[i]){
                list[edge[i].fi].pb(edge[i].se);
                list[edge[i].se].pb(edge[i].fi);
            }
        }
        bool vis[n+1];
        memset(vis, 0, sizeof(vis));
        ll jum = 0;
        for(int i = 1;i <= n;i++){
            if(!vis[i]){
                stack<int> temp;
                temp.push(i);
                vis[i] = 1;
                int cnt = 0;
                while(!temp.empty()){
                    int now = temp.top();
                    temp.pop();
                    cnt += khusus[now];
                    for(auto j : list[now]){
                        if(!vis[j]){
                            temp.push(j);
                            vis[j] = 1;
                        }
                    }
                }
                jum += ((ll)cnt * (q-cnt));
            }
        }
        cout << jum/2 << endl;
    }

    return 0;
}