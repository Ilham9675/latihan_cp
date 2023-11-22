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
    
    int n;
    cin >> n;
    int temp[n];
    for(int i = 0;i < n;i++){
        cin >> temp[i];
    }
    ll total = 0;
    stack<int> nilai;
    for(int i = 0;i < n;i++){
        if(i == 0 || i == n - 1){
            nilai.push(temp[i]);
        }else{
            if(temp[i] <= nilai.top() && temp[i] <= temp[i+1]){
                total += min(nilai.top(), temp[i+1]);
            }else{
                nilai.push(temp[i]);
            }
        }
    }
    while(nilai.size() > 1){
        int sem = nilai.top();
        nilai.pop();
        total += max(sem,nilai.top());
    }
    cout << total;

    return 0;
}