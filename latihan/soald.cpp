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
    
    int n;
    cin >> n;
    for(int i= 0;i < n ;i++){
        float a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a/b > c/d){
            cout << "Lebih Besar\n";
        }else if(a/b < c/d){
            cout << "Lebih Kecil\n";
        }else{
            cout << "Sama\n";
        }
    }



    return 0;
}