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
    string nilai[1000];
    int i = 0;
    ll jum = 0;
    bool in = 0;
    do{
        string sem;
        cin >> sem;
        if(sem == "end"){
            break;
        }else{
            nilai[i] = sem;
            i++;
        }
    }while(true);
    for(int k = 0;k < i;k++){
        string gab = "";
        string gab2 = "";
        bool cek = 0;
        int x = 0,y = 0;
        for(int j = 0;j < nilai[k].size();j++){
            if(nilai[k][j] >= '0' && nilai[k][j] <= '9'){
                gab += nilai[k][j];
                nilai[k][j] = '.';
                if(j > 0){
                    if(nilai[k][j-1] == '*' && !(nilai[k][j-1] >= '0' && nilai[k][j-1] <= '9')){
                        x = k;
                        y = j-1;
                        cek = 1;
                    }
                }
                if(j < nilai[k].size()-1 ){
                    if(nilai[k][j+1] == '*' && !(nilai[k][j+1] >= '0' && nilai[k][j+1] <= '9')){
                        x = k;
                        y = j+1;
                        cek = 1;
                    }
                }
                if(k > 0){
                    if(nilai[k-1][j] == '*' && !(nilai[k-1][j] >= '0' && nilai[k-1][j] <= '9')){
                        x = k-1;
                        y = j;
                        cek = 1;
                    }
                }
                if(k < i-1){
                    if(nilai[k+1][j] == '*' && !(nilai[k+1][j] >= '0' && nilai[k+1][j] <= '9')){
                        x = k+1;
                        y = j;
                        cek = 1;
                    }
                }
                if(j > 0 && k > 0){
                    if(nilai[k-1][j-1] == '*' && !(nilai[k-1][j-1] >= '0' && nilai[k-1][j-1] <= '9')){
                        x = k-1;
                        y = j-1;
                        cek = 1;
                    }
                }
                if(j > 0 && k < i-1){
                    if(nilai[k+1][j-1] == '*' && !(nilai[k+1][j-1] >= '0' && nilai[k+1][j-1] <= '9')){
                        x = k+1;
                        y = j-1;
                        cek = 1;
                    }
                }
                if(j < nilai[k].size()-1 && k > 0){
                    if(nilai[k-1][j+1] == '*' && !(nilai[k-1][j+1] >= '0' && nilai[k-1][j+1] <= '9')){
                        x = k-1;
                        y = j+1;
                        cek = 1;
                    }
                }
                if(j < nilai[k].size()-1 && k < i-1){
                    if(nilai[k+1][j+1] == '*' && !(nilai[k+1][j+1] >= '0' && nilai[k+1][j+1] <= '9')){
                        x = k+1;
                        y = j+1;
                        cek = 1;
                    }
                }
                //cout << k << " "<< cek << endl;
            }else{
                bool cek2 = 0;
                if(y > 0){
                    if(nilai[x][y-1] >= '0' && nilai[x][y-1] <= '9'){
                        cek2 = 1;
                        int cp1 = x;
                        int cp2 = y-1;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            cp2--;
                        }
                        cp2++;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            gab2 += nilai[cp1][cp2];
                            nilai[cp1][cp2] = '.';
                            cp2++;
                        }
                    }
                }
                if(y < nilai[x].size()-1){
                    if(nilai[x][y+1] >= '0' && nilai[x][y+1] <= '9'){
                        cek2 = 1;
                        int cp1 = x;
                        int cp2 = y+1;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            cp2--;
                        }
                        cp2++;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            gab2 += nilai[cp1][cp2];
                            nilai[cp1][cp2] = '.';
                            cp2++;
                        }
                    }
                }
                if(x > 0){
                    if(nilai[x-1][y] >= '0' && nilai[x-1][y] <= '9'){
                        cek2 = 1;
                        int cp1 = x-1;
                        int cp2 = y;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            cp2--;
                        }
                        cp2++;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            gab2 += nilai[cp1][cp2];
                            nilai[cp1][cp2] = '.';
                            cp2++;
                        }
                    }
                }
                if(x < i-1){
                    if(nilai[x+1][y] >= '0' && nilai[x+1][y] <= '9'){
                        cek2 = 1;
                        int cp1 = x+1;
                        int cp2 = y;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            cp2--;
                        }
                        cp2++;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            gab2 += nilai[cp1][cp2];
                            nilai[cp1][cp2] = '.';
                            cp2++;
                        }
                    }
                }
                if(y > 0 && x > 0){
                    if(nilai[x-1][y-1] >= '0' && nilai[x-1][y-1] <= '9'){
                        cek2 = 1;
                        int cp1 = x-1;
                        int cp2 = y-1;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            cp2--;
                        }
                        cp2++;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            gab2 += nilai[cp1][cp2];
                            nilai[cp1][cp2] = '.';
                            cp2++;
                        }
                    }
                }
                if(y > 0 && x < i-1){
                    if(nilai[x+1][y-1] >= '0' && nilai[x+1][y-1] <= '9'){
                        cek2 = 1;
                        int cp1 = x+1;
                        int cp2 = y-1;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            cp2--;
                        }
                        cp2++;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            gab2 += nilai[cp1][cp2];
                            nilai[cp1][cp2] = '.';
                            cp2++;
                        }
                    }
                }
                if(y < nilai[x].size()-1 && x > 0){
                    if(nilai[x-1][y+1] >= '0' && nilai[x-1][y+1] <= '9'){
                        cek2 = 1;
                        int cp1 = x-1;
                        int cp2 = y+1;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            cp2--;
                        }
                        cp2++;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            gab2 += nilai[cp1][cp2];
                            nilai[cp1][cp2] = '.';
                            cp2++;
                        }
                    }
                }
                if(y < nilai[x].size()-1 && x < i-1){
                    if(nilai[x+1][y+1] >= '0' && nilai[x+1][y+1] <= '9'){
                        cek2 = 1;
                        int cp1 = x+1;
                        int cp2 = y+1;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            cp2--;
                        }
                        cp2++;
                        while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                            gab2 += nilai[cp1][cp2];
                            nilai[cp1][cp2] = '.';
                            cp2++;
                        }
                    }
                }
                if(gab != ""){
                    if(cek == 1 && cek2 == 0){
                        //jum += stoi(gab);
                    }else if(cek == 1 && cek2 == 1){
                        //cout << gab2 << endl;
                        jum += (stoi(gab) * stoi(gab2));
                    }
                }
                cek = 0;
                gab = "";
                gab2 = "";
                cek2 = 0;
            }
        }
        bool cek2 = 0;
        if(y > 0){
            if(nilai[x][y-1] >= '0' && nilai[x][y-1] <= '9'){
                cek2 = 1;
                int cp1 = x;
                int cp2 = y-1;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    cp2--;
                }
                cp2++;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    gab2 += nilai[cp1][cp2];
                    nilai[cp1][cp2] = '.';
                    cp2++;
                }
            }
        }
        if(y < nilai[x].size()-1){
            if(nilai[x][y+1] >= '0' && nilai[x][y+1] <= '9'){
                cek2 = 1;
                int cp1 = x;
                int cp2 = y+1;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    cp2--;
                }
                cp2++;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    gab2 += nilai[cp1][cp2];
                    nilai[cp1][cp2] = '.';
                    cp2++;
                }
            }
        }
        if(x > 0){
            if(nilai[x-1][y] >= '0' && nilai[x-1][y] <= '9'){
                cek2 = 1;
                int cp1 = x-1;
                int cp2 = y;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    cp2--;
                }
                cp2++;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    gab2 += nilai[cp1][cp2];
                    nilai[cp1][cp2] = '.';
                    cp2++;
                }
            }
        }
        if(x < i-1){
            if(nilai[x+1][y] >= '0' && nilai[x+1][y] <= '9'){
                cek2 = 1;
                int cp1 = x+1;
                int cp2 = y;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    cp2--;
                }
                cp2++;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    gab2 += nilai[cp1][cp2];
                    nilai[cp1][cp2] = '.';
                    cp2++;
                }
            }
        }
        if(y > 0 && x > 0){
            if(nilai[x-1][y-1] >= '0' && nilai[x-1][y-1] <= '9'){
                cek2 = 1;
                int cp1 = x-1;
                int cp2 = y-1;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    cp2--;
                }
                cp2++;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    gab2 += nilai[cp1][cp2];
                    nilai[cp1][cp2] = '.';
                    cp2++;
                }
            }
        }
        if(y > 0 && x < i-1){
            if(nilai[x+1][y-1] >= '0' && nilai[x+1][y-1] <= '9'){
                cek2 = 1;
                int cp1 = x+1;
                int cp2 = y-1;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    cp2--;
                }
                cp2++;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    gab2 += nilai[cp1][cp2];
                    nilai[cp1][cp2] = '.';
                    cp2++;
                }
            }
        }
        if(y < nilai[x].size()-1 && x > 0){
            if(nilai[x-1][y+1] >= '0' && nilai[x-1][y+1] <= '9'){
                cek2 = 1;
                int cp1 = x-1;
                int cp2 = y+1;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    cp2--;
                }
                cp2++;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    gab2 += nilai[cp1][cp2];
                    nilai[cp1][cp2] = '.';
                    cp2++;
                }
            }
        }
        if(y < nilai[x].size()-1 && x < i-1){
            if(nilai[x+1][y+1] >= '0' && nilai[x+1][y+1] <= '9'){
                cek2 = 1;
                int cp1 = x+1;
                int cp2 = y+1;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    cp2--;
                }
                cp2++;
                while(nilai[cp1][cp2] >= '0' && nilai[cp1][cp2] <= '9'){
                    gab2 += nilai[cp1][cp2];
                    nilai[cp1][cp2] = '.';
                    cp2++;
                }
            }
        }
        if(gab != ""){
            if(cek == 1 && cek2 == 0){
                //jum += stoi(gab);
            }else if(cek == 1 && cek2 == 1){
                jum += (stoi(gab) * stoi(gab2));
            }
        }
        cek = 0;
        cek2 = 0;
        gab = "";
        gab2 = "";
    }
    cout << jum;

    return 0;
}