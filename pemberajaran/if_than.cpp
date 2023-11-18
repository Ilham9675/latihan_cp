#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A;
    scanf("%d",&A);
    if(A / 10000 != 0){
        printf("puluhribuan");
    }else if (A / 1000 != 0){
        printf("ribuan");
    }else if(A / 100 != 0){
        printf("ratusan");
    }else if(A / 10 != 0){
        printf("puluhan");
    }else{
        printf("satuan");
    }
    return 0;
}