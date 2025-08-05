#include<stdio.h>
void print_array(int* a,int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void reverse_arr(int* a,int size)
{
    int temp=0;
    for(int i=0; i<size/2; i++)
    {
        temp = a[i];
        a[i] = a[size-i-1];
        a[size-i-1] = temp;
    }
}
void multiplication(int* arr1,int size1,int* arr2,int size2)
{
    int result[size1+size2];
    reverse_arr(arr1,size1);
    reverse_arr(arr2,size2);
    for(int i=0; i<size2; i++)
    {
        int k = i;
        int carry = 0,mul = 0;
        for(int j=0; j<size1; j++)
        {
            mul = arr2[i]*arr1[j];
            // printf("%d*%d\n",arr2[i],arr1[j]);
            if(i == 0){mul += carry;}
            else{mul = mul + carry + result[k];}            
            carry = mul/10;
            result[k++] = mul%10;
            if(j == size1-1)
            {result[k] = carry;}
            // print_array(result,size1+size2);
        }
        // print_array(result,size1+size2);
    }
    // print_array(result,size1+size2);
    reverse_arr(result,size1+size2);
    print_array(result,size1+size2);
}
int main()
{
    int arr1[3] = {1,2,1}, arr2[2] = {1,1};
    multiplication(arr1,3,arr2,2);

}
