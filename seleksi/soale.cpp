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

int kotak[6][6];
bool cek[5][5];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int angka = 1;
    for(int i = 0;i <=5;i++){
        for(int j = 0;j <=5;j++){
            if(i == 0 || j == 0){
                kotak[i][j] = 0;
            }else{
                kotak[i][j] = angka;
                angka++;
            }
        }
    }
    int n;
    cin >> n;
    while(n--){
        char tunjuk;
        int nilai;
        cin >> tunjuk >> nilai;
        if(tunjuk == 'k'){
            for(int i = 1;i <= 2;i++){
                int temp = kotak[i][nilai];
                kotak[i][nilai] = kotak[6-i][nilai];
                kotak[6-i][nilai] = temp; 
            }
        }else{
            for(int i = 1;i <= 2;i++){
                int temp = kotak[nilai][i];
                kotak[nilai][i] = kotak[nilai][6-i];
                kotak[nilai][6-i] = temp; 
            }
        }
    }
    memset(cek,0,sizeof(cek));
    cin >> n;
    while(n--){
        int cari;
        cin >> cari;
        int i = 1;
        int indi = 0;
        while (i <= 5){
            int j = 1;
            while(j <= 5){
                if(cari == kotak[i][j]){
                    //cout << "*";
                    cek[i-1][j-1] = 1;
                    indi = 1;
                    break;
                }
                j++;
            }
            if(indi == 1){
                break;
            }
            i++;
        }
    }
    
    int jum = 0;
    for(int i = 0;i < 5;i++){
        if(cek[i][0] == 1 && cek[i][1] == 1 && cek[i][2] == 1 && cek[i][3] == 1 && cek[i][4] == 1){
            jum++;
        }
    }
    for(int i = 0;i < 5;i++){
        if(cek[0][i] == 1 && cek[1][i] == 1 && cek[2][i] == 1 && cek[3][i] == 1 && cek[4][i] == 1){
            jum++;
        }
    }
    if(cek[0][0] == 1 && cek[1][1] == 1 && cek[2][2] == 1 && cek[3][3] == 1 && cek[4][4] == 1){
        jum++;
    }
    if(cek[4][0] == 1 && cek[3][1] == 1 && cek[2][2] == 1 && cek[1][3] == 1 && cek[0][4] == 1){
        jum++;
    }
    cout << jum;
    return 0;
}