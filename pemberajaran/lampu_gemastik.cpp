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
    ll n,jum = 0;
    int temp,nilai;
    cin >> n >> temp;
    for(int i = 1;i <n;i++){
        cin >> nilai;
        if(nilai != temp){
            jum++;
        }
        temp = nilai;
    }
    if(temp == 1){
        jum++;
    }
    cout << jum;

    

    return 0;
}