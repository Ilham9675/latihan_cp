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
    
    priority_queue<int> nilai;
    int n;
    cin >> n;
    while(n--){
        ll p;
        cin >> p;
        if(p == 1){
            int temp;
            cin >> temp;
            nilai.push(temp);
        }else if(p == 2){
            cout << nilai.top() << endl;
        }else if(p == 3){
            nilai.pop();
        }
    }

    return 0;
}