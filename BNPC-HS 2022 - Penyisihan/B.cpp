#include <stdio.h>
int main(){int n;scanf("%d", &n);char arr[5] = {'w','a','d','i'};for(int i = 0; i <= (n/2); i++){printf("%c", arr[i%4]);}for(int i = (n/2)-1; i>=0; i--){printf("%c", arr[i%4]);}puts("");return 0;}