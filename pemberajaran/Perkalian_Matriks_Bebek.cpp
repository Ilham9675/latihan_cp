#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

ll MOD = 26101991;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    ll nilai[n+2];
    for(int i = 1;i <= n+1;i++){
        cin >> nilai[i];
    }
    ll temp1[n+1][n+1],temp2[n+1][n+1],temp3[n+1][n+1];
    memset(temp2,0,sizeof(temp2));
    memset(temp3,0,sizeof(temp3));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n-i+1;j++){
            int L = j,R = j+i-1;
            if(L == R){
                temp1[L][R] = 0;
                temp2[L][R] = 1;
                temp3[L][R] = 1;
            }else{
                temp1[L][R] = 1e14;
                for(int k = L;k < R;k++){
                    ll temp = temp1[L][k] + temp1[k+1][R] + nilai[L]*nilai[k+1]*nilai[R+1];
                    if(temp <= temp1[L][R]){
                        if(temp < temp1[L][R]){
                            temp1[L][R] = temp;
                            temp2[L][R] = (temp2[L][k] * temp2[k+1][R]) % MOD;
                        }else if(temp == temp1[L][R]){
                            temp2[L][R] += (temp2[L][k] * temp2[k+1][R]) % MOD;
                            temp2[L][R] %= MOD;
                        }
                    }
                    temp3[L][R] += (temp3[L][k] * temp3[k+1][R]) % MOD;
                    temp3[L][R] %= MOD;

                }
            }
        }
    }
    int jenis;
    cin >> jenis;
    if(jenis == 1){
        cout << temp1[1][n];
    }else if(jenis == 2){
        cout << temp2[1][n];
    }else{
        cout << temp3[1][n];
    }

    return 0;
}