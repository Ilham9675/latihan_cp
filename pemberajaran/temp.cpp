#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>m;
int njawaban;
vector<string> jawaban;

bool HG(int r, int c, int k){
    int val = m[r][c];
    for(int i = r;i < r+k;i++){
        for(int j = c;j < c+k;j++){
            if(m[i][j] != val){
                return false;
            }
        }
    }
    return true;
}

void QT(int r, int c, int k, string s){
    if(HG(r,c,k)){
        if(m[r][c] == 1){
            jawaban.push_back("1"+ s);
            njawaban++;
        }
    }else{
        QT(r,c,k/2,s+"0");
        QT(r,c+(k/2),k/2,s+"1");
        QT(r+(k/2),c,k/2,s+"2");
        QT(r+(k/2),c+(k/2),k/2,s+"3");
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r,c;
    cin >> r >> c;
    
    int maxrc = max(r,c);
    int pow2 = pow(2,ceil(log2(maxrc)));
    
    m.resize(pow2,vector<int>(pow2,0));

    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin >> m[i][j];
        }
    }

    njawaban = 0;
    QT(0,0,pow2,"");

    cout << njawaban << endl;
    for(int i = 0;i < njawaban;i++){
        cout << jawaban[i] << "\n";
    }
    return 0;
}