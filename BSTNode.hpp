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

        const val_t& getValue();
        void setValue(const val_t&);
  
        const key_t& getKey();
        void setKey(const key_t&);
        BSTNode* getLeftChild();
        void setLeftChild(BSTNode* child);
        BSTNode* getRightChild();
        void setRightChild(BSTNode* child);
        BSTNode* getParent();
        void setParent(BSTNode* par);

};

#include "BSTNode.tpp"

#endif
