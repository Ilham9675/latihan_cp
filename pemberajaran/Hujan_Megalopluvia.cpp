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

    ll a,b;
    cin >> a >> b;
    ll nilai[a+1];
    for(ll i = 1;i <= a;i++){
        cin >> nilai[i];
    }
    ll mid = b,l = b - 1,r = b +1;
    while(nilai[l] < nilai[mid] || nilai[r] < nilai[mid]){
        if(nilai[l] < nilai[mid] && nilai[r] < nilai[mid]){
            if(nilai[l] < nilai[r]){
                l--;
                mid--;
                r--;
            }else{
                l++;
                mid++;
                r++;
            }
        }else if(nilai[l] < nilai[mid]){
            l--;
            mid--;
            r--;
        }else{
            l++;
            mid++;
            r++;
        }
    }
    cout << mid << endl;
    ll hasil[a+1];
    ll indek = 1;
    hasil[indek] = mid;
    while(l > 0 || r <= a){
        if(nilai[l] <= nilai[r]){
            hasil[indek] = l;
            l--;
        }else{
            hasil[indek] = r;
            r--;
        }
        indek++;
    }


    return 0;
}