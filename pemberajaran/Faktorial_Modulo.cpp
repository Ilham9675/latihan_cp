#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll fatorial(ll a ,ll b){
    if(a == 1){
        return 1;
    }else{
        return a * fatorial(a-1,b) % b;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a,b;
    while(cin >> a){
        cin >> b;
        cout << fatorial(a,b) % b << endl;
    }
    

    return 0;
}