#include<stdio.h>
void swap(int *C, int *D){
    int d;
    d = *C;
    *C= *D;
    *D = d;
}
void Heapify(int *A, int n, int i){ 
    int largest = i;
    int l = 2*i +1;
    int r = 2*i + 2;
    if (l < n && *(A+l) > *(A+largest)){
        largest = l;
    }
    if (r < n && *(A+r) > *(A+largest)){
        largest = r;
    }
    if (largest != i)
    {
        swap(A + i, A + largest);
        Heapify(A, n, largest);
    }

}
void heapSort(int A[], int n){ 
    for(int i = n/2 -1; i >=0;i--){
        Heapify(A,n,i);
    }

    for(int i = n - 1; i>= 0; i--){
        swap(A+0,A+i);
        Heapify(A, i, 0);
    }
}

void printArray(int A[], int n){
    for(int i = n-1; i >= 0; i--){
        printf("%d ", A[i]);
    }
}

int main (){
    int b[] = { 9, 11, 22, -4, -3, 2, 7, 12, -2 };
    int n = sizeof(b)/sizeof(b[0]);

    heapSort(b, n);
    printf("Final Array Is\n");
    printArray(b, n);
    return 0;
    }