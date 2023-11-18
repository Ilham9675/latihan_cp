#include <bits/stdc++.h>

using namespace std;

bool pengeckan(string data){
    for(int i = 0;i < data.length();i++){
        if(data[i] != '1'){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int baris,kolom;
    cin >> baris >> kolom;
    string data[baris],ganti = "";
    
    for(int i = 0; i < baris;i++){
        cin >> data[i];
        
    }
    for(int i = 0;i < kolom;i++){
        ganti += '0';
    }
    while(true){
        bool cek = false;
        int sama = 0;
        for(int i = 0;i < baris;i++){
            if(pengeckan(data[i])){
                data[i] = ganti;
                cek = true;
                sama = i;
            }
        }
        if(!cek){
            break;
        }
        for(int j = 0;j < kolom;j++){
            int kor = sama;
            while((data[kor + 1][j] != '1') && (kor + 1 < baris)){
                kor++;
            }
            for(int i = baris - 1;i >= 0;i--){
                if(sama < i){
                    continue;
                }
                if(data[i][j] == '1'){
                    data[i][j] = '0';
                    data[kor][j] = '1';
                    kor--;
                }
            }
        }
    }
    for(int i = 0; i < baris;i++){
        cout << data[i] << endl;
    }
    return 0;
}
