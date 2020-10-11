#include<stdio.h>
#define BN 9
void swap(int *C, int *D){
    int d;
    d = *C;
    *C= *D;
    *D = d;
}
int Heapify(int *A, int i, int n){
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;
    if (l < n && A+l > A+largest){
        largest = l;
    }
    if (r < n && A+r > A+largest){
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
    for(int i = 0; i < n; ++i){
        printf("%d ", A[i]);
        printf("\n");
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