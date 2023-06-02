#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long in[3], q, t, ans;
    char s;
    cin >> in[0] >> in[1] >> in[2] >> q;
    while(q--){
        cin >> s >> t;
        in[s-'a'] += t;
        ans = in[0]+in[1]+in[2] - gcd(in[0], in[1]) - gcd(in[0], in[2]) - gcd(in[1], in[2]) + gcd(gcd(in[0], in[1]), in[2]);
        cout<<ans<<'\n';
    }
}