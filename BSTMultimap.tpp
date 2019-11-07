template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap(){
    sentinel = 0;
    root = sentinel;
    numItems = 0;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& val){
    BSTNode<key_t, val_t>* node = new BSTNode<key_t, val_t>(key, val);
    
    BSTNode<key_t, val_t>* x;
    BSTNode<key_t, val_t>* y;

    y = sentinel;
    x = root;

    while(x != 0){
        y = x;

        if(key < x->getKey()){
            x = x->getLeftChild();
        }
        else{
            x = x->getRightChild();
        }
    }

    node->setParent(y);
    
    if(y == 0){
        root = node;
    }
    else if(key < y->getKey()){
        y->setLeftChild(node);
    }
    else{
        y->setRightChild(node);
    }
    
    numItems++;
}

template <class key_t, class val_t>
int BSTMultimap<key_t, val_t>::getSize(){
    return numItems;
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::isEmpty(){
    return (numItems == 0)? true : false;
}

template <class key_t, class val_t>
string BSTMultimap<key_t, val_t>::toString(){
    queue<BSTNode<key_t, val_t>*> q;
    q.push(root);
    BSTNode<key_t, val_t>* cur; 

    string outStr = "";
    while(!q.empty()){
        cur = q.front();
        q.pop();
        outStr += "(" + to_string(cur->getKey()) + ", " + to_string(cur->getValue()) + ")-";
        if(cur->getLeftChild() != 0){
            q.push(cur->getLeftChild());
        }
        if(cur->getRightChild() != 0){
            q.push(cur->getRightChild());
        }
    }

    return outStr;
}