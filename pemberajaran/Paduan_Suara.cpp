#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int M,N;
int batas[50], nilai[10101];
bool cek;



void cari(int pos, int l, int r,int indek){
    if(pos>N){
        cek = true;
        return;
    }
    if(pos>1){
        if(nilai[pos] == nilai[pos-1]){
            return;
        }
        batas[indek] = nilai[pos];
    }
    if(l>0){
        cari(pos+N/M+1,l-1,r,indek+1);
        if(cek){
            return;
        }
    }
    if(r>0){
        cari(pos+N/M,l,r-1,indek+1);
        if(cek){
            return;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1;i <= N;i++){
        cin >> nilai[i];
    }
    sort(nilai+1,nilai+N+1);

    cin >> M;

    int p = N%M;
    int q = M-p;
    cari(1,p,q,0);
    for(int i = 1;i < M;i++){
        cout << batas[i] << " ";
    }

    return 0;
}