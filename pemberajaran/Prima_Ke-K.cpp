#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void cari_prima(vector<int> &prime){
    bool cek_prime[1000005];
    memset(cek_prime,true,sizeof(cek_prime));
    for(int p = 2;p * p < 1000005;p++){
        if(cek_prime[p] == 1){
            for(int i = p*p;i < 1000005;i += p){
                cek_prime[i] = false;
            }
        }
    }
    for(int i = 2;i < 1000005;i++){
        if(cek_prime[i]){
            prime.push_back(i);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> prime;
    cari_prima(prime);
    int n;
    
    cin >>n;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        cout << prime.at(temp - 1) << endl;
    }
    
    return 0;
}
