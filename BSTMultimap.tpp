template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap(){
    sentinel = 0;
    root = sentinel;
    numItems = 0;
}

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::~BSTMultimap(){
    clear();
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::clear(){
    if(root != 0){
        queue<BSTNode<key_t, val_t>*> q;
        q.push(root);
        BSTNode<key_t, val_t>* cur; 

        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur->getLeftChild() != 0){
                q.push(cur->getLeftChild());
            }
            if(cur->getRightChild() != 0){
                q.push(cur->getRightChild());
            }
            delete cur;
        }

        root = sentinel;
        numItems = 0;
    }
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::contains(const key_t& key) const{
    if(root == 0){
        return false;
    }
    
    queue<BSTNode<key_t, val_t>*> q;
    q.push(root);
    BSTNode<key_t, val_t>* cur; 

    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur->getLeftChild() != 0){
            q.push(cur->getLeftChild());
        }
        if(cur->getRightChild() != 0){
            q.push(cur->getRightChild());
        }
        if(cur->getKey() == key){
            return true;
        }
    }
    return false;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& val){
    BSTNode<key_t, val_t>* node = new BSTNode<key_t, val_t>(key, val);
    
    BSTNode<key_t, val_t>* cur;
    BSTNode<key_t, val_t>* par;

    par = sentinel;
    cur = root;

    while(cur != 0){
        par = cur;

        if(key < cur->getKey()){
            cur = cur->getLeftChild();
        }
        else{
            cur = cur->getRightChild();
        }
    }

    node->setParent(par);
    
    if(par == 0){
        root = node;
    }
    else if(key < par->getKey()){
        par->setLeftChild(node);
    }
    else{
        par->setRightChild(node);
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