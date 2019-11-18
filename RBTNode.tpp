///YOUR JOB: Implement the constructor right here

template <class key_t, class val_t>
RBTNode<key_t, val_t>::RBTNode(const key_t& k, const val_t& v, bool color):BSTNode<key_t, val_t>(k, v)
{
  red = color;
  
}

//template <class key_t, class val_t>
//RBTNode<key_t, val_t>::~RBTNode(){
  
//delete sentinel;
//}
template <class key_t, class val_t>
RBTNode<key_t, val_t>* RBTNode<key_t, val_t>::getParent() const
{
   return dynamic_cast<RBTNode<key_t, val_t>* >(BSTNode<key_t, val_t>::getParent());
}

template <class key_t, class val_t>
RBTNode<key_t, val_t>* RBTNode<key_t, val_t>::getLeftChild() const
{
   return dynamic_cast<RBTNode<key_t, val_t>* >(BSTNode<key_t, val_t>::getLeftChild());
}

template <class key_t, class val_t>
RBTNode<key_t, val_t>* RBTNode<key_t, val_t>::getRightChild() const
{
   return dynamic_cast<RBTNode<key_t, val_t>* >(BSTNode<key_t, val_t>::getRightChild());
}

template <class key_t, class val_t>
bool RBTNode<key_t, val_t>::isRed() const
{
   return red;
}

template <class key_t, class val_t>
void RBTNode<key_t, val_t>::setIsRed(bool newIsRed)
{
   red = newIsRed;
}

