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
    
    priority_queue<pair<int,string>,vector<pair<int,string>>, greater<pair<int,string>>> biasa,palin;
    string temp;
    int n;
    cin >> n;
    int jum = n;
    while(n--){
        cin >> temp;
        int l = 0,r = temp.length()-1;
        while(l <= r){
            if(temp[l] != temp[r]){
                break;
            }
            l++;
            r--;
        }
        //cout << l << " " << r << endl;
        if(l > r){
            palin.push({temp.length(),temp});
        }else{
            biasa.push({temp.length(),temp});
        }
    }

    int i = 0;
    jum -= palin.size();
    
    int batas = jum / (palin.size()+1);
    cout << batas << " " << jum << endl;
    while(!biasa.empty()){
        if((!palin.empty()) && (i == batas)){
        //cout << i % 2 << endl;
            cout << palin.top().se << endl;
            palin.pop();
            i = 0;
        }else{
            cout << biasa.top().se << endl;
            biasa.pop();
        i++;
        }
    }
    return 0;
}