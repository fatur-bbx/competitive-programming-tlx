#include <stdio.h>

int main(){
    long long int k = 0, s = 0, n = 0;
    scanf("%lld %lld %lld", &k, &s, &n);
    if(n < k || n < k * s){
        printf("NO\n");
        return 0;
    }else{
        if(k==2&&n%2==1){
            printf("NO\n");
        }else{
            if(s == 1){
                long long int min = 2*k - 2;
                n -= min;
                if(n<=0)printf("YES\n");
                else if(n%2==1)printf("NO\n");
                else printf("YES\n");
            }
            else printf("YES\n");
            return 0;
        }
    }
}