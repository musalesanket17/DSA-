#include<stdio.h> 

#define SIZE 10 
int comparisons = 0; 

void display_array_elements(int arr[]); 
int linear_search( int arr[] , int key ); 
int binarysearch( int arr[] , int key ); 
int main( )
{
    int arr[SIZE] = {10,20,30,40,50,60,70,80,90,100};
    int key; 

    display_array_elements(arr); 
    printf("Enter the key element"); 
    scanf("%d",&key); 
    //if(linear_search(arr,key)) 
    if(binarysearch(arr,key))
    {
         printf("%d is found in an array , no of comparisons are %d :\n",key,comparisons); 
    }
    else
    {
          printf("%d is not found in an array , no of comparisons are %d :\n",key,comparisons); 
    }
    return 0; 
}

int binarysearch( int arr[] , int key )
{
    int left = 0;
    int right = SIZE - 1; 
    comparisons = 0; 

    while(left<=right)
    {
        int mid = (left + right) / 2;
        comparisons++;  
        if(key == arr[mid])
            return 1;
        if(key < arr[mid])    
           right = mid - 1;
        else 
           left = mid + 1;       

    }
    return 0; 

}


int linear_search( int arr[] , int key )
{
       int index = 0; 
       comparisons = 0;  
       for(index = 0 ; index < SIZE ; index++)
       {
            comparisons++;  
            if(key == arr[index])
                 return 1;  // return true => if key is found  
       }
    return 0;    
}


void display_array_elements(int arr[])
{
    int index; 
    for(index = 0 ; index< SIZE ; index++)
            printf("%4d",arr[index]); 
    printf("\n");    
}

