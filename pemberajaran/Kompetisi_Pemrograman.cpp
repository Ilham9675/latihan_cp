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
    
    int n,m,k,jum;
    cin >> n >> m >> k;
    vector<int> poin(n),prov(n),mx(m+1,0);
    for(int i = 0;i < n;i++){
        cin >> poin[i];
    }
    for(int i = 0;i < n;i++){
        cin >> prov[i];
    }

    for(int i = 0;i < n;i++){
        
        if(mx[prov[i]] < poin[i]){
            mx[prov[i]] = poin[i];
        }
    }
    jum = m;
    for(int i = 0;i < k;i++){
        int x;
        cin >> x;
        x--;
        if(mx[prov[x]] == poin[x]) continue;
        jum++;
    }

    cout << jum;
    

    return 0;
}