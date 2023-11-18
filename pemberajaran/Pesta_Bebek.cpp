#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    set<string> data;
    for(int i = 0; i < N;i++){
        string temp;
        cin >> temp;
        data.insert(temp);
        auto posisi = distance(data.begin(), data.find(temp)) + 1;
        cout << posisi << endl;
    }

    return 0;
}