#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<pair<int,string>> v;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        int a = stoi(s);
        v.push_back({abs(a-x),s});
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        if(i.first == v[0].first) cout << i.second << "\n";
    }
    return 0;
}