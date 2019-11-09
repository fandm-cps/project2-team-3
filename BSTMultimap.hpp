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
        ~BSTMultimap();
        
        virtual void insert(const key_t& key, const val_t& val);
        virtual int getSize();
        virtual bool isEmpty();
        virtual string toString();
        virtual bool contains(const key_t& key) const;
        virtual void clear();
        virtual BSTForwardIterator<key_t, val_t> getMin() const;
};

#include "BSTMultimap.tpp"
#endif