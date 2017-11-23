#include <iostream>
#include "lqueue.h"

using namespace std;

template<class T>
class BinaryTree;


template <class T>
class BinaryTreeNode{

	friend class BinaryTree<T>;
	
	private:
		T data;
		BinaryTreeNode *left;  //Left node
		BinaryTreeNode *right; //Right node

	public:
		BinaryTreeNode(){
			left = right = 0;
		}

		BinaryTreeNode(const T& element){
			data = element;
			left = right = 0;
		}

		BinaryTreeNode(const T& element, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r){
			data = element;
			left = l;
			right = r;
		}
};
 
template <class T> 
class BinaryTree{


	private:
		BinaryTreeNode<T> *root; //Root of the tree
			
		void PreOrder(BinaryTreeNode<T>* node){
			if(node){
				cout << node->data << " ";
				PreOrder(node->left);
				PreOrder(node->right);
			}
		}


		void InOrder(BinaryTreeNode<T>* node){
			if(node){
				InOrder(node->left);
				cout << node->data << " ";
				InOrder(node->right);
			}
		}


		void PostOrder(BinaryTreeNode<T>* node){
			if(node){
				PostOrder(node->left);
				PostOrder(node->right);
				cout << node->data << " ";
			}
		}


		void LevelOrder(BinaryTreeNode<T>* node){
			LinkedQueue<BinaryTreeNode<T>*> Q;
			BinaryTreeNode<T> *t;
			t = root;
			while (t) {
				cout << t->data << " ";
				if (t->left) Q.Add(t->left);
				if (t->right) Q.Add(t->right);
				try {Q.Delete(t);}
				catch (OutOfBounds) {return;}
			}
		}


	public:
        //get
        BinaryTreeNode<T>* getRoot(){return root;}
    
        //set
        void setRoot(BinaryTreeNode<T> *node){root=node;}
    
        //Create
		BinaryTree(){root = 0;}

		
		//IsEmpty
		bool IsEmpty() const{
			return (!root);
		}

		
		//Root
		bool Root(T& x) const{
			if(root){
				x = root->data;
			}
			
			return root;
		}


		//MakeTree
		void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right){
            
			root = new BinaryTreeNode<T>(element, left.root, right.root);
			left.root = right.root = 0;
		}


		//BreakTree
		void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right){
			if (!root) throw "BadInput";

			element = root->data;
			left.root = root->left;
			right.root = root->right;

			delete root;
			root = 0;
		}


		//PreOrder
		void PreOrder(){
			PreOrder(root);
		}


		//InOrder
		void InOrder(){
			InOrder(root);
		}


		//PostOrder
		void PostOrder(){
			PostOrder(root);
		}


		//LevelOrder
		void LevelOrder(){
			LevelOrder(root);
		}


        //Check whether it is a max heap
		bool HasHeapProperty(BinaryTreeNode<T> *node){
            if (node) {
                BinaryTreeNode<T> *leftChild,*rightChild;
                bool l=true,r=true;
                
                if (node->left) {
                    leftChild=node->left;
                    if (leftChild->data<node->data) {
                        l=HasHeapProperty(leftChild);
                    }
                    else {return false;}
                }
                
                
                if (node->right) {
                    rightChild=node->right;
                    if (rightChild->data<node->data) {
                        r=HasHeapProperty(rightChild);
                    }
                    else {return false;}
                }
                
                return l&&r;
            }
            else {return true;}
		}
};

