#include <stdio.h>
#define AN 5
#define BN 9
#define CN (AN + BN)
 
int* array_union(const int* f1, const int* l1,
                 const int* f2, const int* l2, int* d){
    while((f1 != l1) && (f2 != l2)){
        if(*f1 > *f2)
            *d++ = *f1++;
        else if(*f1 < *f2)
            *d++ = *f2++;   
        else {
            *d++ = *f1++;
            ++f2;
        }
    }
 
    while(f1 != l1)
        *d++ = *f1++;
    while(f2 != l2)
        *d++ = *f2++;
    return d;
}
 
int main(void){
    int c[CN], *p, *e;
    int a[AN] = { 9, 7, 5, 3, -1 };
    int b[BN] = { 9, 8, 6, 4, 3, 2, 1, 0, -2 };
 
    e = array_union(a, a + AN, b, b + BN, c);
    for(p = &c[0]; p != e; ++p)
        printf("%d ", *p);
    return 0;
}