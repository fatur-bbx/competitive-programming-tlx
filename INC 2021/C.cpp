#include <bits/stdc++.h>
using namespace std;
const long long d=13;
long long n, a[2][100069],pr[100069],ex[d]={0,3,11,19,29,45,71,97,123,149,175,313,407};
bitset<100069>vtd, dp;

int main(){
    long long i, ii, c, p, z = 0;

    for(i = 0; i<d; i++){
        dp[ex[i]] = 1;
    }
    scanf("%lld", &n);
    for(int ii = 0; ii < 2; ii++){
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[ii][i]);
        }
    }
    for(i = 1; i <= n; i++){
        pr[a[0][i]] = a[1][i];
    }
    for(i = 1; i <= n; i++){
        if(!vtd[i]){
            c=0;
            for(p=i;!vtd[p];p=pr[p]){
                vtd[p]=1;
                c++;
            }
            z^=dp[max(c-2,0ll)];
        }
    }
    if(z){
        printf("First\n");
    }else{
        printf("Second\n");
    }
}