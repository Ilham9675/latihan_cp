#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string nilai;
    cin >> nilai;
    if(nilai.find('0') < nilai.length()){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}