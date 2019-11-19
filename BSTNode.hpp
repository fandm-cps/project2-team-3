#ifndef BSTNODE
#define BSTNODE

template <class key_t, class val_t>
class BSTNode
{
    protected:
        key_t key;
        val_t val;
        BSTNode<key_t, val_t>* leftChild;
        BSTNode<key_t, val_t>* rightChild;
        BSTNode<key_t, val_t>* parent;

    public:
        BSTNode(const key_t& k, const val_t& v);

  virtual ~BSTNode();
        virtual const val_t& getValue();
        virtual void setValue(const val_t&);
  
        virtual const key_t& getKey();
        virtual void setKey(const key_t&);
        virtual BSTNode<key_t,val_t>* getLeftChild() const;
        virtual void setLeftChild(BSTNode* child);
  virtual BSTNode<key_t,val_t>* getRightChild() const;
        virtual void setRightChild(BSTNode* child);
        virtual BSTNode<key_t,val_t>* getParent() const;
        virtual void setParent(BSTNode* par);

};

#include "BSTNode.tpp"

#endif
