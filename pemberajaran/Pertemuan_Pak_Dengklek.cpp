#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool cari(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }else{
        return a.length() < b.length();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int jum;
    cin >> jum;

    string data[jum];

    for(int i = 0;i < jum;i++){
        cin >> data[i];
    }

    sort(data,data + jum,cari);


    for(int i = 0;i < jum;i++){
        cout << data[i] << endl;
    }
    return 0;
}