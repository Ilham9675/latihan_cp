#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    int data[N];
    for(int i = 0;i < N;i++){
        
        cin >> data[i];
    }
    sort(data,data+N);
    cout << data[K-1];
    return 0;
}