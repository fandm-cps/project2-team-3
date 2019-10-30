template <class item_t>
LinkedList<item_t>::LinkedList(){
    head = 0;
    tail = 0;
    size = 0;
}

template <class item_t>
LinkedList<item_t>::~LinkedList(){

    LinkedListNode<item_t>* current = head;

    while(current != 0){
        LinkedListNode<item_t>* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
    head = 0;
}

template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item){
    LinkedListNode<item_t>* node = new LinkedListNode<item_t>(0, item);
    
    if(size == 0){
        head = node;
    }
    else{
        tail->setNext(node);
    }

    tail = node;
    tail->setNext(0);
    size++;
}

template <class item_t>
void LinkedList<item_t>::popBack(){
    if(size != 0){
        if(size == 1){
            head = 0;
            tail = 0;
        }
        else{
            LinkedListNode<item_t>* current = head;

            while(current->getNext()->getNext() != 0){
                current = current->getNext();
            }
            current->setNext(0);
            tail = current;
        }
        size--;
    }
}

template <class item_t>
const item_t& LinkedList<item_t>::getBack() const{
    return tail->getItem();
}

template <class item_t>
void LinkedList<item_t>::pushFront(const item_t& item){
    LinkedListNode<item_t>* node = new LinkedListNode<item_t>(head, item);
    
    if(size == 0){
        tail = node;
    }
    node->setNext(head);
    head = node;
    size++;
}

template <class item_t>
void LinkedList<item_t>::popFront(){
    if(size != 0){
        if(size == 1){
            head = 0;
            tail = 0;
        }
        else{
            head = head->getNext();
        }
        size--;
    }
}

template <class item_t>
const item_t& LinkedList<item_t>::getFront() const{
    return head->getItem();
}

template <class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const{
    
    LinkedListNode<item_t>* current = head;
    int count = 0;

    while(count < index){
        current = current->getNext();
        count++;
    }

    return current->getItem();
}

template <class item_t>
void LinkedList<item_t>::setItem(int index, const item_t& item){
    LinkedListNode<item_t>* current = head;
    int count = 0;

    while(count < index){
        current = current->getNext();
        count++;
    }
    
    current->setItem(item);
}

template <class item_t>
void LinkedList<item_t>::insert(int index, const item_t& item){
    if(index == 0){
        pushFront(item);
    }
    else if(index >= size){
        pushBack(item);
    }
    else{
        LinkedListNode<item_t>* node = new LinkedListNode<item_t>(0, item);
        LinkedListNode<item_t>* current = head;
        int count = 0;

        while(count < index-1){
            current = current->getNext();
            count++;
        }

        node->setNext(current->getNext());
        current->setNext(node);
        size++;
    }
}

template <class item_t>
void LinkedList<item_t>::remove(int index){
    if(index == 0){
        popFront();
    }
    else if(index >= size-1){
        popBack();
    }
    else{
        LinkedListNode<item_t>* current = head;
        int count = 0;

        while(count < index-1){
            current = current->getNext();
            count++;
        }

        current->setNext(current->getNext()->getNext());

        size--;
    }
}

template <class item_t>
int LinkedList<item_t>::getSize() const{
    return size;
}

template <class item_t>
bool LinkedList<item_t>::isEmpty() const{
    return (size == 0)? true : false;
}