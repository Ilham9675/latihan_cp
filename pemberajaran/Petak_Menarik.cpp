#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N,M,K;
    cin >> N >> M >> K;
    ll data[N][M];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> data[i][j];
        }
    }
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            ll jum = 1;
            if(i > 0) jum *= data[j][i - 1];
            if(i < M - 1) jum *= data[j][i + 1];
            if(j > 0) jum *= data[j - 1][i];
            if(j < N - 1) jum *= data[j + 1][i];
            
            if(jum == K){
                cout << j + 1 << " " << i + 1 << endl;
                return 0;
            } 
            
        }
    }
    cout << "0 0";
    return 0;
}