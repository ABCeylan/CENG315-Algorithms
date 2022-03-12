#include "the5.h"
// do not add extra libraries here

/*
W: the width of the field
L: the length of the field
partitions: 2D Boolean array for partitions, if a partition of w x l exists then partitions[x][y] is true.
numberOfCalls/numberOfIterations: method specific control parameter
*/

int recursiveMethod(int W, int L, bool** partitions, int* numberOfCalls){
	
	int absMin = 0;
	(*numberOfCalls)++;
	
	if(partitions[W][L] == false)
	{
	    int wastedArea = W*L;
	    int wastedArea2 = W*L;
	    int wastedArea3 = W*L;
	    
	    for(int M = 1; M <= W/2; M++){
	        int min = recursiveMethod(W - M, L, partitions, numberOfCalls) + recursiveMethod(M, L, partitions, numberOfCalls);
	        if(min < wastedArea2){
	            wastedArea2 = min;
	        }
	    }
	    for(int N = 1; N <= L/2; N++){
	        int min = recursiveMethod(W, L - N, partitions, numberOfCalls) + recursiveMethod(W, N, partitions, numberOfCalls);
	        if(min < wastedArea3){
	            wastedArea3 = min;
	        }
	    }
	    
	    absMin = std::min(W*L,std::min(wastedArea2, wastedArea3));
	    
	}

	    
	    
	return absMin;

	
}

int memo(int W, int L, bool** partitions, int* numberOfCalls, int** m){
	
	(*numberOfCalls)++;
	
	if(m[W][L] == INT_MIN) 
	{
	    if(partitions[W][L])
	    {
	        return 0;
	    }
	    else
	    {
    	    int wastedM = W*L;
    	    for(int M = 1; M <= W/2; M++){
    	        int min = memo(W - M, L, partitions, numberOfCalls, m) + memo(M, L, partitions, numberOfCalls, m);
    	        if(min < wastedM){
	                wastedM = min;
	            }
    	    }
    	    
    	    int wastedN = W*L;
    	    for(int N = 1; N <= L/2; N++){
    	        int min = memo(W, L - N, partitions, numberOfCalls, m) + memo(W, N, partitions, numberOfCalls, m);
    	        if(min < wastedN){
	                wastedN = min;
	            }

    	    }
    	    m[W][L] =  std::min(W*L, std::min(wastedM, wastedN));
    	}
	}
	
	return m[W][L];
	
}

int memoizationMethod(int W, int L, bool** partitions, int* numberOfCalls){
    (*numberOfCalls)++;
	
	
	int** m = new int*[W+1];
	for(int i = 0; i < W+1; i++){
		m[i] = new int[L+1];
		for (int j = 0; j < L+1; j++){
			m[i][j] = INT_MIN;
		}
	}
	
	return memo(W, L, partitions, numberOfCalls, m);
}



int bottomUpMethod(int W, int L, bool** partitions, int* numberOfIterations){
	return 0; // this is a dummy return value. YOU SHOULD CHANGE THIS!
}
