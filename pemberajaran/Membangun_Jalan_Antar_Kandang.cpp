#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int jalur[100000];
int poin[100000];

int findset(int x){
    if(jalur[x] == x){
        return x;
    }
    jalur[x] = findset(jalur[x]);
    return jalur[x];
}
bool cek(int a,int b){
    return findset(a) == findset(b);
}

void join(int a,int b){
    a = findset(a);
    b = findset(b);
    if(poin[a] > poin[b]){
        jalur[b] = a;
    }else{
        jalur[a] = b;
        if(poin[a] == poin[b]){
            poin[b]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,a,b,x;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        jalur[i] = i;
        poin[i] = 0;
    }
    while(k--){
        cin >> x >> a >> b;
        if(x == 1){
            if(!cek(a,b)){
                join(a,b);
            }
        }else{
            if(cek(a,b)){
                cout << "Y" << endl;
            }else{
                cout << "T" << endl;
            }
        }
    }
    

    return 0;
}