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
    
    int V,E,a,b;
    cin >> V >> E >> a >> b;
    vector<pii> nilai[2501];
    int x,y,z;
    for(int i = 1;i <= E;i++){
        cin >> x >> y >> z;
        nilai[x].push_back({y,z});
        nilai[y].push_back({x,z});
    }
    int range[2501];
    for(int i = 1;i <= V;i++){
        range[i] = INT_MAX;
    }
    priority_queue<pii,vector<pii>,greater<pii>> temp;
    
    temp.push({0,a});
    range[a] = 0;
    bool cek[2501];
    while(!temp.empty()){
        int sem = temp.top().second;
        temp.pop();
        if(!cek[sem]){
            cek[sem] = true;
            for(auto i : nilai[sem]){
                if(range[i.first] > range[sem] + i.second){
                    range[i.first] = range[sem] + i.second;
                    temp.push({range[i.first],i.first});
                }
            }
        }
    }
    cout << range[b];



    return 0;
}