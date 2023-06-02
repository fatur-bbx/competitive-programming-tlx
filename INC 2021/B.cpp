#include "bits/stdc++.h"
using namespace std;

signed main()
{
    int n;
    scanf("%d",&n);
    vector<int> L;
    int tw = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        if(x==2)
            tw++;
        else
            L.push_back(x),sum+=x;
    }
    bool ok = false;
    if(L.empty())
        ok=true;
    else if(sum%2==0){
        bitset<125001> dp(1);
        for(int x:L){
            dp |= (dp<<x);
        }
        for(int i = 0; i <= tw; i++){
            if(dp[sum>>1])
                ok=true;
            sum+=2;
        }
    }
    if(ok)
        puts("YES");
    else
        puts("NO");
}