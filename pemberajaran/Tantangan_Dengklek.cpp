#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

queue<pair<int,string>> nilai;
map<string,bool> cek;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,jum=0;
    cin >> n;
    string s="",AC="";
    for(int i=1; i<=n; i++){
        int t;
        cin >> t;
        AC += '0' + i;
        s += '0' + t;
    }
    int k;
    cin >> k;
    
    nilai.push({0,s});
    
    while(!nilai.empty()){
        auto u = nilai.front().fi;
        auto v = nilai.front().se;
        nilai.pop();
        if(v == AC){
            cout << u;
            return 0;
        }
        if(!cek[v]){
            cek[v] = 1;
            for(int i = 0;i <= n-k;i++){
                string sem = v;
                reverse(sem.begin()+i,sem.begin()+i+k);
                nilai.push({u+1,sem});
            }
        }
    }
    cout << "-1";
    return 0;
}