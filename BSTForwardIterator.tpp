#include <iostream>
template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t>::BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel){

this->current = node;
this->sentinel = sentinel;

}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::next(){
	if(current != sentinel){
		if(current->getRightChild() != sentinel){
			current = current->getRightChild();
			while(current->getLeftChild() != sentinel){
				current = current->getLeftChild();
			}
		}
		else{
			BSTNode<key_t, val_t>* tmp = current->getParent();

			while(tmp != sentinel && current == tmp->getRightChild()){
				current = tmp;
				tmp = tmp->getParent();
			}
			current = tmp;
		}
	}
}

template <class key_t, class val_t>
bool BSTForwardIterator<key_t, val_t>::isPastEnd() const{

if (this->current == this->sentinel)
{
	return true;
}
return false;
}

template <class key_t, class val_t>
const key_t& BSTForwardIterator<key_t, val_t>::getKey() const{

  
  return (this->current)->getKey();
}

template <class key_t, class val_t>
const val_t& BSTForwardIterator<key_t, val_t>::getValue() const{

return (this->current)->getValue();
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::setValue(const val_t& newVal){

(this->current)->setValue(newVal);
}

