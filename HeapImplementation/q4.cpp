#include <iostream> 
#include "maxheap.h"
#define Random(x) (rand() % x)

template <class T>
void HeapSort(T a[], int n) {
    T b[n*2];
    T temp;
    MaxHeap<T> *maxHeap=new MaxHeap<T>;
    
    for (int i=1; i<=n; i++) {
        b[i]=a[i];
    }

    maxHeap->Initialize(b, n, sizeof(b));
    for (int i=1; i<=n; i++)
    {
        a[i]=maxHeap->Max();
        maxHeap->DeleteMax(temp);
    }
}

int main(){
 
	int a[11], i, n = 10; 
	// initialize descending data 
	for (i = 1; i <= 10; i++) 
		a[i] = Random(100);
	
	HeapSort(a,10); 
	
	// output sorted data 
	for (i = 1; i <= n; i++) 
		cout << a[i] << ' '; 
	
	cout << endl; 
	return 0;
}
