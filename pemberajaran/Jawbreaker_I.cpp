#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N, M,bola,jum;
ll nilai[25][25];
ll valid[25][25];

void cari(int x, int y){
    valid[x][y] = 1;
    if(x - 1 >= 0){
        if(nilai[x-1][y] == bola && valid[x-1][y] == 0){
            jum++;
            cari(x-1,y);
        }
    }
    if(y - 1 >= 0){
        if(nilai[x][y - 1] == bola && valid[x][y - 1] == 0){
            jum++;
            cari(x,y - 1);
        }
    }
    if(x + 1 < N){
        if(nilai[x+1][y] == bola && valid[x+1][y] == 0){
            jum++;
            cari(x+1,y);
        }
    }
    if(y + 1 < M){
        if(nilai[x][y + 1] == bola && valid[x][y + 1] == 0){
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
            valid[i][j] = 0;
        }
    }
    int x,y;
    cin >> x >> y;
    jum = 1;
    bola = nilai[x][y];
    cari(x,y);
    cout << jum * (jum - 1);
    
    

    return 0;
}