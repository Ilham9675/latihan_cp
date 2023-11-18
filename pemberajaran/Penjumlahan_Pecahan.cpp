#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll fpb(ll a, ll b){
    if(b == 0){
        return a;
    }else{
        return fpb(b, a%b);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d;
    cin >> a >> b >> c >>d;
    ll hasil1 = b * d;
    ll hasil2 = ((hasil1/b) * a) + ((hasil1 / d) * c);
    cout << hasil2 / fpb(hasil1,hasil2) << " " << hasil1 / fpb(hasil1,hasil2) << endl;
    return 0;
}
