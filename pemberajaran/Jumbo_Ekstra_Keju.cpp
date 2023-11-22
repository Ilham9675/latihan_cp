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
    
    int b;
    cin >> b;
    if(b >= 100){
        cout << 9;
        return 0;
    }
    cout << (b-9)/10;

    return 0;
}