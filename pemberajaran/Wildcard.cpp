#include <bits/stdc++.h>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string data1,data2;
    cin >> data1;
    int batas = data1.find('*');
    string kiri = data1.substr(0,batas);
    string kanan = data1.substr(batas+1,data1.length());
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> data2;
        if(data2.length() >= data1.length() - 1){
            if((kiri == data2.substr(0,kiri.length())) && (kanan == data2.substr(data2.length() - kanan.length(),data2.length()))){
                cout << data2 << endl;
            }
        }
    }

    return 0;
}
