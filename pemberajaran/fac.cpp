#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    float A;
    scanf("%f",&A);
    int B = trunc(A);
    if(A == B){
        printf("%d %d",B, B);
    }else if(A >= 0){
        printf("%d %d",B, B + 1);
    }else{
        printf("%d %d",B - 1, B);
    }
    
    return 0;
}