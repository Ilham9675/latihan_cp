#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int ,int> data[n];
    for(int i = 0;i < n;i++){
        cin >> data[i].second >> data[i].first;
        data[i].first += data[i].second - 1;
    }
    sort(data, data + n);
    int jum = 1;
    int mulai = data[0].first;
    for(int i = 1;i < n;i++){
        if(data[i].second > mulai){
            mulai = data[i].first;
            jum++;
        }
    }
    cout << jum;
    return 0;
}