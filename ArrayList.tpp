template <class item_t>

{
using namespace std;

}

template <class item_t>
ArrayList<item_t>::ArrayList(const int capacity) 
{
	ArrayList* items = newArrayList[capacity]
	size = 0;
	//how are we supposed to differentiate between which capacity is which
	this->capacity = capacity;
}

template <class item_t>
void ArrayList<item_t>::popBack()
{
	(*this->items)[this->size-1] = null;
	this->size -= 1;
	this->capacity -= 1;
}

template <class item_t>
const item_t& ArrayList<item_t>:: getBack() const
{
	return (*this->digits)[this->size - 1];
}


template <class item_t>
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
}

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

}