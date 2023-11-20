#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<int> nilai;
    int N,sem = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        string printah;
        cin >> printah;
        if(printah == "add"){
            int x,y;
            cin >> x >> y;
            for(int j = 0; j < y; j++){
                nilai.push(x - sem);
            }
            cout << nilai.size() << endl;
        }else if(printah == "del"){
            int x;
            cin >> x;
            cout << nilai.top() + sem << endl;
            for(int j = 0; j < x; j++){
                nilai.pop();
            }
        }else if(printah == "adx"){
            int x;
            cin >> x;
            sem += x;
        }else if(printah == "dex"){
            int x;
            cin >> x;
            sem -= x;
        }
    }


    return 0;
}