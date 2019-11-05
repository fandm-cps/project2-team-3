#ifndef BST_Node
#define BST_Node

//#include "List.hpp"

template <class key_t, class val_t>
class BSTNode 
{

private:
	key_t key;
	val_t val;
  BSTNode<key_t, val_t>* rightChild;
	BSTNode<key_t, val_t>* leftChild;
	BSTNode<key_t, val_t>* parent;

public:

  //BSTNode();

BSTNode(const key_t &key, const val_t &val);

//Return a given value in the BST
val_t getVal(const val_t val);

//Sets value of a node in BST
void setVal(const val_t val);

//Return a given key in the BST
key_t getKey(const key_t key);

//Sets a key in BST
void setKey(const key_t val);

//return the left  child of a node
BSTNode getLeftChild();

//set the left child of the node at hand
void setLeftChild(BSTNode left);

//return the right  child of a node
BSTNode getRightChild();

//set the right child of the node at hand
void setRightChild(BSTNode right);

//return the parent of the node at hand
BSTNode getParent();

//set the parent of the param node
  void setParent(BSTNode par);

};

#include "BSTNode.tpp"
#endif
