#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> nilai;
    int N;
    cin >> N;
    for(int i = 0;i < N;i++){
        string printah;
        cin >> printah;
        if(printah == "add"){
            int temp,jum;
            cin >> temp >> jum;
            for(int j = 0;j < jum;j++){
                nilai.push_back(temp);
            }
            cout << nilai.size() << endl;
        }else if(printah == "del"){
            int jum;
            cin >> jum;
            cout << nilai.front() << endl;
            nilai.erase(nilai.begin(),nilai.begin() + jum);
        }else if(printah == "rev"){
            reverse(nilai.begin(),nilai.end());
        }
    }
    


    return 0;
}