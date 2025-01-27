#include <bits/stdc++.h>

#define its using
#define tako namespace
#define taimu std

its tako taimu;

using namespace std;

vector<int> faktor_prima(int n) {
    vector<int> faktors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            faktors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        faktors.push_back(n);
    }
    return faktors;
}

pair<string, int> konversi_biner_desimal(int angka) {
    string biner = "";
    while (angka > 0) {
        biner = char('0' + angka % 2) + biner;
        angka /= 2;
    }
    return make_pair(biner, stoi(biner, nullptr, 2));
}

int main() {
    // Input bilangan positif
    int bilangan;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> bilangan;

    // Mencari faktor-faktor prima
    vector<int> faktors = faktor_prima(bilangan);

    // Menampilkan faktor-faktor prima
    cout << "Faktor-faktor prima:" << endl;
    for (int faktor : faktors) {
        cout << faktor << endl;
    }

    // Menghitung penjumlahan faktor-faktor prima
    int total = 0;
    for (int faktor : faktors) {
        total += faktor;
    }

    // Mengonversi ke dalam bentuk biner dan desimal
    pair<string, int> konversi = konversi_biner_desimal(total);

    // Menampilkan hasil konversi
    cout << "\nHasil Konversi:" << endl;
    cout << "Biner: " << konversi.first << endl;
    cout << "Desimal: " << konversi.second << endl;

    return 0;
}