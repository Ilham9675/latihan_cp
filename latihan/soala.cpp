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
char nilai[1000][1000];
bool tes[1000][1000];
int m,n;
void cek(int i,int j,int &jum){
    jum+=1;
    tes[i][j] = 1;
    if(i - 1 >= 0 && tes[i-1][j] != 1 && nilai[i-1][j] == '1'){
        cek(i-1,j,jum);
    }
    if(i + 1 < n && tes[i+1][j] != 1 && nilai[i+1][j] == '1'){
        cek(i+1,j,jum);
    }
    if(j + 1 < m && tes[i][j+1] != 1 && nilai[i][j+1] == '1'){
        cek(i,j+1,jum);
    }
    if(j - 1 >= 0 && tes[i][j-1] != 1 && nilai[i][j-1] == '1'){
        cek(i,j-1,jum);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> nilai[i][j];
        }
    }
    memset(tes,0,sizeof(tes));
    int jum = INT_MIN;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int sem = 0; 
            if(nilai[i][j] == '1' && tes[i][j] == 0){
                cek(i,j,sem);
                jum = max(jum,sem);
            }

        }
    }
    cout << jum;

    return 0;
}