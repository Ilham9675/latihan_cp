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

vector<pii> nilai;
bool cek[501];
ll range[501];
int panjang[501][501];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int V,E;
        cin >> V >> E;
        int x,y,z;
        for(int i = 1;i <= E;i++){
            cin >> x >> y >> z;
            nilai.pb({x,y});
            panjang[x][y] = z;
        }
        for(int i = 0;i < V;i++){
            range[i] = LLONG_MAX;
            cek[i] = false;
        }
        range[0] = 0;

        for(int i = 0;i < V;i++){
            for(auto j : nilai){
                if(range[j.first] < LLONG_MAX){
                    range[j.second] = min(range[j.second],range[j.first]+panjang[j.first][j.second]);

                }
            }
        }

        bool ini = true;
        for(auto j : nilai){
            if(range[j.first] < LLONG_MAX){
                if(range[j.second] > (range[j.first] + panjang[j.first][j.second])){
                    cout << "Pak Dengklek tidak mau pulang" << endl;
                    ini = false;
                    break;
                }
            }
        }
        if(ini){
            if(range[V-1] == LLONG_MAX){
                cout << "Tidak ada jalan" << endl;
            }else{
                cout << range[V-1] << endl;
            }
        }
        while(!nilai.empty()){
            nilai.pop_back();
        }
    }
    return 0;
}