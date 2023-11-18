#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[3][3];
    for(int i = 0;i < 3;i++){
        for (int j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 0;i < 3;i++){
        for (int j = 0; j < 3; j++){
            if(j == 0){
                printf("%d", arr[j][i]);
            }else{
                printf(" %d", arr[j][i]);
            }
        }
        printf("\n");
    }
    return 0;
}