#include<stdio.h>
void main()
{
  int s[50];
  int f[50];
  int a[50];
  int n;
  printf("Keval Shah 60009220061\n");
  printf("Enter number of processes : \n");
  scanf("%d",&n);
  printf("Enter starting time for the processes : \n");
  for(int i=0;i<n;i++){
      scanf("%d",&s[i]);
  }
  printf("Enter finish time for the processes : \n");
  for(int i=0;i<n;i++){
      scanf("%d",&f[i]);
  }
  for(int i=0;i<n;i++){
        a[i]=i+1;
  }
  
  int i,j,temp,prev;
  int sol[100],k;
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
      if(f[j]>f[j+1]){
    	 temp=f[j];
    	 f[j]=f[j+1];
    	 f[j+1]=temp;
    	 temp=s[j];
    	 s[j]=s[j+1];
    	 s[j+1]=temp;
    	 temp=a[j];
    	 a[j]=a[j+1];
    	 a[j+1]=temp;
      }
    }
  }
  sol[0]=a[0];
  k=1;
  prev=0;
  printf("The order of activities is : \n");
  printf("%d -> ",a[0]);
  for(i=1;i<n;i++){
    if(s[i]>=f[prev]){
      sol[k]=a[i];
      prev=i;
      k++;
      printf("%d -> ",a[i]);
    }
  }
  printf("\n");
}