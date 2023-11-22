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
    
    int v,h,n;
    cin >> v >> h >> n;
    int tabel[v+2][h+2];
    memset(tabel,0,sizeof(tabel));
    for(int i = 1;i <= n;i++){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1;j <= x2;j++){
            for(int k = y1;k <= y2;k++){
                tabel[j][k] = 1;
            }
        }
    }

    ll temp[v+1][h+1];
    memset(temp,0,sizeof(temp));
    for(int i = v-1;i >= 0;i--){
        for(int j = 1;j <= h;j++){
            if(tabel[i][j] == 0){
                if(tabel[i+1][j]){
                    int kolom = j;
                    while(tabel[i+1][kolom]){
                        kolom--;
                    }
                    temp[i][j] += temp[i+1][kolom];
                    kolom = j;
                    while(tabel[i+1][kolom]){
                        kolom++;
                    }
                    temp[i][j] += temp[i+1][kolom];
                    temp[i][j]++;
                }else{
                    temp[i][j] = temp[i+1][j];
                }
            }
        }
    }
    ll hasil = -1;
    for(int i = 1;i <= h;i++){
        hasil = max(hasil,temp[0][i]);
    }
    cout << hasil;

    return 0;
}