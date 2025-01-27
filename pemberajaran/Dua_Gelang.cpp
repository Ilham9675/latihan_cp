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
    
    int x1,x2,y1,y2,z1,z2;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    if(pow(x1-x2,2) + pow(y1-y2,2) < pow(z2-z1,2) || pow(x1-x2,2) + pow(y1-y2,2) > pow(z2+z1,2)){
        cout << "tidak bersentuhan";
    }else{
        cout << "bersentuhan";
    }



    return 0;
}