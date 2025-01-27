#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string sub;
    cin >> sub;
    int n,sd,sm;
    cin >> n >> sd >> sm;
    priority_queue<int> nilai;
    ll jum = 0;
    for(int i = 0;i < n-1;i++){
        int p,k,l;
        cin >> p >> k >> l;
        while(!nilai.empty() && sd < p){
            sd++;
            jum += -nilai.top();
            nilai.pop();
        }
        if(sd < p){
            jum = INT_MIN;
        }
        if(l <= k){
            jum+=l;
            sd++;
        }else{
            jum+=k;
            nilai.push(-(l-k));
        }
    }
    while(!nilai.empty() && sd < sm){
        sd++;
        jum += -nilai.top();
        nilai.pop();
    }
    if(sd < sm){
        jum = INT_MIN;
    }

    if(jum < 0){
        cout << "-1";
    }else{
        cout << jum;
    }
    return 0;
}