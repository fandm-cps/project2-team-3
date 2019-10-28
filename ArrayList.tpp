using namespace std;
#include <cstddef>

template <class item_t>
ArrayList<item_t>::ArrayList(){
    items = new item_t[10];
    size = 0;
    capacity = 10;
}

template <class item_t>
ArrayList<item_t>::ArrayList(const int capacity){
	items = new item_t[capacity];
	size = 0;
	this->capacity = capacity;
}

template <class item_t>
ArrayList<item_t>::~ArrayList(){
    delete items;
}

template <class item_t>
void ArrayList<item_t>::pushBack(const item_t& item){
    if(size == capacity){
        item_t* newItems = new item_t[capacity*2];
        
        for(int i = 0; i < capacity-1; i++){
            (newItems)[i] = (items)[i];
        } 

        delete items;
        items = newItems;
        capacity *= 2;
    }
    
    (items)[size] = item;
    size++;
}

template <class item_t>
void ArrayList<item_t>::popBack(){
    if(size != 0){
	    size -= 1;
    }
}

template <class item_t>
const item_t& ArrayList<item_t>:: getBack() const{
	return (items)[size-1];
}

template <class item_t>
void ArrayList<item_t>::pushFront(const item_t& item){

    if(size == capacity){
        item_t* newItems = new item_t[capacity*2];
        
        for(int i = 0; i < capacity-1; i++){
            (newItems)[i+1] = (items)[i];
        } 

        delete items;
        items = newItems;
        capacity *= 2;
    }
    else{
        for(int j = size; j > 0; j--){
            (items)[j] = (items)[j-1];
        }
    }

    (items)[0] = item;
    size++;
}

template <class item_t>
void ArrayList<item_t>:: popFront(){
	if(size != 0){
	    if(size != 1){
		    for (int i = 0; i < size; i++){
			    (items)[i] = (items)[i+1];
		    }
	    }
        size -= 1;
    }
}

template <class item_t>
const item_t& ArrayList<item_t>::getFront() const{
    return (items)[0];
}

template <class item_t>
const item_t& ArrayList<item_t>::getItem(int index) const{
    return (items)[index];
}

template <class item_t>
void ArrayList<item_t>::setItem(int index, const item_t& item){
    (items)[index] = item;
}

template <class item_t>
void ArrayList<item_t>::insert(int index, const item_t& item){
    if(size == capacity){
        item_t* newItems = new item_t[capacity*2];
        
        for(int i = 0; i < capacity-1; i++){
            (newItems)[i] = (items)[i];
        } 

        delete items;
        items = newItems;
        capacity *= 2;
    }

	if (index == 0){
		pushFront(item);
	}
	else if (index >= size){
		pushBack(item);
	}
	else{
        for(int i = size-1; i >= index; i--){
            (items)[i+1] = (items)[i];
        }
        (items)[index] = item;
        size++;
	}
}

template <class item_t>
void ArrayList<item_t>::remove(int index){
    for(int i = index; i < size-1; i++){
        (items)[i] = (items)[i+1];
    }
    size--;
}

template <class item_t>
int ArrayList<item_t>::getSize() const{
    return size;
}

template <class item_t>
bool ArrayList<item_t>::isEmpty() const{
    return (size == 0)? true : false;
}

template <class item_t>
int ArrayList<item_t>::getCapacity() const{
    return capacity;
}