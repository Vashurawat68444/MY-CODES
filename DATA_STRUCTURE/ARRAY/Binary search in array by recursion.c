#include<stdio.h>
binary_search(int arr[],int UB, int LB, int input ){
      if(LB<=UB){ int mid=(UB+LB)/2;
       if(arr[mid] == input)
       return mid;
       if(arr[mid] >input)
       return binary_search(arr,UB-1,LB,input);
       return binary_search(arr,UB,LB+1,input);
      }
      return -1;
     }
int main()
{
    //printf("input Array should be in Ascending order \n\n");
    int UB,LB,mid,input;
    printf("Enter the LB and UB in array : ");
    scanf("%d %d",&LB ,&UB);//here we declere upper and lower bound 
    int p=UB+1;
    int arr[p];//on the basis of upper and lower bound i declere size of array
    for (int i=0; i<=UB; i++)//in this loop i'll get input for my array
    {
        printf("Enter elements at index %d : ",i);
        scanf("%d",&arr[i]);
    }
    printf("Enter input which you want to search : ");
    scanf("%d",&input);
    mid = binary_search(arr,UB,LB,input);  //through this function i found the mid element
    if(mid==-1)//if element is not present then this part will run 
    printf("Element is not present");
     
    else printf("Index in array for given input : %d",mid);
}

    