#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        string S;
        cin >> S;
        int panjang = S.length();
        int nilai[panjang][panjang];
        memset(nilai,0,sizeof(nilai));
        for(int j = 0;j < panjang;j++){
            nilai[j][j] = 1;
        }
        for(int j = 2;j <= panjang;j++){
            for(int k = 0;k < panjang-j+1;k++){
                int L = k, R= k+j-1;
                if(S[L] == S[R]){
                    nilai[L][R] = nilai[L+1][R-1] + 2;
                }else{
                    nilai[L][R] = max(nilai[L+1][R],nilai[L][R-1]);
                }
            }
        }
        cout << nilai[0][panjang-1] << endl;
    }

    return 0;
}