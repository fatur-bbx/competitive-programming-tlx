#include <bits/stdc++.h>

using namespace std;

int main()
{
    int banyak, cari;
    bool flag = false;
    cin >> banyak >> cari;
    int inde = 0;
    for (int i = 0; i < banyak; i++) {
        int angka;
        cin >> angka;
        if(angka == cari && flag == false){
            inde = i;
            flag = true;
            break;
        }
    }
    if(flag != false){
        cout << inde << endl;
    }else{
        cout << -1 << endl;
    }
}