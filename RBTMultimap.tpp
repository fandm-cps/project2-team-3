template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::RBTMultimap(){
	BSTNode<key_t, val_t>* node = new RBTNode<key_t, val_t>(0,0,false);
	
	this->sentinel = node;
	this->root = this->sentinel;
}

template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::~RBTMultimap(){
  	this->clear();
  	delete this->sentinel;
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& value){
	RBTNode<key_t, val_t>* node = new RBTNode<key_t, val_t>(key, value, true);

	this->insertNode(node);
	insertFixup(node);
}


/*
QUESTIONS HERE

use -> or . ?
use isRed() or color?

*/

#define PARENT insertedNode->getParent()
#define GRANDPARENT PARENT->getParent()

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertFixup(RBTNode<key_t, val_t>* insertedNode){
		
	while(PARENT->isRed()){
		
		//find the uncle
		if(PARENT == GRANDPARENT->getLeftChild()){
			RBTNode<key_t, val_t>* uncle = GRANDPARENT->getRightChild();

			if(uncle->isRed()){
				PARENT->setIsRed(false);
				uncle->setIsRed(false);
				GRANDPARENT->setIsRed(true);
				insertedNode = GRANDPARENT;
			}
			else{
				if(insertedNode == PARENT->getRightChild()){
					insertedNode = PARENT;
					rotateLeft(insertedNode);
				}

				PARENT->setIsRed(false);
				GRANDPARENT->setIsRed(true);
				rotateRight(GRANDPARENT);
			}
		}
		else{
			RBTNode<key_t, val_t>* uncle = GRANDPARENT->getLeftChild();

			if(uncle->isRed()){
				PARENT->setIsRed(false);
				uncle->setIsRed(false);
				GRANDPARENT->setIsRed(true);
				insertedNode = GRANDPARENT;
			}
			else{
				if(insertedNode == PARENT->getLeftChild()){
					insertedNode = PARENT;
					rotateRight(insertedNode);
				}

				PARENT->setIsRed(false);
				GRANDPARENT->setIsRed(true);
				rotateLeft(GRANDPARENT);
			}

		}
	}

	RBTNode<key_t, val_t>* tmp  = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
	tmp->setIsRed(false);

}

// Cormen p. 313
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateLeft(BSTNode<key_t, val_t>* node){
	BSTNode<key_t, val_t>* other = node->getRightChild();
	node->setRightChild(other->getLeftChild());

	if(other->getLeftChild() != this->sentinel){
		other->getLeftChild()->setParent(node);
	}
	other->setParent(node->getParent());

	if(node->getParent() == this->sentinel){
		this->root = other;
	}
	else if(node == node->getParent()->getLeftChild()){
		node->getParent()->setLeftChild(other);
	}
	else{
		node->getParent()->setRightChild(other);
	}
	other->setLeftChild(node);
	node->setParent(other);
}

//RIGHT-ROTATE is symmetric: exchange left and right everywhere
template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateRight(BSTNode<key_t, val_t>* node){
	BSTNode<key_t, val_t>* other = node->getLeftChild();
	node->setLeftChild(other->getRightChild());

	if(other->getRightChild() != this->sentinel){
		other->getRightChild()->setParent(node);
	}
	other->setParent(node->getParent());

	if(node->getParent() == this->sentinel){
		this->root = other;
	}
	else if(node == node->getParent()->getRightChild()){
		node->getParent()->setRightChild(other);
	}
	else{
		node->getParent()->setLeftChild(other);
	}
	other->setRightChild(node);
	node->setParent(other);
}

