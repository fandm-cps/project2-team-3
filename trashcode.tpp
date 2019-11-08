

BSTNode<val_t, key_t>* findSuc = pos->current;
BSTNode<val_t, key_t>* ittSent = pos->sentinel;

if (findSuc->getRightChild() == ittSent){
   //how do you call a tpp funtion within another tpp function
   findSuc = getMin(findSuc->getRightChild());
}
BSTNode<val_t, key_t>* sucPar = findSuc->getParent();

while (sucPar != ittSent && findSucc == sucPar->getRightChild()){

      findSuc = sucPar;
      sucPar = sucPar->getRightChild();
}
findSuc = sucPar;
