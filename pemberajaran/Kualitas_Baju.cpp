#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    float data[N];
    for(int i = 0; i < N;i++){
        cin >> data[i];
    }

    sort(data,data+N);
    if(N % 2 == 1){
        printf("%.1f",data[N/2]);
    }else{
        printf("%.1f",(data[N/2] + data[N/2 - 1]) / 2);
    }
    return 0;
}