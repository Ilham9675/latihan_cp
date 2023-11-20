#include <bits/stdc++.h>
typedef long long ll;
using namespace std;




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> nilai;
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++){
        string temp1;
        int temp2;
        cin >> temp1;
        if(temp1 == "push_back"){
            cin >> temp2;
            nilai.push_back(temp2);
        }else if(temp1 == "push_front"){
            cin >> temp2;
            nilai.insert(nilai.begin(),temp2);
        }else if(temp1 == "pop_back"){
            nilai.pop_back();
        }else if(temp1 == "pop_front"){
            nilai.erase(nilai.begin());
        }
    }
    int i = 0;
    while(i < nilai.size()){
        cout << nilai.at(i) << endl;
        i++;
    }

    return 0;
}