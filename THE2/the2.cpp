#include "the2.h"

//You may write your own helper functions here

void swapHelper(unsigned short int* a,unsigned short int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partitionHelper1 (unsigned short *arr, int low, int high, long& swap, double & avg_dist, double & max_dist, double & total_dist) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
    
    double swap_dist;
    
  
    for (int j = low; j <= high - 1; j++) 
    { 
         
        if (arr[j] >= pivot) 
        { 
            i++; 
            swapHelper(&arr[i], &arr[j]);
            swap++;
            swap_dist = j - i;
            if(swap_dist > max_dist){
                max_dist = swap_dist;
            }
           total_dist += swap_dist; 
        } 
        
         
    } 
    swapHelper(&arr[i + 1], &arr[high]); 
    swap++;
    swap_dist = high -i -1;
    if(swap_dist > max_dist){
                max_dist = swap_dist;
    }
    total_dist += swap_dist;
    
    
    
    
    
    
    return (i + 1); 
} 

void quickSortHelper1(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, int size, int low, int high, double & total_dist){
    
    int pi;
    
    if(low < high){
        int pi = partitionHelper1(arr, low, high, swap, avg_dist, max_dist, total_dist);
        
        quickSortHelper1(arr, swap, avg_dist, max_dist, size, low, pi - 1, total_dist);
        quickSortHelper1(arr, swap, avg_dist, max_dist, size, pi + 1, high, total_dist);
    }
}



int partitionHelper2(unsigned short *arr, int size, long& swap, double & avg_dist, double & max_dist, double & total_dist)
{   
    int pivot = arr[(size-1)/2];
    int i = - 1;
    int j = size;
    double swap_dist;
    
    while (1)
    {
        do {
            j--;
        } while (arr[j] < pivot);
        
 
        do {
            i++;
        } while (arr[i] > pivot);
        
 
        if (i < j) {
            swapHelper(&arr[i], &arr[j]);
            swap++;
            swap_dist = j - i;
            total_dist += swap_dist;
            if(swap_dist > max_dist){
                max_dist = swap_dist;
            }
        }
        else{
            return j;
        }
   
    }
}

void quickSortHelper2(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, int size, double & total_dist){
    
    int pi;
    
    if(size > 1){
        pi = partitionHelper2(arr, size, swap, avg_dist, max_dist, total_dist);
        
        quickSortHelper2(arr, swap, avg_dist, max_dist, pi + 1, total_dist);
        quickSortHelper2(arr+pi+1, swap, avg_dist, max_dist, size -1 -pi, total_dist);
        
    }
        
}

void quickSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size)
{
    //Your code here
    
    int low, high;
    if(size <= 1){
        swap = 0;
        avg_dist = 0;
        max_dist = 0;
        
    }
    
    if(hoare == false && size > 1){
        low = 0;
        high = size - 1;
        double total_dist = 0;
        quickSortHelper1(arr, swap, avg_dist, max_dist, size, low, high, total_dist);
        if(swap != 0){
        avg_dist = total_dist / swap;
        }
    }
    
    if(hoare == true && size > 1){
        low = 0;
        high = size - 1;
        double total_dist = 0;
        quickSortHelper2(arr, swap, avg_dist, max_dist, size, total_dist);
        if(swap != 0){
        avg_dist = total_dist / swap;
        }
    }
	
}
int minOf(int a, int b){
    if(a < b){
        return a;
    }
    else if(a > b){
        return b;
    }
    else{
        return a;
    }
}

void partitionHelper3(unsigned short* arr, int size, long &swap, long& comparison, int & left, int & right) {
   int i = 0;
   int j = 0;
   int k;
   int m;
   int p = size -1;
   while(i<p){
       if(arr[i] > arr[size-1]){
           swapHelper(&arr[i], &arr[j]);
           swap++;
           i++;
           j++;
           comparison++;
       }
       else if(arr[i] == arr[size-1]){
           p--;
           swapHelper(&arr[i], &arr[p]);
           swap++;
           comparison += 2;
       }
       else{
           i++;
           comparison += 2;
       }
       
   }
   m = minOf(p-j, size-p);

   for( k = 0; k < m; k++){
       swapHelper(&arr[j+k], &arr[size-m+k]);
       swap++;
   }
   left = j;
   right = p - j;
   
   
}
void quickSortHelper3(unsigned short *arr, int size, long &swap, long& comparison){
    
   int left;
   int right;
   int i, j;
   if(size > 1){
   partitionHelper3(arr, size, swap, comparison, left , right);
   quickSortHelper3(arr, left, swap, comparison);
   quickSortHelper3(arr+size-right, right, swap, comparison);
   }
}
void quickSort3(unsigned short *arr, long &swap, long &comparison, int size) {
	
    //Your code here
	
	int left, right;
    if(size <= 1){
        swap = 0;
        comparison = 0;
        return;
        
    }
    left = 0;
    right = size - 1;
    quickSortHelper3(arr, size, swap, comparison);
}




























