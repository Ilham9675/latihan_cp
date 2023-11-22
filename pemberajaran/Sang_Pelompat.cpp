#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl "\n"
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define fi first
#define se second
#define pii pair<int,int>

int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,1,-1};

int r,c;
char a[1005][1005];
int hasil[1005][1005];
queue <pii> q;

void bfs(int x,int y){
    hasil[x][y] = 0;
    q.push({x,y});
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int go_x = cur.fi + movex[i],go_y = cur.se + movey[i];
            
            if(go_x > 0 && go_x <= r && go_y > 0 && go_y <= c){
                if(a[go_x][go_y] == '#' || a[go_x][go_y] == 'T'){
                    if(hasil[go_x][go_y] > hasil[cur.fi][cur.se]){
                        hasil[go_x][go_y] = hasil[cur.fi][cur.se];
                        q.push({go_x,go_y});
                    }
                    continue;
                }
                while(go_x > 0 && go_x <= r && go_y > 0 && go_y <= c && a[go_x][go_y] == '.'){
                    go_x += movex[i];
                    go_y += movey[i];
                }
                
                if(go_x > 0 && go_x <= r && go_y > 0 && go_y <= c){
                    
                    if(hasil[go_x][go_y] > hasil[cur.fi][cur.se] + 1){
                        hasil[go_x][go_y] = hasil[cur.fi][cur.se] + 1;
                        q.push({go_x,go_y});
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string temp;
    cin >> temp;
    cin >> r >> c;
    int sx = 0,sy = 0,ex = 0,ey = 0;
    for(int i = 1;i <= r;i++){
        for(int j = 1;j <= c;j++){
            cin >> a[i][j];
            if(a[i][j] == 'S') sx = i, sy = j;
            if(a[i][j] == 'T') ex = i, ey = j;
        }
    }
    
    for(int i = 1;i <= r;i++){
        for(int j = 1;j <= c;j++){
            hasil[i][j] = 1e9;
        }
    }
    bfs(sx,sy);
    if(hasil[ex][ey] == 1e9) cout << -1;
    else cout << hasil[ex][ey];

    return 0;
}