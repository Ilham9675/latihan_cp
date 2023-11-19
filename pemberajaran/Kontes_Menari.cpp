#include <bits/stdc++.h>
typedef int ll;
using namespace std;

ll n, r, y, j, bonus;
bool user[15];
char gerak[15];
ll score[15];
vector<ll> v;

void proses(ll indek,ll sum, char prev, bool prevuser){
    if(indek > r){
        v.push_back(sum);
        return;
    }
    for(ll i = 1;i <= n;i++){
        if(user[i])continue;
            
        user[i] = 1;
        ll newsum = sum;
        if(prev == 'P') newsum += score[i] * 2;
        else if(prev == 'L') newsum += score[i] / 2;
        else newsum += score[i];

        if(prevuser) newsum += bonus;
        proses(indek+1, newsum, gerak[i],prevuser | (gerak[i] == 'Y'));
        user[i] = 0;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string sub;
    cin >> sub;
    int nomer = 0;
    cin >> nomer;

    cin >> n >> r >> bonus >> j;

    for(ll i = 1;i <= n;i++){
        cin >> score[i] >> gerak[i];
    }

    proses(1,0,'B',0);
    sort(v.begin(),v.end());

    while(j--){
        ll x;
        cin >> x;
        cout << v.size() - (upper_bound(v.begin(),v.end(),x) - v.begin()) << endl;
    }

    
    return 0;
}