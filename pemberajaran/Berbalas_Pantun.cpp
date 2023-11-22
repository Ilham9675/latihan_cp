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
    
    int n;
    cin >> n;
    int temp;
    ll jum = 0;
    for(int i = 0;i < n*2;i++){
        cin >> temp;
        jum += temp;
    }
    cout << jum*n;
    return 0;
}