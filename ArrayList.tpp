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

/*template <class item_t>
void ArrayList<item_t>::popBack()
{
	(*this->items)[this->size-1] = null;
	this->size -= 1;
	this->capacity -= 1;
}*/

template <class item_t>
const item_t& ArrayList<item_t>:: getBack() const
{
	return (items)[this->size - 1];
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

/*template <class item_t>
void ArrayList<item_t>:: popFront()
{
	//if not null
	if (this->isEmpty())
	{
	
	}
	else if (this->size == 1)
	{
	this->items[0] = null;
	this->size -= 1;
	}
	//if not empty
	else{
		for (int i = 0; i < size; i++)
		{
			(*this->items)[i] = (*this->items)[i+1];
		}
		(*this->items)[this->size - 1] = null;
		this->size -= 1;
	}
}*/

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

/*template <class item_t>
void ArrayList<item_t> insert(int index, const item_t& item)
{
	if (index == 0)
	{
		this->pushFront(item);
	}
	else if (index > size)
	{
		this->push->pushback(item);
	}
	else if ((*this->items)[index] == null)
	{
		(*this->items)[index] = item;
	}
	else{
		item_t tmp1 = (*this->digits)[index];
		item_t tmp2 = null;

		//setting the index equal to item
		(*this->digits)[index] = item;

		//pushing everything back
		for (int i = 0; i <size; i++)
		{
			tmp2 = (*this->digits)[index + 1];
			(*this->digits)[index + 1] = tmp1;
			tmp1 = tmp2;
			index++;
		}
		this->size = this->size + 1;
		this->pushBack(tmp1);
	}

}*/
/*template <class item_t>
void ArrayList<item__t>::insert(int index, item_t* item){
    if(size == capacity){
        item_t* newItems = new item_t[capacity*2];
        
        for(int i = 0; i < capacity-1; i++){
            (newItems)[i] = (items)[i];
        } 

        delete items;
        items = newItems;
        capacity *= 2;
    }

    for(int j = size; j > index; j--){
        (items)[j] = (items)[j-1];
    }

    size++;

}*/

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