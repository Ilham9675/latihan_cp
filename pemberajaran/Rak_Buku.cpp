#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue <int> data;
    int n,b,temp,jum = 0;
    cin >> n >> b;
    for(int i = 0;i < n;i++){
        cin >> temp;
        data.push(temp);
    }
    while(b > 0){
        b -= data.top();
        jum++;
        data.pop();
    }
    cout << jum;

    return 0;
}