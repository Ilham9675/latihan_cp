#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


vector<vector<int> > mat;

void matrix(int a, int b, int size, const string& code){
    if(code.empty()){
        for(int i = a;i < a + size;i++){
            for(int j = b;j < b + size;j++){
                mat[i][j] = 1;
            }
        }
        return;
    }
    int newsize = size / 2;
    switch(code[0]){
        case '0':
            matrix(a,b,newsize,code.substr(1));
            break;
        case '1':
            matrix(a,b + newsize,newsize,code.substr(1));
            break;
        case '2':
            matrix(a + newsize,b,newsize,code.substr(1));
            break;
        case '3':
            matrix(a + newsize,b + newsize,newsize,code.substr(1));
            break;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N , R , C , P;  
    cin >> N;
    vector<string> codes(N);
    for(string& code : codes){
        cin >> code;
    }
    cin >> R >> C;
    for(P = 1;(1 << P) < max(R,C);++P);
    int newsize = 1 << P;

    mat.assign(newsize,vector<int>(newsize,0));

    for(const string& code : codes){
        matrix(0,0,newsize,code.substr(1));
    }
    for(int i = 0;i < R;++i){
        for(int j = 0;j < C;++j){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }


    

    return 0;
}