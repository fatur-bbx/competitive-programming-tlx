#include<stdio.h>
int main(){
    int tc;
    scanf("%d",&tc);getchar();
    
    int arr[tc];
    int bug_counter = 0;
    int temp = 0;
    for(int i = 0; i < tc; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < tc; i++){
        temp = 0;
        if(arr[i]<0){
            for(int j = 0; j<i+1;j++){
                if(arr[j]==arr[i]-arr[i]-arr[i]){
                    temp=0;
                    break;
                }else{
                    temp++;
                }
            }
        }
        if(temp!=0){
            bug_counter++;
        }
    }
    printf("%d\n",bug_counter);
}