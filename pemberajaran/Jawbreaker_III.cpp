#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll N, M,jum;
char nilai[25][25],bola;
bool valid[25][25];
bool validasi[25][25];

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

void tandai(int x, int y){
    validasi[x][y] = true;
    nilai[x][y] = '.';
    if(x - 1 >= 0){
        if(nilai[x-1][y] == bola && validasi[x-1][y] == false){
            tandai(x-1,y);
        }
    }
    if(y - 1 >= 0){
        if(nilai[x][y - 1] == bola && validasi[x][y - 1] == false){
            tandai(x,y - 1);
        }
    }
    if(x + 1 < N){
        if(nilai[x+1][y] == bola && validasi[x+1][y] == false){
            tandai(x+1,y);
        }
    }
    if(y + 1 < M){
        if(nilai[x][y + 1] == bola && validasi[x][y + 1] == false){
            tandai(x,y + 1);
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
            validasi[i][j] = false;
        }
    }
    ll nilai_max = INT_MIN;
    int x,y;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(!valid[i][j]){
                jum = 1;
                bola = nilai[i][j];
                cari(i,j);
            }else{
                continue;
            }
            if(nilai_max < jum){
                nilai_max = jum;
                x = i;
                y = j;
            }
        }
    }
    bola = nilai[x][y];
    tandai(x, y);

    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            if(nilai[j][i] == '.'){
                int x = j;
                if(x != 0){
                    while((nilai[x-1][i] != '.') && (x != 0)){
                        char temp = nilai[x][i];
                        nilai[x][i] = nilai[x - 1][i];
                        nilai[x - 1][i] = temp;
                        x--;
                    }
                }
            }
        }
    }

    for(int i = 0; i < N;i++){
        for(int j = 0; j < M;j++){
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}