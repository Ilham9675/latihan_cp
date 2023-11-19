#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll jum,skor[5] = {0},temp[5] = {0};
bool hasil = false;
void cek(int a,int b){
    int c = a,d = b;
    if(c >= jum-2){
        bool sama = true;
        for(int i = 0;i < jum;i++){
            if(skor[i] != temp[i]){
                sama = false;
                break;
            }
        }
        if(sama){
            hasil = true;
        }
    }else{
        if(d == jum-1){
            c++;
            d = c + 1;
        }else{
            d++;
        }
        temp[c] += 3;
        cek(c,d);
        temp[c] -= 3;

        temp[d] += 3;
        cek(c,d);
        temp[d] -= 3;

        temp[c] += 1;
        temp[d] += 1;
        cek(c,d);
        temp[c] -= 1;
        temp[d] -= 1;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> jum;
        for(int i = 0; i < jum;i++){
            cin >> skor[i];
        }
        hasil = false;
        if(jum == 2){
            if(skor[0] + skor[1] == 3 || skor[0] + skor[1] == 2 || skor[0] + skor[1] == 0){
                hasil = true;
            }
        }else{
            cek(0,0);
        }
        
        if(hasil){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
    

    return 0;
}