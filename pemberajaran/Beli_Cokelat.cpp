#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,d;
    cin >> n >> d;
    
    vector< pair< ll, ll >> data;

    for(int i = 0;i < n;i++){
        ll a,b;
        cin >> a >> b;
        data.push_back({a,b});
    }
    sort(data.begin(),data.end());
    ll jum = 0;
    for(int i = 0;i < n;i++){
        if(data[i].first <= d/data[i].second){
            jum += data[i].second;
            d -= (data[i].first * data[i].second);
        }else{
            ll sem = d / data[i].first;
            jum += sem;
            break;
        }
        
    }

    cout << jum;
    

    return 0;
}