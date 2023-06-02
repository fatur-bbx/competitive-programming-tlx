#include <bits/stdc++.h>

using namespace std;

int main(){
    int detik;
    cin >> detik;
    int jam = detik/3600;
    detik -= (jam*3600);
    int menit = detik/60;
    detik-=(menit*60);
    cout << jam << endl;
    cout << menit << endl;
    cout << detik << endl;
}