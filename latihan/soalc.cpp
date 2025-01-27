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
    
    ll a,b;
    cin >> a >> b;
    if(a > b){
        for(int i = 0;i < a-b;i++){
            for(int j = 0;j < i;j++){
                cout << " ";
            }
            for(int j = 0;j < (a-b)-i;j++){
                cout << "*";
            }
            cout << endl;
        }
        for(int i = 2;i <= a-b;i++){
            for(int j = 0;j < (a-b)-i;j++){
                cout << " ";
            }
            for(int j = 0;j < i;j++){
                cout << "*";
            }
            cout << endl;
        }
    }else if(a < b){
        for(int i = 0;i < b-a;i++){
            for(int j = 0;j < (b-a)-i;j++){
                cout << "*";
            }
            cout << endl;
        }
        for(int i = 2;i <= b-a;i++){
            for(int j = 0;j < i;j++){
                cout << "*";
            }
            cout << endl;
        }
    }else{
        for(int i = 0;i < a*2-1;i++){
            for(int j = 0;j < a;j++){
                cout << "*";
            }
            cout << endl;
        }
    }

    return 0;
}