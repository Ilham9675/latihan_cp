#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N, M,bola,jum;
ll nilai[25][25];
bool valid[25][25];

void cari(int x, int y){
    valid[x][y] = true;
    if(x - 1 >= 0){
        if(nilai[x-1][y] == bola && valid[x-1][y] == false){
            jum++;
            cari(x-1,y);
        }
    }
    if(y - 1 >= 0){
        if(nilai[x][y - 1] == bola && valid[x][y - 1] == false){
            jum++;
            cari(x,y - 1);
        }
    }
    if(x + 1 < N){
        if(nilai[x+1][y] == bola && valid[x+1][y] == false){
            jum++;
            cari(x+1,y);
        }
    }
    if(y + 1 < M){
        if(nilai[x][y + 1] == bola && valid[x][y + 1] == false){
            jum++;
            cari(x,y + 1);
        }
    }
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < M;j++){
            cin >> nilai[i][j];
            valid[i][j] = false;
        }
    }
    ll nilai_max = INT_MIN;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(!valid[i][j]){
                jum = 1;
                bola = nilai[i][j];
                cari(i,j);
            }else{
                continue;
            }
            nilai_max = max(nilai_max,jum);
        }
    }
    cout << nilai_max * (nilai_max - 1);
    

    return 0;
}