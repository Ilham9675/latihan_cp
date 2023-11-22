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
    
    int n,l,t,mulai,akhir;
    cin >> n >> l >> t >> mulai >>akhir;
    vector<int> jalur[n+1];
    for(int i = 0;i < l;i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        jalur[temp1].pb(temp2);
        jalur[temp2].pb(temp1);
    }
    vector<pair<int,int>> tol;
    for(int i = 0;i < t;i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        tol.pb({temp1,temp2});
    }

    int jarakM[n+1],jarakP[n+1];
    memset(jarakM,-1,sizeof(jarakM));
    memset(jarakP,-1,sizeof(jarakP));
    jarakM[mulai] = 0;
    jarakP[akhir] = 0;
    queue <int> temp;
    temp.push(mulai);
    while(!temp.empty()){
        int now = temp.front();
        temp.pop();
        for(auto i : jalur[now]){
            if(jarakM[i] == -1){
                jarakM[i] = jarakM[now]+1;
                temp.push(i);
            }
        }
    }

    temp.push(akhir);
    while(!temp.empty()){
        int now = temp.front();
        temp.pop();
        for(auto i : jalur[now]){
            if(jarakP[i] == -1){
                jarakP[i] = jarakP[now]+1;
                temp.push(i);
            }
        }
    }
    int jum = INT_MAX;
    if(jarakM[akhir] > -1){
        jum = jarakM[akhir];
    }

    for(auto i : tol){
        int temp1 = i.fi,temp2 = i.se;
        if(jarakM[temp1] > -1 && jarakP[temp2] > -1){
            jum = min(jum,jarakM[temp1] + jarakP[temp2] + 1); 
        }
        if(jarakM[temp2] > -1 && jarakP[temp1] > -1){
            jum = min(jum,jarakM[temp2] + jarakP[temp1] + 1); 
        }
    }
    cout << jum;
    return 0;
}