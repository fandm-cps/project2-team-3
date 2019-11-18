#include <iostream>
using namespace std;

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
    if(root != sentinel){
        queue<BSTNode<key_t, val_t>*> q;
        q.push(root);
        BSTNode<key_t, val_t>* cur; 

        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur->getLeftChild() != sentinel){
                q.push(cur->getLeftChild());
            }
            if(cur->getRightChild() != sentinel){
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
    if(root == sentinel){
        return false;
    }
    
    queue<BSTNode<key_t, val_t>*> q;
    q.push(root);
    BSTNode<key_t, val_t>* cur; 

    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur->getLeftChild() != sentinel){
            q.push(cur->getLeftChild());
        }
        if(cur->getRightChild() != sentinel){
            q.push(cur->getRightChild());
        }
        if(cur->getKey() == key){
            return true;
        }
    }
    return false;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insertNode(BSTNode<key_t, val_t>* newNode){

}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& val){
    BSTNode<key_t, val_t>* node = new BSTNode<key_t, val_t>(key, val);
    
    node->setRightChild(sentinel);
    node->setLeftChild(sentinel);

    BSTNode<key_t, val_t>* cur;
    BSTNode<key_t, val_t>* par;

    par = sentinel;
    cur = root;

    while(cur != sentinel){
        par = cur;

        if(key < cur->getKey()){
            cur = cur->getLeftChild();
        }
        else{
            cur = cur->getRightChild();
        }
    }

    node->setParent(par);
    
    if(par == sentinel){
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
        if(cur->getLeftChild() != sentinel){
            q.push(cur->getLeftChild());
        }
        if(cur->getRightChild() != sentinel){
            q.push(cur->getRightChild());
        }
    }

    return outStr;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMin() const{

    BSTNode<key_t, val_t>* runner = this->root;

    if (runner == this->sentinel){
        return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
    }

    while (runner->getLeftChild() != sentinel){
        runner = runner->getLeftChild();
    }
    return BSTForwardIterator<key_t, val_t>(runner, sentinel);
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMax() const{

    BSTNode<key_t, val_t>* runner = this->root;

    if (runner == sentinel){
        return  BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
    }

    while (runner->getRightChild() != sentinel){
        runner = runner->getRightChild();
    }
    return  BSTForwardIterator<key_t, val_t>(runner, sentinel);   
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findFirst(const key_t& key) const{

    if(!contains(key)){
        return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
    }

    BSTNode<key_t, val_t>* runner = this->root;

    while(runner != this->sentinel){ 

        if (runner->getKey() == key){
            return BSTForwardIterator<key_t, val_t>(runner, sentinel);
        }
        else if(key < runner->getKey()){
            runner = runner->getLeftChild();
        }
        else{
            runner = runner->getRightChild();
        }
    }
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findLast(const key_t& key) const{

    if (this->numItems == 0){
        return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
    }
    else if(!contains(key)){
        return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
    }

    BSTNode<key_t, val_t>* runner = this->root;
    BSTNode<key_t, val_t>* last = this->sentinel;

    while (runner != this->sentinel){

        if (runner->getKey() == key){
            last = runner;
        }
        if (key < runner->getKey()){
            runner = runner->getLeftChild();
        }
        else{
            runner = runner->getRightChild();
        }    
    }

    return BSTForwardIterator<key_t, val_t>(last, sentinel);
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* u, BSTNode<key_t, val_t>* v){

    BSTNode<key_t, val_t>* uPar = u->getParent();
    
    if (u->getParent() == sentinel){
        this->root = v; 
    }
    else if (u == uPar->getLeftChild()){
        uPar->setLeftChild(v);
    }
    else{
	    uPar->setRightChild(v);
    }
  
    if (v != this->sentinel){
        v->setParent(uPar);
    }
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos){

    BSTNode<key_t, val_t>* runner = pos.current;
    BSTForwardIterator<key_t, val_t> succ = pos;

    if (runner->getLeftChild() == sentinel){
        this->transplant(runner, runner->getRightChild());
    }
    else if(runner->getRightChild() == sentinel){

        this->transplant(runner, runner->getLeftChild());
    }
    else{
        BSTNode<key_t, val_t>* tmpNode = runner->getRightChild();
        while (tmpNode->getLeftChild() != sentinel){
            tmpNode = tmpNode->getLeftChild();
        }

        if (tmpNode->getParent() != runner){
            this->transplant(tmpNode, tmpNode->getRightChild());
            tmpNode->setRightChild(runner->getRightChild());
            tmpNode->getRightChild()->setParent(tmpNode);
        }

        this->transplant(runner, tmpNode);
        tmpNode->setLeftChild(runner->getLeftChild());
        tmpNode->getLeftChild()->setParent(tmpNode);
    }
    if(numItems > 0){
        numItems--;
    }
    succ.next();
    return succ;
}