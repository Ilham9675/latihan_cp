#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int N, M;
char nilai[2][25][25],bola;
bool valid[2][25][25];

void cari(int x, int y,int data,ll &jum){
    valid[data][x][y] = true;
    if(x - 1 >= 0){
        if(nilai[data][x-1][y] == bola && valid[data][x-1][y] == false){
            jum++;
            cari(x-1,y,data,jum);
        }
    }
    if(y - 1 >= 0){
        if(nilai[data][x][y - 1] == bola && valid[data][x][y - 1] == false){
            jum++;
            cari(x,y - 1,data,jum);
        }
    }
    if(x + 1 < N){
        if(nilai[data][x+1][y] == bola && valid[data][x+1][y] == false){
            jum++;
            cari(x+1,y,data,jum);
        }
    }
    if(y + 1 < M){
        if(nilai[data][x][y + 1] == bola && valid[data][x][y + 1] == false){
            jum++;
            cari(x,y + 1,data,jum);
        }
    }
}

void tandai(int x, int y,int data){
    valid[data][x][y] = true;
    nilai[data][x][y] = '.';
    if(x - 1 >= 0){
        if(nilai[data][x-1][y] == bola && valid[data][x-1][y] == false){
            tandai(x-1,y,data);
        }
    }
    if(y - 1 >= 0){
        if(nilai[data][x][y - 1] == bola && valid[data][x][y - 1] == false){
            tandai(x,y - 1,data);
        }
    }
    if(x + 1 < N){
        if(nilai[data][x+1][y] == bola && valid[data][x+1][y] == false){
            tandai(x+1,y,data);
        }
    }
    if(y + 1 < M){
        if(nilai[data][x][y + 1] == bola && valid[data][x][y + 1] == false){
            tandai(x,y + 1,data);
        }
    }
}

void tumpuk(int data){
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            if(nilai[data][j][i] == '.'){
                int x = j;
                if(x != 0){
                    while((nilai[data][x-1][i] != '.') && (x != 0)){
                        char temp = nilai[data][x][i];
                        nilai[data][x][i] = nilai[data][x - 1][i];
                        nilai[data][x - 1][i] = temp;
                        bool temp2 = valid[data][x][i];
                        valid[data][x][i] = valid[data][x - 1][i];
                        valid[data][x - 1][i] = temp2;
                        x--;
                    }
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < M;j++){
            cin >> nilai[0][i][j];
            nilai[1][i][j] = nilai[0][i][j];
            valid[0][i][j] = false;
            valid[1][i][j] = false;
        }
    }
    ll nilai_max = INT_MIN;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            ll jum;
            if(!valid[0][i][j]){
                jum = 1;
                bola = nilai[0][i][j];
                cari(i,j,0,jum);
            }else{
                continue;
            }
            if(jum == 1) continue;
            bola = nilai[1][i][j];
            tandai(i, j,1);
            tumpuk(1);

            
            ll jum2 = 0,data_akhir = INT_MIN;
            for(int i2 = 0;i2 < N;i2++){
                for(int j2 = 0;j2 < M;j2++){
                    if(!valid[1][i2][j2]){
                        jum2 = 1;
                        bola = nilai[1][i2][j2];
                        cari(i2,j2,1,jum2);
                    }else{
                        continue;
                    }
                    data_akhir = max(data_akhir, jum2);
                }
            }
            jum *= (jum - 1);
            if(jum2 != 0){
                jum += (data_akhir * (data_akhir - 1));
            }
            nilai_max = max(nilai_max, jum);
            
            for(int i3 = 0;i3 < N;i3++){
                for(int j2 = 0;j2 < M;j2++){
                    valid[1][i3][j2] = false;
                    nilai[1][i3][j2] = nilai[0][i3][j2];
                }
            }
        }
    }
    cout << nilai_max;
    
    

    return 0;
}