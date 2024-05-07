#include<stdio.h>
int main(){
    int i,j;
    int coins[] = {10,2,5,1,20};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount;
    printf("Enter amount : ");
    scanf("%d",&amount);
    //sorting coins in descending order
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(coins[i]<coins[j]){
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
    int selected[50];
    int sel_count = 0;
    for (i = 0; i < n; i++) {
        while (coins[i] <= amount) {
            amount = amount - coins[i];
            selected[sel_count] = coins[i];
            sel_count++;
        }
    }
    printf("No. of coins : %d\n",sel_count);
    printf("Coins selected are : \n");
    for(i=0;i<sel_count;i++){
        printf("%d ",selected[i]);
    }
    return 0;
}