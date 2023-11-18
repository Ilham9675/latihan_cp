#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string data1, data2;
    cin >> data1 >> data2;
    int cek = 0;
    int i = 0,j = 0;
    if(data1.length() - 1 != data2.length()){
        cout << "Wah, tidak bisa :(";
        return 0;
    }
    while(i < data1.length() && j < data2.length()){
        if(data1[i] != data2[j] && cek == 1){
            cout << "Wah, tidak bisa :(";
            return 0;
        }else if(data1[i] != data2[j] && cek == 0){
            i++;
            cek++;
        }else{
            i++;
            j++;
        }
    }
    cout << "Tentu saja bisa!";
    return 0;
}
