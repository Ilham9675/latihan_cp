#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second


ll binset(ll m, ll harga, ll panjang, ll cheapest){
    ll L = 0, R = m/harga,ret = 0;
    while(L <= R){
        ll mid = (L + R) / 2;
        ll sisa = m - (harga * mid);
        if((sisa / cheapest) + mid >= panjang){
            L = mid + 1;
            ret = mid;
        }else {
            R = mid - 1;
        }
    }
    return ret;
}

void tampil(deque<ll> nilai){
    while(nilai.size()){
        cout << nilai.front();
        nilai.pop_front();
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<pair<ll,ll>> a(n+1),temp(n+1);
    ll minim = LLONG_MAX;
    for(int i = 0;i <= n;i++){
        cin >> a[i].fi;
        a[i].se = i;
        minim = min(minim,a[i].fi);
    }

    ll m;
    cin >> m;
    ll panjang = m/minim;
    temp = a;
    sort(temp.begin(),temp.end());
    if(temp[0].se == 0){
        if(n > 0 && m >= temp[1].fi){
            panjang = (m - temp[1].fi) / minim + 1;
        }else{
            panjang = (m >= temp[0].fi);
        }
    }

    ll nilai = panjang;
    deque<ll> nilai1,nilai2;
    bool cek = false;
    for(int i = n;i >= 0;i--){
        ll beli = binset(m,a[i].fi,panjang,minim);
        panjang -= beli;
        m -= (a[i].fi * beli);
        while(nilai1.size() < 50 && beli > 0){
            nilai1.pb(i);
            nilai2.pb(i);
            beli--;
            if(nilai1.size() == 1 && i == 0){
                cek = true;
                nilai = 1;
                break;
            }
        }
        if(cek)break;
        if(beli > 0){
            if(beli >= 50){
                nilai2.clear();
                for(int j = 1; j <= 50;j++){
                    nilai2.pb(i);
                }
            }else{
                for(int j = 1; j <= beli; j++){
                    nilai2.pop_front();
                    nilai2.pb(i);
                }
            }
        }
    }
    if(nilai == 0){
        cout << 0 << endl;
    }else{
        cout << nilai << endl;
        tampil(nilai1);
        tampil(nilai2);
    }


    

    return 0;
}