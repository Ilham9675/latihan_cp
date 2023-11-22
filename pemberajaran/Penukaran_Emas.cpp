#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int solve(int n){
    int a = n/2 + n/3 + n/4;
    if(a < n){
        return n;
    }else{
        return solve(n/2) + solve(n/3) + solve(n/4);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    cout << solve(n);

    return 0;
}