#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

ll mod;
bool cek = false;

ll pangkat(ll a,ll b){
    if(b == 0) return 1;
    if(a == 0) return 0;
    if(b == 1) return a;
    ll x = pangkat(a,b/2);
    x *= x;
    ll y = x % mod * a;
    if(b & 1){
        if(!cek){
            if(x >= mod || y >= mod) cek = true;
        }
        return y % mod;
    }
    if(!cek){
        if(x >= mod) cek = true;
    }
    return x % mod;
}

void cari(vector<ll> &nilai){
    if(nilai.size() >= 3){
        ll sem = nilai.at(0);
        for(int i = 0;i < nilai.at(2);i++){
            ll hasil = nilai.at(1);
            sem = pangkat(sem,hasil) % mod;
        }
        nilai.erase(nilai.begin());
        nilai.erase(nilai.begin());
        nilai.erase(nilai.begin());
        nilai.insert(nilai.begin(),sem);
        cari(nilai);
    }else if(nilai.size() == 2){
        ll sem = pangkat(nilai.at(0),nilai.at(1));
        nilai.erase(nilai.begin());
        nilai.erase(nilai.begin());
        nilai.insert(nilai.begin(),sem);
        cari(nilai);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string temp;
    vector<ll> nilai;
    
    while(getline(cin,temp)){
        ll sem = 0;
        for(int i = 0;i < temp.size();i++){
            if(temp[i] == ' '){
                nilai.push_back(sem);
                sem = 0;
            }else{
                sem = sem * 10 + (temp[i] - 48);
            }
        }
        
        mod = sem;
        cek = false;
        cari(nilai);
        cout << nilai.at(0) % mod << endl;
        
        nilai.pop_back();
    }
    

    return 0;
}