 
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

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMin() const{

BSTNode<key_t, val_t>* runner = this->root;

if (runner == this->sentinel){

   return BSTForwardIterator<key_t, val_t>(0, 0);
   }

if (runner->getLeftChild() != sentinel){

   runner = runner->getLeftChild();
   return BSTForwardIterator<key_t, val_t>(runner, 0);
}
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMax() const{

BSTNode<key_t, val_t>* runner = this->root;

if (runner == sentinel){
   return  BSTForwardIterator<key_t, val_t>(0,0);
   }

while (runner->getRightChild() != sentinel){
   runner = runner->getRightChild();
}
return  BSTForwardIterator<key_t, val_t>(runner, 0);   
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findFirst(const key_t& key) const{


BSTNode<key_t, val_t>* runner;
runner = this->root;
BSTNode<key_t, val_t>* par;
par = this->sentinel;

 while(runner != this->sentinel && runner->getKey() != key){

 par = runner;

        if(key < runner->getKey()){
            runner = runner->getLeftChild();
        }
        else{
            runner = runner->getRightChild();
        }
    }
    
    if (par->getKey() != key)
    {

	return BSTForwardIterator<key_t, val_t>(sentinel, 0);
    }
    

 return BSTForwardIterator<key_t, val_t>(par, 0);
 }

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findLast(const key_t& key) const{

 BSTNode<key_t, val_t>* runner = this->root;
BSTNode<key_t, val_t>* last = this->sentinel;

while (runner != this->sentinel){


      //par = runner;

      if (key < runner->getKey()){

      	 runner = runner->getLeftChild();
      }
      else{

	runner = runner->getRightChild();
      }

      if (runner->getKey() == key){
      
      	 last = runner;
      }
}
if (last->getKey() != key){

   return BSTForwardIterator<key_t, val_t>(sentinel, 0);
}

return BSTForwardIterator<key_t, val_t>(last, 0);
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::transplant(const BSTNode<key_t, val_t>* u, const BSTNode<key_t, val_t>* v){

if (u->getParent() == this->sentinel){

   (this->root)->setKey(v->getKey());
   (this->root)->setValue(v->getValue());
}
else if (u == (u->getParet())->getLeftChild()){

     BSTNode<key_t, val_t>
}
}



template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::remove(
const BSTForwardIterator<key_t, val_t>& pos){

BSTNode<val_t, key_t>* runner = pos->current;
BSTNode<val_t, key_t>* ittSent = pos->sentinel;

if (runner->getLeftChild() == ittSent){

   if(runner->getParent() == ittSent){

   	runner = runner->getRightChild();
	}
	else if(runner == (runner->getParent())->getLeftChild) {

	(runner->getParent())->getLeftChild() = runner->getRightChild();
	}
	else{

	if (runner->getRightChild() == ittSent){

	(runner->getRightChild())->getParent() = runner->getParent();
	}
	}
}
else if(runner->getRightChild() == ittSent){

     if(runner->getParent() == ittSent){

     runner = runner->getLeftChild();
     }
     else if (runner == (runner->getParent())->getLeftChild()){

     (runner->getParent())->getLeftChild() = runner->
     }
}
}