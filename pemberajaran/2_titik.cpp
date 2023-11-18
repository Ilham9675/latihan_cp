#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A,B,C,ter = 0;
    scanf("%d %d %d",&A,&B,&C);
    int mat1[A][B],mat2[B][C];
    for(int i = 0;i < A;i++){
        for(int j = 0;j < B;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    for(int i = 0;i < B;i++){
        for(int j = 0;j < C;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    int mat3[A][C];
    for(int i = 0;i < A;i++){
        for(int j = 0;j < C;j++){
            for(int k = 0;k < B;k++){
                if(k == 0){
                    mat3[i][j] = mat1[i][k] * mat2[k][j];
                }else{
                    mat3[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    }

    for(int i = 0;i < A;i++){
        for(int j = 0;j < C;j++){
            printf("%d",mat3[i][j]);
            if(j < C - 1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
    
    return 0;
}