#define RPARENT replacementNode->getParent()

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::deleteFixup(RBTNode<key_t, val_t>* replacementNode){
	
	while(replacementNode != this->root && !replacementNode->isRed()){
		if(replacementNode == RPARENT->getLeftChild()){
			RBTNode<key_t, val_t>* sibling = RPARENT->getRightChild();

			if(sibling->isRed()){
				sibling->setIsRed(false);
				RPARENT->setIsRed(true);
				rotateLeft(RPARENT);
				sibling = RPARENT->getRightChild();
			}

			if(!sibling->getLeftChild()->isRed() && !sibling->getRightChild()->isRed()){
				sibling->setIsRed(true);
				replacementNode = RPARENT;
			}
			else{
				if(!sibling->getRightChild()->isRed()){
					sibling->getLeftChild()->setIsRed(false);
					sibling->setIsRed(true);
					rotateRight(sibling);
					sibling = RPARENT->getRightChild();
				}

				sibling->setIsRed(RPARENT->isRed());
				RPARENT->setIsRed(false);
				sibling->getRightChild()->setIsRed(false);
				rotateLeft(RPARENT);
				RBTNode<key_t, val_t>* tmp  = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
				replacementNode = tmp;
			}
		}
		else{
			RBTNode<key_t, val_t>* sibling = RPARENT->getLeftChild();

			if(sibling->isRed()){
				sibling->setIsRed(false);
				RPARENT->setIsRed(true);
				rotateRight(RPARENT);
				sibling = RPARENT->getLeftChild();
			}

			if(!sibling->getRightChild()->isRed() && !sibling->getLeftChild()->isRed()){
				sibling->setIsRed(true);
				replacementNode = RPARENT;
			}
			else{
				if(!sibling->getLeftChild()->isRed()){
					sibling->getRightChild()->setIsRed(false);
					sibling->setIsRed(true);
					rotateLeft(sibling);
					sibling = RPARENT->getLeftChild();
				}

				sibling->setIsRed(RPARENT->isRed());
				RPARENT->setIsRed(false);
				sibling->getLeftChild()->setIsRed(false);
				rotateRight(RPARENT);
				RBTNode<key_t, val_t>* tmp  = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
				replacementNode = tmp;
			}
		}
	}
	replacementNode->setIsRed(false);
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode){

  	if (nodeToReplace->getParent() == this->sentinel){
      	this->root = replacementNode;
	}
  	else if (nodeToReplace == nodeToReplace->getParent()->getLeftChild()){
    	nodeToReplace->getParent()->setLeftChild(replacementNode);
  	}
  	else{
    	nodeToReplace->getParent()->setRightChild(replacementNode);  
 	}
  	replacementNode->setParent(nodeToReplace->getParent());
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> RBTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos){
  
  //this is basically z
  RBTNode<key_t, val_t>* og = dynamic_cast<RBTNode<key_t, val_t>* >(pos.current);
  //this is basically y
  RBTNode<key_t, val_t>* runner = og;

  bool runnerOGColor = runner->isRed();
  RBTNode<key_t, val_t>* tmpNode = dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel);
  RBTNode<key_t, val_t>* minNode = dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel);

  if (og->getLeftChild() == this->sentinel){
    tmpNode = og->getRightChild();
    this->transplant(og, og->getRightChild());
  }
  else if (og->getRightChild() == this->sentinel){
    tmpNode = og->getLeftChild();
    this->transplant(og, og->getLeftChild());
  }
  else{
    //
    minNode = og->getRightChild();
    while (minNode->getLeftChild() != this->sentinel){
      minNode = minNode->getLeftChild();
    }
    runner = minNode;
    runnerOGColor = runner->isRed();
    tmpNode = runner->getRightChild();
    
    if (runner->getParent() == og){
      tmpNode->setParent(runner);
    }
    else{
      this->transplant(runner, runner->getRightChild());
      runner->setRightChild(og->getRightChild());
      runner->getRightChild()->setParent(runner);
    }
    this->transplant(og, runner);
    runner->setLeftChild(og->getLeftChild());
    runner->getLeftChild()->setParent(runner);
    runner->setIsRed(og->isRed());
  }
  if (runnerOGColor == false){
    this->deleteFixup(tmpNode);
  }

}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
   using namespace std;
   ofstream fout(filename.c_str());

   long long counter = 1;
   map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
   nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
   counter++;

   fout << "digraph RBTMultimap {" << endl;

   fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

   if(this->root != this->sentinel)
   {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
      {
	 nodeToCounter[rt] = counter;
	 counter++;
      }
      if(!nodeToCounter[rt->getParent()])
      {
	 nodeToCounter[rt->getParent()] = counter;
	 counter++;
      }
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
      {
	 fout << ", color=grey];" << endl;
      }
      else
      {
	 //The root's parent is something weird!! Make the arrow orange so it sticks out
	 fout << ", color=orange];" << endl;
      }

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
      {
	 RBTNode<key_t, val_t>* node = q.front();
	 q.pop();

	 printed[node] = true;
      
	 //Set up node's appearance
	 if(!nodeToCounter[node])
	 {
	    nodeToCounter[node] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	 if(node->isRed())
	 {
	    fout << "red";
	 }
	 else
	 {
	    fout << "black, fontcolor=white";
	 }
	 fout << "];" << endl;

	 //Set up child links
	 //First the left node
	 if(!nodeToCounter[node->getLeftChild()])
	 {
	    nodeToCounter[node->getLeftChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	 if(node->getLeftChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getLeftChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getLeftChild());
	 }

	 if(node->getLeftChild() != this->sentinel)
	 {
	    if(node->getLeftChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getLeftChild()->getParent()])
	       {
		  nodeToCounter[node->getLeftChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }

	 //Now the right node
	 if(!nodeToCounter[node->getRightChild()])
	 {
	    nodeToCounter[node->getRightChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	 if(node->getRightChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getRightChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getRightChild());
	 }

	 if(node->getRightChild() != this->sentinel)
	 {
	    if(node->getRightChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getRightChild()->getParent()])
	       {
		  nodeToCounter[node->getRightChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }
      }
   }
   fout << "}" << endl;
}

