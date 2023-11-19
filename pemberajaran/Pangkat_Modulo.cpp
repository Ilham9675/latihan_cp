#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

ll fpb(ll a, ll b){
    if(b == 0){
        return a;
    }else{
        return fpb(b, a%b);
    }
}

ll pow_pangkat(ll x,ll y,ll mod){
    if(y == 0){
        return 1;
    }else if(y == 1){
        return x;
    }else{
        ll res = pow_pangkat(x,y/2,mod);
        res = res * res % mod;
        if(y % 2){
            res = res * x % mod;
        }
        return res;
    }
}

ll pangkat(vector<ll> data,ll indeks,ll k){
    if(indeks == 0){
        return data.at(0);
    }else{
        return pow_pangkat(pangkat(data,indeks - 1,k),data.at(indeks),k);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a,b,c;
    vector<ll> data;
    
    while(cin >> a >> b){
        int hasil;
        while(cin >> c){
            data.push_back(a);
            a = b;
            b = c;
        }
        data.push_back(a);
        cout << pangkat(data,data.size() - 1,b) % b << endl;
        while(data.size() != 0){
            data.pop_back();
        }
        
    }
    

    return 0;
}