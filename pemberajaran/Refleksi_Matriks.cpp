#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N,M;
    cin >> N >> M;
    ll data1[N][M];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin >> data1[i][j];
        }
    }

    ll A,B;
    cin >> A >> B;
    ll data2[A][B];
    for(int i = 0;i < A;i++){
        for(int j = 0;j < B;j++){
            cin >> data2[i][j];
        }
    }

    if(A != N || B != M){
        cout << "tidak identik";
        return 0;
    }
    ll cek = 0;
    for(int i = 0;i < A;i++){
        for(int j = 0;j < B;j++){
            if(data1[i][j] != data2[i][j]){
                cek++;
            }
        }
    }
    if(cek == 0){
        cout << "identik";
        return 0;
    }

    cek = 0;
    for(int i = 0;i < A;i++){
        for(int j = 0;j < B;j++){
            if(data1[i][j] != data2[(A - 1) - i][j]){
                cek++;
            }
        }
    }
    if(cek == 0){
        cout << "horisontal";
        return 0;
    }

    cek = 0;
    for(int i = 0;i < A;i++){
        for(int j = 0;j < B;j++){
            if(data1[i][j] != data2[i][(B - 1) - j]){
                cek++;
            }
        }
    }
    if(cek == 0){
        cout << "vertikal";
        return 0;
    }


    cek = 0;
    for(int i = 0;i < A;i++){
        for(int j = 0;j < B;j++){
            if(data1[i][j] != data2[j][i]){
                cek++;
            }
        }
    }
    if(cek == 0){
        cout << "diagonal kanan bawah";
        return 0;
    }

    cek = 0;
    for(int i = 0;i < A;i++){
        for(int j = 0;j < B;j++){
            if(data1[i][j] != data2[(B - 1) - j][(A - 1) - i]){
                cek++;
            }
        }
    }
    if(cek == 0){
        cout << "diagonal kiri bawah";
    }else{
        cout << "tidak identik";
    }

    return 0;
}