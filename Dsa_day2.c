
#include <stdio.h>

int main() {
  int a,pos,n,arr[50],i;
  printf("Enter the size of array:");
  scanf("%d",&n);
  printf("Enter the elements of array:");
  for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
  }
  printf("Enter the position of the element you want to delete:");
  scanf("%d",&pos);
  for(i=pos-1;i<n;i++){
      arr[i]=arr[i+1];
  }
  n--;
  printf("New array after deletion is:");
   for(i=0;i<n;i++){
     printf("%d ",arr[i]);
  }
    return 0;
}

