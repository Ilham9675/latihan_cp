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
    int nilai[3];
    for(int i = 0;i < 3;i++){
        cin >> nilai[i];
    }
    sort(nilai,nilai+3);
    if(nilai[2]%4 == 0 && (nilai[1] + nilai[0]) % 3 == 0 && nilai[2]/4==(nilai[0]+nilai[1])/3){
        cout << "YA";
    }else{
        cout << "TIDAK";
    }

    return 0;
}