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
    ll n,m;
    char temp;
    cin >> n >> m;
    deque<char> n1,n2;
    for(int i = 0;i < n;i++){
        cin >> temp;
        n1.pb(temp);
    }
    for(int i = 0;i < m;i++){
        cin >> temp;
        n2.pb(temp);
    }
    while(!n1.empty() && !n2.empty()){
        temp = n2.front();
        n2.pop_front();
        
        if(n1.back() == temp){
            while(n1.back() == temp){
                n1.pop_back();
                if(n1.empty()){
                    break;
                }
            }
        }else{
            n1.push_back(temp);
        }
    }
    if(n1.empty()){
        cout << "MENANG";
    }else{
        cout << "KALAH";
    }

    return 0;
}