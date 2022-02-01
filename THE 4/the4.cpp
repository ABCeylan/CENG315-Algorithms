#include "the4.h"



int recursive_sln(int i, int*& arr, int &number_of_calls){ //direct recursive
    number_of_calls+=1;

    int a, b, max;
    
    
    if(i == 0)
    return arr[0];
    
    if(i == 1)
    return std::max(arr[1], arr[0]);
    
    if(i == 2){
        max = std::max(arr[1], arr[0]);
        return std::max(arr[2], max);
    }
    
    a = recursive_sln(i-3, arr, number_of_calls) + arr[i];
    b = recursive_sln(i-1, arr, number_of_calls);
    
    return std::max(a,b); 
}



int memoization_sln(int i, int*& arr, int*& mem){ //memoization


    int max;
    
    if (i == 0)
    {
        mem[0] = std::max(arr[0],0);
    }
    else if (i == 1)
    {
        mem[0] = std::max(arr[0],0);
        mem[1] = std::max(arr[1],mem[0]);
    }
    else if (i >= 2)
    {
        mem[0] = std::max(arr[0],0);
        mem[1] = std::max(arr[1], mem[0]);

        
        max = std::max(arr[0],0);
        max= std::max(arr[1],max);
        max = std::max(arr[2],max);
        mem[2] = max;

        int k = 3;
        while (k < i + 1)
        {
            mem[k] = std::max(mem[k - 1],(arr[k] + mem[k - 3]));
            k++;
        }
    }
    return mem[i]; 

    
}



int dp_sln(int size, int*& arr, int*& mem){ //dynamic programming

    int i = 3;
 
    if (size == 1) {
 
        mem[0] = std::max(0, arr[0]);
    }
 
    else if (size == 2) {
 
        mem[0] = std::max(0, arr[0]);
        mem[1] = std::max(arr[1], mem[0]);
    }
    else if (size >= 3) {
 
        mem[0] = std::max(0, arr[0]);
 
        mem[1] = std::max(arr[1], std::max(0, arr[0]));
 
        mem[2] = std::max(arr[2], std::max(arr[1], std::max(0, arr[0])));
 
        
 
        while (i < size) {
 
            mem[i] = std::max(mem[i - 1], arr[i] + mem[i - 3]);
            i++;
        }
    }
 
    return mem[size - 1];

    
}

