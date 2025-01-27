#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,indek = 0;
    int nilai[27];
    memset(nilai, 0, sizeof(nilai));
    string al = "aABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string a;
    cin >> n >> a;
    for(int i = 0;i < n;i++){
        for(int j = 1;j <= 26;j++){
            if(al.substr(j,1) == a.substr(i,1)){
                nilai[j] += 1;
                break;
            }
        }
    }
    sort(nilai,nilai+27,greater<int>());
    int cek1 = nilai[0], cek2 = nilai[1],cek3 = nilai[2];
    if(cek3 == 0){
        cout << -1;
    }else{
        if(cek2 > cek3){
            cout << cek3 *3 +2;
        }else{
            if(cek1 > cek2){
                cout << cek3 *3 +1;
            }else{
                cout << cek3 * 3;
            }
        }
    }




    return 0;
}