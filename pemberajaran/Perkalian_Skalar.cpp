#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long data1[n],data2[n];
    for(int i = 0;i < n;i++){
        cin >> data1[i];
    }
    sort(data1, data1+n,greater<int>());
    for(int i = 0;i < n;i++){
        cin >> data2[i];
    }
    sort(data2, data2+n);
    int jum = 0;
    for(int i = 0;i < n;i++){
        jum += data1[i] * data2[i];
    }
    cout << jum;
    return 0;
}