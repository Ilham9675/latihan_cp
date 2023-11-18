#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int data[N];
    for(int i = 0;i < N;i++){
        scanf("%d",&data[i]);
    }
    int mx = INT_MIN,ans = INT_MIN;
    for(int i = 0;i < N;i++){
        if(i >= M){
            if(mx < data[i-M]){
                mx = data[i-M];
            }
            if(data[i] + mx > data[i]){
                data[i] = data[i] + mx;
            }
        }
        if(ans < data[i]){
            ans = data[i];
        }
    }
    printf("\n%d", ans);
    return 0;
}