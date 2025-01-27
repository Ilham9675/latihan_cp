#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

ll kor[1001][1001];
int n;
void cek(int l,int r){
    if(l+1 <= r){
        if(r-1 >= l){
            kor[l+1][r] = kor[l][r] + kor[l+1][r-1];
        }else{
            kor[l+1][r] = kor[l][r];
        }
        //cout << l+1 << " " << r << " " << kor[l+1][r] << endl;
        cek(l+1,r);
    }
    if(r+1 <= n){
        if(l-1 >= 0){
            kor[l][r+1] = kor[l][r] + kor[l-1][l+1];
        }else{
            kor[l][r+1] = kor[l][r];
        }
        //cek(l,r+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int total = 1;
    int indek = 0;
    
    memset(kor, 0, sizeof(kor));
    kor[0][0] = 1;
    for(int i = 0;i <= n;i++){
        cek(0,i);
    }
    cout << kor[n][n] << endl;

    return 0;
}