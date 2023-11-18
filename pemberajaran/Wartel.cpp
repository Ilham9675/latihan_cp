#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N,Q;
    cin >> N >> Q;
    map<string,string> data;
    for(int i = 0;i < N;i++){
        string temp1,temp2;
        cin >> temp1 >> temp2;
        data[temp1] = temp2;
    }

    for(int i = 0;i < Q;i++){
        string cari;
        cin >> cari;
        auto temp = data.find(cari);
        if(temp != data.end()){
            cout << temp->second << endl;
        }else{
            cout << "NIHIL" << endl; 
        }
    }
    return 0;
}