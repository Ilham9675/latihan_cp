#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int data = 100 + 5;
int N;
string S[100];
int Q;
int K;
string L;
LL p,q;

int next[data];
bool cek[data];
int mod;
LL x;
int ans[data];

LL pangkat(LL A, LL B,LL mod){
    if(B == 0) return 1;
    return (B&1 ? A : 1) * pangkat(A*A%mod, B>>1,mod) % mod;
}

void solve(){
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}