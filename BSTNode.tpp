template <class key_t, class val_t>
BSTNode<key_t, val_t>::BSTNode(const key_t& k, const val_t& v){
    key = k;
    val = v;
    leftChild = 0;
    rightChild = 0;
    parent = 0;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>::~BSTNode(){

}

template <class key_t, class val_t>
const val_t& BSTNode<key_t, val_t>::getValue(){
    return val;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setValue(const val_t& val){
    this->val = val;
}

template <class key_t, class val_t>
const key_t& BSTNode<key_t, val_t>::getKey(){
    return key;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setKey(const key_t& key){
    this->key = key;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getLeftChild() const{
    return leftChild;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setLeftChild(BSTNode* child){
    leftChild = child;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getRightChild() const{
    return rightChild;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setRightChild(BSTNode* child){
    rightChild = child;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getParent() const{
    return parent;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setParent(BSTNode* parent){
    this->parent = parent;
}
