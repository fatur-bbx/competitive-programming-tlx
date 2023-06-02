#include <bits/stdc++.h>

#define defSetting cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define fi first
#define se second
#define endl '\n'
#define p(x) push(x)
#define read reader{}
#define lb lower_bound
#define ub upper_bound
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define getchar getchar_unlocked
#define mem(x, y) memset(x, y, sizeof(x))
#define sleep(x) for(int i = 0; i < x; i++) sleep_for(nanoseconds(1000000000));
#define asloop(i, x, y, z) for(auto i = x; i <= y ; i += z)
#define deloop(i, x, y, z) for(auto i = x; i >= y; i -= z)

using namespace std;
using namespace chrono;
using namespace this_thread;

typedef long long sll;
typedef unsigned long long ull;

const int mod = 1e9+7;
const string space = " ";

char cc = 0;
template <class type> void readers(type &var){
    var = 0;
    char prev;
    while(cc < 48 || cc >= 58){
        prev = cc;
        cc = getchar();
    }

    if(prev == 45){
        while(cc >= 48 && cc < 58){
            var = (var * 10) - (cc - 48);
            cc = getchar();
        }
    }else{
        while(cc >= 48 && cc < 58){
            var = (var << 1) + (var << 3) + (cc - 48);
            cc = getchar();
        }
    }
}

void readers(string &var){
    var = "";

    while(cc <= 32 || cc == 126){
        cc = getchar();
    }

    while(cc > 32 && cc != 126){
        var.pb(cc);
        cc = getchar();
    }
}

struct reader{
    template <class type> reader &operator >> (type &var){
        readers(var);
        return *this;
    }
};

signed main(){
    defSetting

    sll width, tc;
    read >> width >> tc;

    while(tc--){
        sll Ki;
        read >> Ki;
        cout << 3 * Ki / width << endl;
    }

    return 0;
}