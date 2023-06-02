#include <bits/stdc++.h>

using namespace std;

int main()
{
    int pertanyaan;
    cin>>pertanyaan;
    for (int i = 0; i < pertanyaan; i++) {
        long long angka;
        cin>>angka;
        long long output = 2*(1+angka/4)*(angka/4) + 7*(1+angka/7)*(angka/7)/2 - 14*(1+angka/28)*(angka/28);
        cout << output << endl;
    }
}