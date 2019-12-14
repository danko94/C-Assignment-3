
#include <stdio.h>
#include <math.h>

#define ARR_SIZE 50

void shift_element(int* arr, int i)
{
    int* ptr = arr;
    arr+=i+1;
    for(;i>0;i--){
        *arr=*(arr-1);
        arr--;
    }
    arr = ptr;
}

void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
        if(i!=n-1)
		{
             printf("%d,", arr[i]);
        } 
        else
        {
            printf("%d", arr[i]);
        }
        
	printf("\n"); 
} 

void insertion_sort(int* arr, int len)
{
    int* ptr;
    ptr = arr;
    int i, key, j; 
	for (i = 1; i < len; i++) { 
        arr=ptr;
		key = *(arr+i); 
        
		
		if(*(arr+i)<*(arr+i-1))
		{
			j=0;
			while ((j<i)&&(key>*(arr+j)))
			{
				j++;
			}
			
            shift_element(arr+j-1, i-j);		
			*(arr+j)=key;
		} 
}
}

int main()
{
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if(scanf("%d", arr+i)==EOF)
            break;
    }
    
    int *ptr_arr;
    ptr_arr = arr;
    
	int n = sizeof(arr) / sizeof(*ptr_arr); 
    printf("%d\n", n);
	insertion_sort(arr, n); 
	printArray(arr, n); 
}