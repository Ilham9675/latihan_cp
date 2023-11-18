#include <bits/stdc++.h>
using namespace std;

struct koordinat{
    int x, y;
};

bool menentukan_nilai(koordinat A,koordinat B,koordinat C){
    if(B.x <= max(A.x,C.x) && B.x >= min(A.x,C.x) && B.y <= max(A.y,C.y) && B.y >= min(A.y,C.y)){
        return true;
    }
    return false;
}

int cari_nilai(koordinat A,koordinat B,koordinat C){
    int val = (B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y);
    if(val == 0){
        return 0;
    }else if(val > 0){
        return 1;
    }else{
        return 2;
    }
}


bool cari(koordinat iron_man,koordinat musuh, koordinat kor1,koordinat kor2){
    int nilai1 = cari_nilai(iron_man,musuh,kor1);
    int nilai2 = cari_nilai(iron_man,musuh,kor2);
    int nilai3 = cari_nilai(kor1,kor2,iron_man);
    int nilai4 = cari_nilai(kor1,kor2,musuh);

    if(nilai1 != nilai2 && nilai3 != nilai4){
        return true;
    }
    if(nilai1 == 0 && menentukan_nilai(iron_man,kor1,musuh)){
        return true;
    }
    if(nilai2 == 0 && menentukan_nilai(iron_man,kor2,musuh)){
        return true;
    }
    if(nilai3 == 0 && menentukan_nilai(kor1,iron_man,kor2)){
        return true;
    }
    if(nilai4 == 0 && menentukan_nilai(kor1,musuh,kor2)){
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int jumlah,x,y,sum = 0;
    cin >> x >> y;
    koordinat iron_man = {x,y};
    cin >> jumlah;
    vector<koordinat> musuh,kor1,kor2;
    for(int i = 0; i < jumlah;i++){
        cin >> x >> y;
        musuh.push_back({x,y});
    }
    cin >> jumlah;
    for(int i = 0;i < jumlah;i++){
        cin >> x >> y;
        kor1.push_back({x,y});
        cin >> x >> y;
        kor2.push_back({x,y});
    }
    for(auto ms:musuh){
        bool cek = false;
        for(int i = 0; i < kor1.size();i++){
            if(cari(iron_man,ms,kor1[i],kor2[i])){
                cek = true;
            }
        }
        if(!cek){
            sum++;
        }
    }
    cout << sum << "\n";
    return 0;
}