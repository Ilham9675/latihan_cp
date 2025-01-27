#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second

int fpb (int x, int y)  //rekrusif fpb
{
 int hasil, sisabagi;
 
 if (y <= x && x % y == 0)
 {
  return y;
 }
 else
  if (x < y)
  {
   hasil = fpb (y, x);
   return hasil;
  }
  else
   {
    sisabagi = x % y;
    hasil = fpb (y, sisabagi);
    return hasil;
   }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b;
    while(cin >> a >> b){
        
        ll c = fpb(a,b);
        a /= c;
        b /= c;
        c /= c;
        ll x1 = 1,y1 = 0;
        ll x2 = 0,y2 = 1;
        while(((a*x1) + (b*y1) != 1) && ((a*x2) + (b*y2) != 1)){
            
        //cout << a*x2 + b*y2 << " " << x2 << " " << y2 << endl;
            if(abs(a*x1) < abs(b*y1)){
                x1++;
            }else{
                y1--;
            }
            if(abs(a*x2) < abs(b*y2)){
                x2--;
            }else{
                y2++;
            }
        }
        if(a*x1 + b*y1 == 1){
            cout << x1 << " " << y1 << endl;
        }else{
            cout << x2 << " " << y2 << endl;
        }
        
    }
    return 0;
}