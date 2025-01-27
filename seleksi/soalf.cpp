#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> b;
    map<int,deque<int>> nilai;
    int n = 0;
    cin >> n;
    int awal;
    for(int i = 0;i < n;i++){
        int x,y;
        cin >> x >> y;
        if(i == 0){
            awal = x;
        }
        nilai[x].push_back(y);
    }
    int lantai = awal;
    priority_queue<int,vector<int>,greater<int>> lif;
    ll jum = awal-1;
    bool cek = 1;
    ll sem = 0;
    int up = -1;
    //cout << jum;
    while(lantai != 11 && lantai != 0){
        //cout << nilai[lantai].front() << endl;
        if(lif.size() != 0){
            jum += sem;
            //cout << jum << endl;
            sem = 0;

            while(lif.size() != 0 && lif.top() == lantai){
                //cout << "*";
                jum++;
                lif.pop();
            }
            if(lif.size() != 0){
                if(lif.top() > lantai){
                    cek = 1;
                }else{
                    cek = 0;
                }
            }
        }
        if(nilai[lantai].size() > 0){
            jum += sem;
            sem = 0;
            while(lif.size() <= 4 && nilai[lantai].size() > 0){
                jum++;
                lif.push(nilai[lantai].front());
                nilai[lantai].pop_front();
            }
            //cout << jum << endl;
            if(lif.size() != 0){
                if(lif.top() > lantai){
                    cek = 1;
                }else{
                    cek = 0;
                }
            }
        }
        if(lif.size() == 0){
            int a = lantai+1;
            int temp1 = 0,temp2 = 0;
            while(a <= 10){
                if(nilai[lantai].size() > 0){
                    temp1 = lantai;
                    break;
                }
                a++;
            }
            a = lantai-1;
            while(a > 0){
                if(nilai[lantai].size() > 0){
                    temp2 = lantai;
                    break;
                }
                a--;
            }
            if(temp1 == 0 && temp2 != 0){
                cek = 0;
            }else if(temp1 != 0 && temp2 == 0){
                cek = 1;
            }else{
                if(min(temp1-lantai,lantai-temp2) < lantai){
                    cek = 0;
                }else{
                    cek = 1;
                }
            }
            
        }
        if(cek == 1){
            //cout << "*";
            lantai++;
        }else{
            //cout << "-";
            lantai--;
        }
        sem++;
    }
    cout << jum;
    

    return 0;
}
