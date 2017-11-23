#include "binarytree.h"
#include <iostream>

using namespace std;

int main(){

	BinaryTree<int> empty, t1, t2, t3, t4, heap, noHeap;
	
	heap.MakeTree(20, empty, empty);
	t1.MakeTree(40, empty, empty);
	t2.MakeTree(43, heap, t1);
	
	noHeap.MakeTree(20, empty, empty);
	t3.MakeTree(40, empty, empty);
	t4.MakeTree(15, noHeap, t3);
	
	noHeap.MakeTree(45, t4, empty);
	heap.MakeTree(45, t2, empty);

	if(heap.HasHeapProperty(heap.getRoot()) && !noHeap.HasHeapProperty(noHeap.getRoot())){
		cout << "Correct" << endl;
	}
	else{
		cout << "Incorrect" << endl;
	}
}
