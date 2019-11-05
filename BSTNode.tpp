#include <iostream>

template <class key_t, val_t>
BSTNode<key_t, val_t>::BSTNode(const key_t &newKey, const val_t &newVal){
	key = newKey;
	val = newVal;
	righChild = 0;
	leftChild = 0;
	parent = 0;
}

template <class key_t, val_t>
val_t BTSNode<key_t, val_t>::getVal(){
	return this.val;
}

template <class key_t, val_t>
void BTSNode<key_t, val_t>::setVal(val_t &newVal){
	val = newVal;
}

template <class key_t, val_t>
key_t BTSNode<key_t, val_t>::getKEy(){
	return this.key;
}

template <class key_t, val_t>
void BTSNode<key_t, val_t>::setKey(key_t_t &newKey){
	key = newKey;
}

template <class key_t, val_t>
BSTNode<key_t, val_t>* BTSNode<key_t, val_t>::getLeftChild(){
	return this->leftChild;
}

template <class key_t, val_t>
void BTSNode<key_t, val_t>::setLeftChild(BTSNode<key_t, val_t>* newLeft){
	leftChild = newLeft;
}

template <class key_t, val_t>
BSTNode<key_t, val_t>* BTSNode<key_t, val_t>::getRightChild(){
	return this->rightChild;
}

template <class key_t, val_t>
void BTSNode<key_t, val_t>::setRightChild(BTSNode<key_t, val_t>* newRight){
	rightChild = newRight;
}

template <class key_t, val_t>
BSTNode<key_t, val_t>* BTSNode<key_t, val_t>::getParent()
	return this->parent;
}

template <class key_t, val_t>
void BTSNode<key_t, val_t>::setParent(BTSNode<key_t, val_t>* newParent){
	parent = newParent;
}
