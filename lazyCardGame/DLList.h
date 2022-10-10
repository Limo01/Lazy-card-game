#ifndef DLLIST_H
#define DLLIST_H

#include <ostream>

template <class T>
class DLList {
private:

    class node
    {
    public:
        T info;
        node *prev, *next;
        node(const T& t, node* p = 0, node* n=0);
    };

    /**
     * @brief destroy
     * @param n, node* node from which to start the deep destruction of the list
     */
    static void destroy(node* n);

    /**
     * @brief deep_copy
     * @param src => node* node from which to start deep copy of the list
     * @param fst => node* passed by reference, starting node of the list where src will be copied
     * @param last => node* passed by reference, final node of the list where src will be copied
     */
    static void deep_copy(node *src, node*& fst, node*& last);

    node *first, *last; // pointers to the first and last node in the list
    // empty list IFF first == nullptr == last
    int size;

public:
    /**
     * @brief DLList => Class DLList constructor
     */
    DLList();

    /**
     * @brief DLList => Class DLList copy constructor
     * @param l => list to copy
     */
    DLList(const DLList& l);

    /**
     * @brief ~DLList => Class DLList destructor
     */
    ~DLList();

    /**
     * @brief getSize
     * @return number of items in the list
     */
    int getSize() const;

    /**
     * @brief isEmpty
     * @return true if the list is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief push_front
     * @param t => T, element to be inserted at the beginning of the list
     */
    void push_front(const T& t);

    /**
     * @brief push_back
     * @param t => T, item to add to the end of the list
     */
    void push_back(const T& t);

    /**
     * @brief removeFront
     * @return first element of the list
     */
    T removeFront();

    /**
     * @brief removeBack
     * @return last item in the list
     */
    T removeBack();

    /**
     * @brief remove
     * @param i => int, index of the item to remove
     * @return element at index i
     */
    T remove(int i);

    /**
     * @brief operator =
     * @param l => DLList, list to copy
     * @return copied list
     */
    DLList& operator=(const DLList& l);

    /**
     * @brief operator []
     * @param i => int, index
     * @return element at position i returned by reference
     */
    T& operator[](int i) const;

    class Iterator
    {
        friend class DLList <T>;
    private: //const_iterator undefined IFF ptr==nullptr & past_the_end==false
        node* ptr;
        bool past_the_end;

        /**
         * @brief Iterator => Class Iterator private constructor
         * @param p => node*, pointer to the starting node
         * @param pte => bool, past_the_end to report if it has gone beyond the end of the list
         */
        Iterator(node* p, bool pte= false);

    public:
        /**
         * @brief Iterator => Class Iterator constructor
         */
        Iterator();

        /**
         * @brief operator ++ prefix
         * @return next element of the iteration
         */
        Iterator& operator++();

        /**
         * @brief operator ++ (int) postfix
         * @return current element of the iteration and moves on to the next
         */
        Iterator operator++(int);

        /**
         * @brief operator -- prefix
         * @return previous element of the iteration
         */
        Iterator& operator--();

        /**
         * @brief operator -- (int) postfix
         * @return current element of the iteration and moves to the previous one
         */
        Iterator operator--(int);

        /**
         * @brief operator ==
         * @param it => Iterator, iterator to compare passed by reference
         * @return true if the two iterators are equal, false otherwise
         */
        bool operator==(const Iterator& it) const;

        /**
         * @brief operator !=
         * @param it => Iterator, iterator to compare passed by reference
         * @return true if the two iterators are different, false otherwise
         */
        bool operator!=(const Iterator& it) const;

        /**
         * @brief operator *
         * @return T, value of the info field of the node type pointer
         */
        T& operator*() const;

        /**
         * @brief operator ->
         * @return T*, pointer to the info field of the node-type pointer
         */
        T* operator->() const;
    };

    /**
     * @brief begin
     * @return start of the iterator
     */
    Iterator begin();

    /**
     * @brief end
     * @return end of the iterator
     */
    Iterator end();
};

template <class T>
DLList<T>::node::node(const T& t, node* p, node* n): info(t), prev(p), next(n) {};

template <class T>
void DLList<T>::destroy(node* n)
{
    if (n != nullptr)
    {
        destroy(n->next);
        delete n;
    }
};

template <class T>
void DLList<T>::deep_copy(node *src, node*& fst, node*& last)
{
    if (src)
    {
        fst = last = new node(src->info);
        node* aux = src->next;
        while (aux)
        {
            last = new node(aux->info, last);
            last->prev->next = last;
            aux = aux->next;
        }
    }
    else
    {
        fst = last = nullptr;
    }
};

template <class T>
DLList<T>::DLList(): first(nullptr), last(nullptr), size(0) {};

template <class T>
DLList<T>::DLList(const DLList& l): size(l.size)
{
    deep_copy(l.first,first,last);
};

template <class T>
DLList<T>::~DLList()
{
    destroy(first);
};

template <class T>
int DLList<T>::getSize() const
{
    return size;
};

template <class T>
bool DLList<T>::isEmpty() const
{
    return size==0;
};

