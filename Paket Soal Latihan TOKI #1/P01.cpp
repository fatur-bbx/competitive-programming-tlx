#include <bits/stdc++.h>
using namespace std;

int main(){
    int banyak;
    cin >> banyak;
    string out = "";
    for (int i = 0; i < banyak; i++) {
        int angka;
        cin >> angka;
        int reversed_number = 0, rem;
        while(angka != 0) {
            rem = angka % 10;
            reversed_number = reversed_number * 10 + rem;
            angka /= 10;
        }
        out += to_string(reversed_number)+"\n";
    }
    cout << out;
}