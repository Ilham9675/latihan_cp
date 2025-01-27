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
    int n,m,q;
    int jarak[201][201],temp[201];

    cin >> n >> m >> q;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j){
                jarak[i][j] = 0;
            }else{
                jarak[i][j] = 1e9;
            }
        }
    }
    int x,y,z;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        jarak[x][y] = min(jarak[x][y], z);
        jarak[y][x] = min(jarak[y][x], z);
    }

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                jarak[j][k] = min(jarak[j][k], jarak[j][i]+jarak[i][k]);
            }
        }
    }
    int jum = 0;
    for(int i = 1;i <= q;i++){
        cin >> temp[i];
        if(i > 1){
            jum += jarak[temp[i]][temp[i-1]];
        }
    }
    cout << jum;


    

    return 0;
}