#ifndef RBT_MULTIMAP
#define RBT_MULTIMAP
#include "RBTNode.hpp"
#include "BSTMultimap.hpp"

template <class key_t, class val_t>
class RBTMultimap : public BSTMultimap<key_t, val_t>
{

protected:


public:
  RBTMultimap();
  ~RBTMultimap();

  
  
  void printDOT(std::string filename);




};

  #include "RBTMultimap.tpp"
  #endif
