#include <iostream>
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

    node->setRightChild(sentinel);
    node->setLeftChild(sentinel);
    
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

   return BSTForwardIterator<key_t, val_t>(sentinel, 0);
   }

while (runner->getLeftChild() != sentinel){

   runner = runner->getLeftChild();
}
return BSTForwardIterator<key_t, val_t>(runner, 0);
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
return  BSTForwardIterator<key_t, val_t>(runner, 0);   
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findFirst(const key_t& key) const{


BSTNode<key_t, val_t>* runner;
runner = this->root;
BSTNode<key_t, val_t>* par;
par = this->root;
int loops = 0;
//std::cout << "sentkey: " << (sentinel->getKey()) << std::endl;
//std::cout << "sentkey: " << (sentinel->getKey()) << std::endl;

if (this->numItems == 0){

   return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
}

if (this->root->getKey() == key){
   return BSTForwardIterator<key_t, val_t>(root, sentinel);
}

while(runner != this->sentinel){ 

//std::cout << "loops: " << loops << std::endl;

loops = loops + 1;
 par = runner;

        if(key < runner->getKey()){
            runner = runner->getLeftChild();
        }
        else{
            runner = runner->getRightChild();
        }
	//std::cout << "parVal: " << par->getValue() << std::endl;
    }
    
    if (par->getKey() != key)
    {
	
	return BSTForwardIterator<key_t, val_t>(sentinel, sentinel);
    }
    

 return BSTForwardIterator<key_t, val_t>(par, 0);
 }

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findLast(const key_t& key) const{

 BSTNode<key_t, val_t>* runner = this->root;
BSTNode<key_t, val_t>* last = this->sentinel;

if (runner->getKey() == key){

   return BSTForwardIterator<key_t, val_t>(runner, 0);
}

while (runner != this->sentinel){


      //par = runner;

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
if (last->getKey() != key){

   return BSTForwardIterator<key_t, val_t>(sentinel, 0);
}

return BSTForwardIterator<key_t, val_t>(last, 0);
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* u, BSTNode<key_t, val_t>* v){
  std::cout << "uVal: " << u->getValue() << std::endl;
  //std::cout << "vVal: " << v->getValue() << std::endl;
  bool tf = true;
  if (v != this->sentinel){
    tf = false;
    }
  std::cout << "is v = sent? " << tf << endl;
  std::cout << "TF: " << (u->getParent())->getLeftChild()->getValue() << std::endl;
if (u->getParent() == sentinel){
  std::cout << "First if? " << std::endl;
   (this->root)->setKey(v->getKey());
   (this->root)->setValue(v->getValue());
}
else if (u == (u->getParent())->getLeftChild()){
  std::cout << "u == uPL" << std::endl;
     BSTNode<key_t, val_t>* parLeft = (u->getParent())->getLeftChild();
     if (v != this-> sentinel){
       if (v->getKey() < parLeft->getKey())
	 {
	   parLeft->setLeftChild(v);
	 }
       else{
	 std::cout << "final transplant else" << std::endl;
	 parLeft->setRightChild(v);
       }
     }
     parLeft->setLeftChild(v);
     //parLeft->setKey(v->getKey());
     //parLeft->setValue(v->getValue());
     std::cout << "done u == uPL" << std::endl;
}
else{
  std::cout << "Ohhhh here" << std::endl;
	BSTNode<key_t, val_t>* par = (u->getParent());
	par->setRightChild(v);
	//parRight->setKey(v->getKey());
	//parRight->setValue(v->getValue());
	}
std::cout << "Out of If/Else" << std::endl;
if (v != this->sentinel){
  std::cout << "Not Sent" << std::endl;
  //BSTNode<key_t, val_t>* vP = v->getParent();
   std::cout << "Here" << std::endl;
   BSTNode<key_t, val_t>* uP = u->getParent();
   v->setParent(uP);
   std::cout << "Here2" << std::endl;
   //vP->setKey(uP->getKey());
   //vP->setValue(uP->getValue());
}

}



template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::remove(
const BSTForwardIterator<key_t, val_t>& pos){

BSTNode<key_t, val_t>* runner = pos.current;
BSTForwardIterator<key_t, val_t> succ = pos;
succ.next();

if (runner->getLeftChild() == sentinel){

   this->transplant(runner, runner->getRightChild());
}
else if(runner->getRightChild() == sentinel){

    this->transplant(runner, runner->getLeftChild());
}
else{
std::cout << "in the part with two children" << std::endl;
	BSTNode<key_t, val_t>* tmpNode = runner->getRightChild();
	//std::cout << "left childs val: " << tmpNode->getLeftChild()->getValue() << std::endl;
	int loops = 0;
	while (tmpNode->getLeftChild() != sentinel){
	std::cout << "in the while loop with two children" << std::endl;
	std::cout << "loops: " << loops << std::endl;
	loops = loops + 1;
	tmpNode = tmpNode->getLeftChild();
	}
	std::cout << "herere" << std::endl;
	std::cout << "tmpPar: " << tmpNode->getParent()->getValue() << std::endl;
	if (tmpNode->getParent() != runner){
	std::cout << "IN THE IF" << std::endl;
	//std::cout << "IN THE IF" << std::endl;
	   this->transplant(tmpNode, tmpNode->getRightChild());
	   std::cout << "AFTER TRANSPLANT" << std::endl;
	   //BSTNode<key_t, val_t>* tmpRight = tmpNode->getRightChild();
	   tmpNode->setRightChild(runner->getRightChild());
	   BSTNode<key_t, val_t>* tmpRight = tmpNode->getRightChild();
	   std::cout << "1TIME" << std::endl;
	   //BSTNode<key_t, val_t>* tmpRightPar = (tmpNode->getRightChild())->getParent();
	   tmpRight->setParent(tmpNode);
	   std::cout << "2TIME" << std::endl;
	   //tmpRight->setKey((runner->getRightChild())->getKey());
	   //tmpRight->setValue((runner->getRightChild())->getValue());

	   //tmpRightPar->setKey(tmpNode->getKey());
	   //tmpRightPar->setValue(tmpNode->getValue());
	   std::cout << "BEFORE SECOND TRANSPLANT" << std::endl;
	   this->transplant(runner, tmpNode);
	   std::cout << "AFTER SECOND TRANSPLANT" << std::endl;

	   tmpNode->setLeftChild(runner->getLeftChild());
	   //BSTNode<key_t, val_t>* tmpLeft = tmpNode->getLeftChild();
	   tmpNode->getLeftChild()->setParent(tmpNode);
	   //BSTNode<key_t, val_t>* tmpLeftPar = (tmpNode->getLeftChild())->getParent();
	   //tmpLeft->setKey((runner->getLeftChild())->getKey());
	   //tmpLeft->setValue((runner->getLeftChild())->getValue());

	   //tmpLeftPar->setKey(runner->getKey());
	   //tmpLeftPar->setValue(runner->getValue());
	}
}
this->numItems = this->numItems - 1;
 std::cout << "BEFORE Final Return" << std::endl;
return succ;
}
