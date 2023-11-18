#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int monster;
    bool dikunjungi = 0;
    vector<int> tetangga;
} Node;

int hitungTenagaTanpaPengali(Node node[], int nodeinit) {
    stack<int> tetangga;
    tetangga.push(nodeinit);
    node[nodeinit].dikunjungi = 1;
    int curNode;

    int sum = node[nodeinit].monster;
    while(!tetangga.empty()) {
        curNode = tetangga.top();
        tetangga.pop();
        for(auto adjNode: node[curNode].tetangga) {
            if(!node[adjNode].dikunjungi) {
                tetangga.push(adjNode);
                node[adjNode].dikunjungi = 1;

                sum += node[adjNode].monster;
            }
        }
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;

    Node node[N];
    for(int i = 0; i < N; i++) cin >> node[i].monster;

    int nodeA, nodeB;
    int i = 0;
    while(i < K) {
        cin >> nodeA >> nodeB;
        nodeA--;
        nodeB--;
        node[nodeA].tetangga.push_back(nodeB);
        node[nodeB].tetangga.push_back(nodeA);
        i++;
    }

    vector<int> sumByGroup;
    int temp;
    i = 0;
    int sz2 = 0;
    int j;
    while(i < N) {
        if(!node[i].dikunjungi) {
            temp = hitungTenagaTanpaPengali(node, i);
            sumByGroup.push_back(temp);
            sz2++;
            j = sz2 - 1;
            while(j > 0 && sumByGroup[j] > sumByGroup[j - 1]) {
                swap(sumByGroup[j], sumByGroup[j - 1]);
                j--;
            }
        }
        i++;
    }

    int ans = 0;
    int pengali = 1;
    
    i = 0;
    int sz = sumByGroup.size();
    while(i < sz) {
        ans += (sumByGroup[i] * pengali);
        pengali++;
        i++;
    }

    cout << ans << endl;
    return 0;
}