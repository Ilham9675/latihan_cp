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
    
    queue <pair<pair<int,int>,int>> nilai;
    int n,m;
    cin >> n >> m ;
    int arr[n+1][m+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    int a,b;
    cin >> a >> b;

    nilai.push({{a,b},0});
    while(!nilai.empty()){
        a = nilai.front().first.first;
        b = nilai.front().first.second;
        int jum = nilai.front().second;
        nilai.pop();
        arr[a][b] = -1;
        if(a == 1 || b == 1 || a == n || b == m){
            cout << jum + 1;
            return 0;
        }
        if(arr[a+1][b] == 0) nilai.push({{a+1,b},jum+1});
        if(arr[a-1][b] == 0) nilai.push({{a-1,b},jum+1});
        if(arr[a][b+1] == 0) nilai.push({{a,b+1},jum+1});
        if(arr[a][b-1] == 0) nilai.push({{a,b-1},jum+1});
    }

    return 0;
}