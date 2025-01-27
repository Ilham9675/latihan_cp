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

int p[101],r[101];

int findset(int a){
    if(p[a] == a){
        return a;
    }
    p[a] = findset(p[a]);
    return p[a];
}

bool cek(int a,int b){
    return findset(a) == findset(b);
}

void add(int a,int b){
    a = findset(a);
    b = findset(b);
    if(r[a] < r[b]){
        p[a] = b;
    }else{
        p[b] = a;
        if(r[a] == r[b]){
            r[a]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        p[i] = i;
        r[i] = 0;
    }

    vector<pair<int,pii>> nilai;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int temp;
            cin >> temp;
            if(i!= j){
                nilai.push_back({temp,{i,j}});
            }
        }
    }
    sort(nilai.begin(),nilai.end());
    int jum = 0;
    for(auto i : nilai){
        int temp = i.first;
        int a = i.second.first;
        int b = i.second.second;
        if(!cek(a,b)){
            jum += temp;
            add(a,b);
        }
    }
    cout << jum;

    return 0;
}