#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


#include<functional>
#include<iostream>
#include<assert.h>
#include"bstnode.h"

template<typename Item>
class BinarySearchTree {

public:
	// Public Interface Functions: All of these are implemented
	BinarySearchTree();
	~BinarySearchTree();

	void	printInorder();
	void	printPostorder();
	void	printPreorder();
	void	insert(Item item);

	void	remove(Item item);

	Item	min() const;
	Item	max() const;
	int		height() const;
	bool	search(Item item) const;

	bool	empty() const;

	void	printTree() const;

private:

	// Member variable root
	Node<Item>* root;

	//Auxillary recursive bst functions
	//public interface functions call these
	//You will implement these functions.

	// Tree traversal, second parameter is a "function" with 
	// return type void and parameter Node*, i.e: 
	//					void process(Node* )
	void inorder(Node<Item>* node, std::function<void(Node<Item>*)> proc);
	void preorder(Node<Item>* node, std::function<void(Node<Item>*)> proc);
	void postorder(Node<Item>* node, std::function<void(Node<Item>*)> proc);

	Node<Item>* min(Node<Item> *node) const;
	Node<Item>* max(Node<Item> *node) const;
	int   height(Node<Item>* node) const;

	Node<Item>* insert(Node<Item> *node, Item item);
	bool  search(Node<Item> *node, Item item) const;

	Node<Item>* remove(Node<Item> *node, Item item);

	void  printTree(Node<Item> *node, int space) const;
};


//----------------------------------------------------------
//-------------- Binary Search Tree Function Implementations 
// 
//  Public Interface functions
// 		Completley Implemented, nothing to do.  These functions 
//      call the recursive helper functions you will implement
//		below.

// Constructor
template<typename Item>
BinarySearchTree<Item>::BinarySearchTree() :root(nullptr) {}

// Destructor
template<typename Item>
BinarySearchTree<Item>::~BinarySearchTree() {

	//Use the post order traversal to delete the nodes.
	//lambda function to delete a node n: 
	//				[](Node* n) {delete n; } 
	postorder(root, [](Node<Item>* n) {delete n; });
}
template<typename Item>
void BinarySearchTree<Item>::printInorder() {

	//Use inorder traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item() << std::endl; }"
	inorder(root, [](Node<Item>* n) {std::cout << n->item() << " "; });

	std::cout << std::endl;
}
template<typename Item>
void BinarySearchTree<Item>::printPreorder() {

	//Use pre order traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item() << std::endl; }"
	preorder(root, [](Node<Item>* n) {std::cout << n->item() << " "; });
	std::cout << std::endl;
}
template<typename Item>
void BinarySearchTree<Item>::printPostorder() {

	//Use post order traversal to print items in a node in the tree.
	//lambda function to print the item in a node:
	//lambda to print->	"[](Node* n) {std::cout << n->item() << std::endl; }"
	postorder(root, [](Node<Item>* n) {std::cout << n->item() << " "; });
	std::cout << std::endl;
}
template<typename Item>
void BinarySearchTree<Item>::insert(Item item) {
	root = insert(root, item);
}
template<typename Item>
void BinarySearchTree<Item>::remove(Item item) {
	root = remove(root, item);
}
template<typename Item>
Item	BinarySearchTree<Item>::min() const {

	assert(root != nullptr);

	Node<Item>* node = min(root);
	return node->item();
}
template<typename Item>
Item	BinarySearchTree<Item>::max() const {

	assert(root != nullptr);

	Node<Item>* node = max(root);
	return node->item();
}
template<typename Item>
int	BinarySearchTree<Item>::height() const {

	return height(root);
}
template<typename Item>
bool BinarySearchTree<Item>::search(Item item) const {
	return search(root, item);
}
template<typename Item>
bool BinarySearchTree<Item>::empty() const {
	return (root == nullptr);
}
template<typename Item>
void BinarySearchTree<Item>::printTree() const {
	printTree(root, 0);
}

//----------------------------------------------------------
//
// Private Recursive Functions: You Implement These.
//

// Inorder Traversal: Implemented so you can see how passing a function into 
// another function works, other traversals remain for you to implement.  the second
// parameter, proc, is a function and we see that its return type is void and it 
// has a Node* as a parameter.  Any function of that form passed into inorder will be
// called as seen below.  
// If we assume that we use the printing lambda defined above you can imagine that proc 
// is defined as:
//		void proc(Node<Item> * n){std::cout << n->item() << " "; }
template<typename Item>
void BinarySearchTree<Item>::inorder(Node<Item>* node, std::function<void(Node<Item>*)> proc) {
	if (node == nullptr)
		return;

	inorder(node->left(), proc);
	proc(node);
	inorder(node->right(), proc);

}

template<typename Item>
void BinarySearchTree<Item>::postorder(Node<Item>* node, std::function<void(Node<Item>*)> proc) {

	//******** TODO *********

}
template<typename Item>
void BinarySearchTree<Item>::preorder(Node<Item>* node, std::function<void(Node<Item>*)> proc) {
	if (node == nullptr)
		return;

	proc(node);
	preorder(node->left(), proc);
	preorder(node->right(), proc);
	
}