template <class T>
void DLList<T>::push_front(const T& t)
{
    first = new node(t,nullptr,first);
    if(first->next==nullptr) //invocation list was empty
    {
        last=first;
    }
    else //invocation list wasn't empty
    {
        (first->next)->prev=first;
    }
    size++;
};

template <class T>
void DLList<T>::push_back(const T& t)
{
    if(last) //not empty list
    {
        last = new node(t,last,nullptr);
        (last->prev)->next=last;
    }
    else//empty list
    {
        first=last=new node(t);
    }
    size++;
};

template <class T>
T DLList<T>::removeFront()
{
    if(!isEmpty())
    {
        T aux= first->info;
        if(size==1)
        {
            delete first;
            first=last=nullptr;
        }
        else
        {
            first= first->next;
            delete first->prev;
            first->prev= nullptr;
        }

        size--;
        return aux;
    }
    else throw std::range_error("DLList<T>::removeFront(): DLList<T> is empty");
};

template <class T>
T DLList<T>::removeBack()
{
    if(!isEmpty())
    {
        T aux= last->info;
        if(size==1)
        {
            delete first;
            first=last=nullptr;
        }
        else
        {
            last= last->prev;
            delete last->next;
            last->next= nullptr;
        }

        size--;
        return aux;
    }
    else throw std::range_error("DLList<T>::removeBack(): DLList<T> is empty");
};

template <class T>
T DLList<T>::remove(int i)
{
    if(i<size)
    {
        if(i==0)
        {
            return removeFront();
        }
        else if(i==size-1)
        {
            return removeBack();
        }
        else
        {
            node* n= first;
            for(int j=0; j<i; j++)
                n=n->next;

            T aux= n->info;
            n->prev->next= n->next;
            n->next->prev= n->prev;
            delete n;
            size--;
            return aux;
        }
    }
    else throw std::out_of_range("DLList<T>::remove(int) : index is out of range or DLList<T> is empty");
};

template <class T>
DLList<T>& DLList<T>::operator=(const DLList& l)
{
    if(this != &l)
    {
        destroy(first);
        deep_copy(l.first,first,last);
    }
    return *this;
};

template <class T>
T& DLList<T>::operator[](int i) const
{
    if(i<size && i>=0)
    {
        node* n= first;
        for(int j=0; j<i; j++)
            n=n->next;
        return n->info;
    }
    else
        throw std::out_of_range("DLList<T>::operator[](int) : index is out of range or DLList<T> is empty");
};

template <class T>
DLList<T>::Iterator::Iterator(node* p, bool pte): ptr(p), past_the_end(pte) {};

template <class T>
DLList<T>::Iterator::Iterator(): ptr(nullptr), past_the_end(false) {};

template <class T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator++()
{
    if(ptr!= nullptr)
    {
        if(!past_the_end)
        {
            if(ptr->next != nullptr)
            {
                ptr = ptr->next;
            }
            else
            {
                ptr = ptr+1;
                past_the_end = true;
            }
        }
    }
    return *this;
};

template <class T>
typename DLList<T>::Iterator DLList<T>::Iterator:: operator++(int)
{
    Iterator aux(*this);
    if(ptr!= nullptr)
    {
        if(!past_the_end)
        {
            if(ptr->next != nullptr)
                ptr = ptr->next;
            else
            {
                ptr = ptr+1;
                past_the_end = true;
            }
        }
    }
    return aux;
};

template <class T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator--()
{
    if(ptr != nullptr)
    {
        if(ptr->prev == nullptr)
            ptr=nullptr;
        else if(!past_the_end)
            ptr = ptr->prev;
        else
        {
            ptr = ptr-1;
            past_the_end = false;
        }
    }
    return *this;
};

template <class T>
typename DLList<T>::Iterator DLList<T>::Iterator::operator--(int)
{
    Iterator aux(*this);
    if(ptr != nullptr)
    {
        if(ptr->prev == nullptr)
            ptr=nullptr;
        else if(!past_the_end)
            ptr = ptr->prev;
        else
        {
            ptr = ptr-1;
            past_the_end = false;
        }
    }
    return aux;
};

template <class T>
bool DLList<T>::Iterator::operator==(const Iterator& it) const
{
    return ptr == it.ptr;
};

template <class T>
bool DLList<T>::Iterator::operator!=(const Iterator& it) const
{
    return ptr != it.ptr;
};

template <class T>
T& DLList<T>::Iterator::operator*() const
{
    return ptr->info;
};

template <class T>
T* DLList<T>::Iterator::operator->() const
{
    return &(ptr->info);
};

template <class T>
typename DLList<T>::Iterator DLList<T>::begin()
{
    return Iterator(first);
};

template <class T>
typename DLList<T>::Iterator DLList<T>::end()
{
    if(!last) return Iterator();
    return Iterator(last+1,true);
};

template<class T>
std::ostream& operator<<(std::ostream& o, const DLList<T>& l)
{
    o << "{ ";
    for(auto it= l.begin(); it!=l.end(); it++)
    {
        o << *it << " ";
    }
    return o << "}";
};

#endif // DLLIST_H
