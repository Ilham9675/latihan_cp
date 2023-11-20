#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int nilai[100000];

int cari(int jum,int indek, int batas,int sisa){
    if(indek < batas){
        if(sisa/nilai[indek] != 0){
            jum += (sisa/nilai[indek]);
            sisa %= nilai[indek];
            if(sisa == 0){
                return jum;
            }else{
                return cari(jum , indek+1,batas,sisa);
            }
        }else{
            return cari(jum , indek+1,batas,sisa);
        }
    }else{
        return 0;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> m >> n;
    for(int i = 0;i < n;i++){
        cin >> nilai[i];
    }
    int hasil = INT_MAX;
    sort(nilai,nilai+n,greater<int>());
    for(int i = 0;i < n;i++){
        int temp_hasil = 0;
        int target = m;
        if(target % nilai[i] == 0){
            if(target / nilai[i] != 0){
                hasil = min(target/nilai[i],hasil);
            }
        }else{
            //cout << "*";
            temp_hasil = cari(0,i,n,target);
            if(temp_hasil != 0){
                hasil = min(temp_hasil,hasil);
            }
        }
    }
    if(hasil == INT_MAX){
        cout << 0 << endl;
    }else{
        cout << hasil << endl;
    }

    return 0;
}