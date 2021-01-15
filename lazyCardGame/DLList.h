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
     * @param n, node* nodo dal quale iniziare la distruzione profonda della lista
     */
    static void destroy(node* n);

    /**
     * @brief deep_copy
     * @param src => node* nodo dal quale iniziare la copia profonda della lista
     * @param fst => node* passato per referenza, nodo iniziale della lista in cui verrà copiata src
     * @param last => node* passato per referenza, nodo finale della lista in cui verrà copiata src
     */
    static void deep_copy(node *src, node*& fst, node*& last);

    node *first, *last; // puntatori al primo e ultimo nodo della lista
    // lista vuota IFF first == nullptr == last
    int size;

public:
    /**
     * @brief DLList => Costruttore della classe DLList
     */
    DLList();

    /**
     * @brief DLList => Costruttore di copia della clase DLList
     * @param l => lista da copiare
     */
    DLList(const DLList& l);

    /**
     * @brief ~DLList => Distruttore della classe DLList
     */
    ~DLList();

    /**
     * @brief getSize
     * @return numero di elementi nella lista
     */
    int getSize() const;

    /**
     * @brief isEmpty
     * @return true se la lista è vuota, false altrimenti
     */
    bool isEmpty() const;

    /**
     * @brief push_front
     * @param t => T, elemento da inserire all'inizio della lista
     */
    void push_front(const T& t);

    /**
     * @brief push_back
     * @param t => T, elemento da aggiungere alla fine della lista
     */
    void push_back(const T& t);

    /**
     * @brief removeFront
     * @return primo elemento della lista
     */
    T removeFront();

    /**
     * @brief removeBack
     * @return ultimo elemento della lista
     */
    T removeBack();

    /**
     * @brief remove
     * @param i => int, indice dell'elemento da rimuovere
     * @return elemento all'indice i
     */
    T remove(int i);

    /**
     * @brief operator =
     * @param l => DLList, lista da copiare
     * @return lista copiata
     */
    DLList& operator=(const DLList& l);

    /**
     * @brief operator []
     * @param i => int, indice
     * @return elemento alla posizione i ritornato per referenza
     */
    T& operator[](int i) const;

    class Iterator
    {
        friend class DLList <T>;
    private: //const_iterator indefinito IFF ptr==nullptr & past_the_end==false
        node* ptr;
        bool past_the_end;

        /**
         * @brief Iterator => Costruttore privato della classe Iterator
         * @param p => node*, puntatore al nodo iniziale
         * @param pte => bool, past_the_end per segnalare se è andato oltre la fine della lista
         */
        Iterator(node* p, bool pte= false);

    public:
        /**
         * @brief Iterator => Costruttore della classe Iterator
         */
        Iterator();

        /**
         * @brief operator ++ prefisso
         * @return elemento successivo dell'iterazione
         */
        Iterator& operator++();

        /**
         * @brief operator ++ (int) postfisso
         * @return elemento corrente dell'iterazione e passa al successivo
         */
        Iterator operator++(int);

        /**
         * @brief operator -- prefisso
         * @return elemento precedente dell'iterazione
         */
        Iterator& operator--();

        /**
         * @brief operator -- (int) postfisso
         * @return elemento corrente dell'iterazione e passa al precedente
         */
        Iterator operator--(int);

        /**
         * @brief operator ==
         * @param it => Iterator, iteratore da confrontare passato per referenza
         * @return true se i due iteratori sono uguali, false altrimenti
         */
        bool operator==(const Iterator& it) const;

        /**
         * @brief operator !=
         * @param it => Iterator, iteratore da confrontare passato per referenza
         * @return true se i due iteratori sono diversi, false altrimenti
         */
        bool operator!=(const Iterator& it) const;

        /**
         * @brief operator *
         * @return T, valore del campo info del puntatore di tipo nodo
         */
        T& operator*() const;

        /**
         * @brief operator ->
         * @return T*, puntatore al campo info del puntatore di tipo nodo
         */
        T* operator->() const;
    };

    /**
     * @brief begin
     * @return inizio dell'iteratore
     */
    Iterator begin();

    /**
     * @brief end
     * @return fine dell'iteratore
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
    if(first->next==nullptr) //lista di invocazione era vuota
    {
        last=first;
    }
    else //lista di invocazione NON era vuota
    {
        (first->next)->prev=first;
    }
    size++;
};

template <class T>
void DLList<T>::push_back(const T& t)
{
    if(last) //lista non vuota
    {
        last = new node(t,last,nullptr);
        (last->prev)->next=last;
    }
    else//lista vuota
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
