#include<stdio.h>
void swap(int *C, int *D){
    int d;
    d = *C;
    *C= *D;
    *D = d;
}
void Heapify(int *A, int n, int i){ 
    int largest = i;
    int left = 2*i +1;
    int right = 2*i + 2;
    if (left < n && *(A+left) > *(A+largest)){
        largest = left;
    }
    if (right < n && *(A+right) > *(A+largest)){
        largest = right;
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
    printf("\n");
}

int main (){
    int arrayToSort[] = { 9, 11, 22, -4, -3, 2, 7, 12, -2 };
    int n = sizeof(arrayToSort)/sizeof(arrayToSort[0]);
    printf("%ld", sizeof(arrayToSort));
    printf("Array we should sort: \n");
    for(int i = 0; i < n; i++){
    printf("%d ", arrayToSort[i]);
    }
    printf("\n");
    heapSort(arrayToSort, n);
    printf("Final Array Is\n");
    printArray(arrayToSort, n);
    return 0;
    }