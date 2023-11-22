#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n;
    int nilai[n];
    for(int i = 0;i < n;i++){
        cin >> nilai[i];
    }
    cin >> m;
    int hasil[m+1];
    hasil[0] = 0;

    for(int i = 1;i <= m;i++){
        int temp = m + 1;
        for(int j = 0;j < n;j++){
            if(i - nilai[j] >= 0){
                temp = min(temp,hasil[i-nilai[j]] + 1);
            }
        }
        hasil[i] = temp;
    }
    
    cout << hasil[m];



    return 0;
}