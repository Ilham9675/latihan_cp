#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int initpos, int N, int M) {
    if(M >= N) return 0;

    int res = 0, temp = INT_MIN, temp2 = INT_MIN;
    for(int i=initpos;i<N;i++) {
        for(int j=i+1; j<N; j+=M) {
            cout << temp << " " << res << "\t";
            temp = max(temp, arr[j-i]);
            arr[j] = max(arr[j], arr[j]);
            cout << i << " " << j << " " << M << " " << temp << endl;
            //temp2 = max(temp2, getMax(arr, j, N, M));
        }
        temp2 = max(temp2, temp);
        //res = max(temp2, res);
    }
    return temp2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int arr[N];
    for(int i=0; i<N; i++) cin >> arr[i];

    cout << getMax(arr, 0, N, M) << endl;
    return 0;
}