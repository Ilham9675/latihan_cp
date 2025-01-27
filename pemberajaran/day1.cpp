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
    
    int n,m;
    int jum = 0;
    string nilai;
    string huruf[10] = {"","one", "two", "three", "four", "five", "six","seven", "eight","nine"};
    char hasil[10] = {'0','1','2','3','4','5','6','7','8','9'};
    while(cin >> nilai){
        if(nilai == "end"){
            break;
        }
        char awal = ' ',akhir = ' ';
        for(int i = 0;i < nilai.size();i++){
            if(nilai[i] >= '0' && nilai[i] <= '9'){
                if(awal == ' '){
                    awal = nilai[i];
                    akhir = nilai[i];
                }else{
                    akhir = nilai[i];
                }
            }else{
                for(int j = 1;j < 10;j++){
                    int jarak = huruf[j].size();
                    string temp = nilai.substr(i,jarak);
                    if(huruf[j] == temp){
                        if(awal == ' '){
                            awal = hasil[j];
                            akhir = hasil[j];
                        }else{
                            akhir = hasil[j];
                        }
                        break;
                    }
                }
            }
        }
        string gab = "";
        gab += awal;
        gab += akhir;
        
        jum += stoi(gab);
    }
    cout << jum;

    return 0;
}