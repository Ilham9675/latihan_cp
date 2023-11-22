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
    int i = 1,cek = 1;
    while(i <= n/2){
        if(n % i == 0){
            cek++;
        }
        if(cek > 5){
            break;
        }
        i++;
    }
    if(cek == 5){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}