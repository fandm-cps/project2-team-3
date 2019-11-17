#ifndef BSTMULTIMAP
#define BSTMULTIMAP

#include "BSTNode.hpp"
#include "BSTForwardIterator.hpp"
#include <string>
#include <queue>

using namespace std;

template <class key_t, class val_t>
class BSTMultimap
{
    protected:
        BSTNode<key_t, val_t>* root;
        BSTNode<key_t, val_t>* sentinel;
        int numItems;

    public:
        BSTMultimap();
   virtual ~BSTMultimap();
        virtual void insert(const key_t& key, const val_t& val);
  virtual void insertNode(BSTNode<key_t, val_t>* newNode);
        virtual int getSize();
        virtual bool isEmpty();
        virtual string toString();
  virtual bool contains(const key_t& key) const;
        virtual void clear();
  virtual BSTForwardIterator<key_t, val_t> getMin() const;
  virtual BSTForwardIterator<key_t, val_t> getMax() const;
  virtual BSTForwardIterator<key_t, val_t> findFirst(const key_t& key) const;
  virtual BSTForwardIterator<key_t, val_t> findLast(const key_t& key) const;
  virtual void transplant(BSTNode<key_t, val_t>* u, BSTNode<key_t, val_t>* v) ;
  virtual BSTForwardIterator<key_t, val_t> remove(const BSTForwardIterator<key_t, val_t>& pos);
};

#include "BSTMultimap.tpp"
#endif