// BinarySearchTree::insert recursively inserts into the BST according 
// to the rules of the BST.  
template<typename Item>
Node<Item>* BinarySearchTree<Item>::insert(Node<Item>* node, Item item) {
	//node is root!

	//root = insert(root, item);

	if (node == nullptr) {
		node = new Node<Item>;
		node->item(item);
		return node;
	}

	if (node->item() == item) {
		return node;
	}

	if (node->item() > item) {
		if (node->left() == nullptr) 
		{
			node->left(new Node<Item>);
			node->left()->item(item);
			return node;
		}
	}

	if (node->item() < item) {
		if (node->right() == nullptr)
		{
			node->right(new Node<Item>);
			node->right()->item(item);
			return node;
		}
	}
	//if (node == nullptr) {
	//	Node<Item>* ptr = new Node<Item>();

	//	return ptr;
	//}

	// if (node->left()->item() < item) {
	//	insert(node->right(), item);
	//	return nullptr;
	//}

	//else if (node->right()->item() > item) {
	//	insert(node->left(), item);
	//	return nullptr;
	//}

	// if (node->left() == nullptr) {
	//	 new *Node nnode = Node();
	//	 node->right() = nnode;
	//	 node->right()->item(item);
	//	 return nullptr;
	//}

	//******** TODO *********
	return nullptr;
}

// BinarySearchTree<Item>::search recursively searches the tree for item.
template<typename Item>
bool BinarySearchTree<Item>::search(Node<Item>* node, Item item) const {

	//******** TODO *********
	return false;
}

// BinarySearchTree<Item>::height
// Height of a binary tree is the height of the largest subtree + 1
// An empty tree has height 0;
template<typename Item>
int	BinarySearchTree<Item>::height(Node<Item>* node) const {

	int counter = 1;

	if (node == nullptr) {
		return 0;
	}

	
	if (node->left() != nullptr) {
		//node = node->left();
		
		int answer = counter + height(node->left());
		return answer;
	}

	if (node->left() == nullptr && node->right() == nullptr) {
		return counter;
	}

	//return counter;
}

// BinarySearchTree<Item>::min recursively obtain the node with the minimum item
template<typename Item>
Node<Item>* BinarySearchTree<Item>::min(Node<Item>* node) const {

	if (node == nullptr)
		return nullptr;

	if (node->left() != nullptr) {
		min(node->left());
	}

	if (node->left() == nullptr) {
		return node;
	}

}

// BinarySearchTree<Item>::max recursively obtain the node with the minimum item
template<typename Item>
Node<Item>* BinarySearchTree<Item>::max(Node<Item>* node) const {

	if (node == nullptr)
		return nullptr;

	if (node->right() != nullptr) {
		max(node->right());
	}

	if (node->right() == nullptr) {
		return node;
	}

}

// BinarySearchTree<Item>::printTree
// Prints the BST in a tree format rotated -90 degrees.  Uses space to 
// signify the space between levels of the tree. Uses the inorder 
// traversal but traverses right first, rather than left. Cannot use
// any of the other travel functions because of this.
//
// parameter space determines the number of spaces needed for each level.
// Example binary shows 5 spaces between levels. 
//
// i.e. traverse right 
//		print appropriate number of spaces 
//		print item 
//		traverse left
//
// It never makes sense to use loops to facilitate increasing recursive depth
// But that doesn't mean you should not use loops for other purposes that are
// not related to the actuall recursion.  
template<typename Item>
void BinarySearchTree<Item>::printTree(Node<Item>* node, int space) const {

	//******** TODO *********

}


//BinarySearchTree<Item>::remove
//
// Make sure you're comfortable with the iterative solution seen in the lecture slides
// before thinking about how to do it recursively.
//
// Recursively removes a node in the binary tree.  The recursive algorithm will 
// be different than the iterative algorithm.  The iterative algorithm conisted
// of first finding the node using two pointers so that we know how to rearrange
// the children of the deleted node. In recursion we are passing in the sub trees
// each recursive step, so by definition we already have a handle on each subtrees'
// parents (it is the node that is passed into the previous recursive step).
// After we search the node to remove (if it is in the tree) everything else is the same, we  
// handle the three cases: leaf, one child (which consist of two cases: left vs right),
// and two children.  With iterative algorithm there were subcases regardling if the 
// node was root or not, with recursion we get that for free.  
//
// In the iterative algorithm discussed in class, in dealing with a node with two children
// We swapped items from one of the nodes in either subtree.  For the recursive algorithm
// We just want to write the subtree node's item into the node to be deleted, not actually 
// swap. This way subtree remains a valid bst, so we can recurse on that subtree and 
// recursively call _deleteNode on that item (not the original) to remove that node.  
// 
// It takes a bit to wrap your head around this, use the 6 steps, draw lots of pictures.
// 
template<typename Item>
Node<Item>* BinarySearchTree<Item>::remove(Node<Item>* node, Item item) {

	//******** TODO *********
	return nullptr;
}





































































// MMXM


























































#endif//BINARYSEARCHTREE_H_MMX