//힙sort
//n 2n 2n+1


#include<stdio.h>
#include<stdlib.h>

void tem(int *A, int *B){
    int tem = *A;
    *A = *B;
    *B = tem;
}

int main(void)
{
    int heap[] = {1,2,3,4,5,6,7,8,9,10};
    int mid = (sizeof(heap)/4 + 1) / 2;


    for (int i = 0; i < mid; ){
        if(heap[2*i] < heap[2*i+1]) tem(&heap[2*i], &heap[2*i+1]);

        if(heap[2*i] > heap[i]){
            tem(&heap[2*i], &heap[i]);
            if((i%2 == 1) && (heap[i] > heap[(i-1)/2]) ) i = (i-1)/2;
            else if((i%2 == 0) && (heap[i] > heap[i/2]) ) i /= 2;
        }else{ 
            ++i;
            if(2*i < mid && heap[2*i] < heap[i]) tem(&heap[2*i], &heap[i]);
        }
        //if(heap[2*(i-1)] < heap[2*(i-1)+1]) tem(&heap[2*(i-1)], &heap[2*(i-1)+1]);
    }

    for(int i = 0; i < 10; ++i){
        printf("%d\n", heap[i]);
    }
    return 0;
}


// else if(heap[2*i] < heap[2*i+1] && heap[2*i+1] > heap[i]){
//             tem(&heap[2*i+1], &heap[i]);
//             if(i != 1){
//                 if(i%2 == 1){
//                     if(heap[i] > heap[(i-1)/2]){
//                         i = (i-1)/2;
//                     }else ++i;
//                 }else{
//                     if(heap[i] > heap[i/2]){
//                         i /= 2;
//                     }else ++i;
//                 }    
//             }else ++i;