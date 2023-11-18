#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;

    vector<pair<int ,int>> betina,jantan;
    int x,y,z;
    int min_jantan = INT_MAX,max_jantan = INT_MIN,min_betina = INT_MAX,max_betina = INT_MIN;
    for(int i = 0;i < n ;i++){
        cin >> x >> y >> z;
        if(z == 0){
            jantan.push_back({x,y});
            if(min_jantan > y){
                min_jantan = y;
            }
            if(max_jantan < y){
                max_jantan = y;
            }
        }else{
            betina.push_back({x,y});
            if(min_betina > y){
                min_betina = y;
            }
            if(max_betina < y){
                max_betina = y;
            }
        }
    }

    sort(betina.begin(), betina.end());
    sort(jantan.begin(), jantan.end());

    int batas_x,batas_y,temp_x,temp_y;
    float min = INT_MAX;
    for(int i = 0;i < jantan.size();i++){
        for(int j = 0;j < betina.size();j++){
            float temp = sqrt(pow(abs(jantan[i].first - betina[j].first),2) + pow(abs(jantan[i].second - betina[j].second),2));
            if(min > temp){
                min = temp;
                batas_x = (jantan[i].first + betina[j].first) / 2;
                batas_y = (jantan[i].second + betina[j].second) / 2;
                temp_x = jantan[i].first;
                temp_y = jantan[i].second;
            }
        }
    }
    cout << batas_x << batas_y << endl;

    if((jantan[jantan.size() - 1].first < batas_x) && (betina[0].first > batas_x)){
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> x >> y;
            if(x < batas_x){
                cout << "JANTAN\n";
            }else{
                cout << "BETINA\n";
            }
        }
    }else if((betina[betina.size() - 1].first < batas_x) && (jantan[0].first > batas_x)){
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> x >> y;
            if(x > batas_x){
                cout << "JANTAN\n";
            }else{
                cout << "BETINA\n";
            }
        }
    }else if((max_jantan < batas_y) && (min_betina > batas_y)){
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> x >> y;
            if(y < batas_y){
                cout << "JANTAN\n";
            }else{
                cout << "BETINA\n";
            }
        }
    }else if((max_betina < batas_y) && (min_jantan > batas_y)){
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> x >> y;
            if(y > batas_y){
                cout << "JANTAN\n";
            }else{
                cout << "BETINA\n";
            }
        }
    }else{
        int m,c;
        int X1,X2,Y1,Y2;
        X1 = (-temp_y) + batas_x + batas_y;
        Y1 = temp_x - batas_x + batas_y;
        X2 = temp_y - batas_y + batas_x;
        Y2 = (-temp_x) + batas_x + batas_y;

        m = abs(Y1 - Y2) / abs(X1 - X2);
        c = (m * batas_x) / batas_y;
        

        cin >> n;

        int hasil = (m * jantan[0].first) + c;
        if(hasil > jantan[0].second){
            for(int i = 0;i < n;i++){
                cin >> x >> y;
                hasil = (m * x) + c;
                if(hasil > batas_y){
                    cout << "JANTAN\n";
                }else{
                    cout << "BETINA\n";
                }
            }

        }else{
            for(int i = 0;i < n;i++){
                cin >> x >> y;
                hasil = (m * x) + c;
                if(hasil < batas_y){
                    cout << "JANTAN\n";
                }else{
                    cout << "BETINA\n";
                }
            }
        }
    }

    
    
    
    return 0;
}