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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ull vertex;
    cin >> vertex;
    ull jum = 0;
    while(vertex != 0){
        jum += vertex;
        vertex /= 2;
    }
    cout << jum;
    return 0;
}