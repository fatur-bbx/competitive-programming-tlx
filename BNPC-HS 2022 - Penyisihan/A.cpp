#include <cstdio>
#include <cstring>
using namespace std;
#pragma GCC optimize("O2")
#pragma unroll 2
#define gc getchar_unlocked
namespace fastio{
    template <typename T> void sca(T &angka){
        T kali = 1; angka = 0; char input = gc();
        while(input < '0' || input > '9') {
            if(input=='-'){
                kali = -1;
                input = gc();
            }
        }
        while(input >= '0' && input <= '9'){
            angka = (angka << 3) + (angka << 1) + input - 48, input = gc();
            angka *= kali;
        }
    }
    template <typename FIRST, typename... REST> void scan(FIRST& first, REST&... rest);
    void scan(){}
    template <typename FIRST, typename... REST> void scan(FIRST& first, REST&... rest){sca(first);scan(rest...);}    
}using namespace fastio;

typedef long long ll;
#define fi first
#define se second

int arr[1001];

int main(){
    int n, m;
    scan(n, m);
    int i, a;
    for(a = 1; a <= m; ++a){
        scan(i);
        arr[i] = (++arr[i]) % 4;
    }
    i = 0;
    for(a = 1; a <= n; ++a){
        if(arr[a] == 2 || arr[a] == 3) ++i;
    }
    printf("%d\n",i);

    return 0;
}