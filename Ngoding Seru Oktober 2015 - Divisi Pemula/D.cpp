#include <bits/stdc++.h>

using namespace std;

int main(){
    int s, N, D, i = 1;
    cin >> s >> N >> D;
    while(i <= N){
        cout << s << endl;
        s+=D;
        i++;
    }
}