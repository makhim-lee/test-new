if(heap[2*i] < heap[2*i+1]) tem(&heap[2*i], &heap[2*i+1]);

        if(heap[2*i] > heap[i]){
            tem(&heap[2*i], &heap[i]);
            if((i%2 == 1) && (heap[i] > heap[(i-1)/2]) ) i = (i-1)/2;
            else if((i%2 == 0) && (heap[i] > heap[i/2]) ) i /= 2;
        }else{
            ++i;
            if(2*i < mid && heap[2*i] < heap[i]) tem(&heap[2*i], &heap[i]);