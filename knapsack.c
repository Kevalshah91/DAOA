#include<stdio.h>
void main(){
    int n,capacity,i,j;
    printf("Enter the number of items : ");
    scanf("%d",&n);
    int profit[n];
    int weights[n];
    printf("Enter maximum capacity : ");
    scanf("%d",&capacity);
    printf("Enter profits and weights of items:\n");
    for (i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d : ", i + 1);
        scanf("%d %d", &profit[i], &weights[i]);
    }
    // Finding ratio 
    float ratio[n];
    for(i=0;i<n;i++){
        ratio[i] = (float)profit[i] / weights[i];
    }
    // sort in descending order
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(ratio[i] > ratio[j]){
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }
        }
    }

    printf("Profits \t weights \t ratio \n");
    for(i=0;i<n;i++){
        printf("%d\t\t %d\t\t %.2f\n",profit[i],weights[i],ratio[i]);
    }
    float max_profit = 0;
    float current_weight = 0;
    for(i = 0; i < n; i++){
        if(current_weight + weights[i] <= capacity){
            max_profit += profit[i];
            current_weight += weights[i];
        } 
        else {
            max_profit += (capacity - current_weight) * ratio[i];
            break;
        }
    }
    printf("Maximum profit : %.2f\n", max_profit);
}