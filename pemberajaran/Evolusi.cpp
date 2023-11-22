#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

stack <string> temp;
map<string,string> nilai;

bool bfs(string nod,string target){
    temp.push(nod);
    if(nod == target){
        return true;
    }
    if(nilai[nod] == ""){
        return false;
    }
    return bfs(nilai[nod],target);

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    string a,b;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        nilai[b] = a;
    }
    
    cin >> a >> b;
    bool cek = bfs(a,b);
    if(cek){
        while(!temp.empty()){
            cout << temp.top() << endl;
            temp.pop();
        }
        return 0;
    }
    while(!temp.empty()){
        temp.pop();
    }

    cek = bfs(b,a);
    if(cek){
        while(!temp.empty()){
            cout << temp.top() << endl;
            temp.pop();
        }
        return 0;
    }
    cout << "TIDAK MUNGKIN";

    return 0;
}