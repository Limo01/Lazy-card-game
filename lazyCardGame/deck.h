#ifndef DECK_H
#define DECK_H

#include <ostream>

template <class T>
class Deck
{
private:   
    unsigned int MAX_SIZE;
    unsigned int size;
    T* cards;

    /**
     * @brief deepCopy => Function to copy an array of cards
     * @param t => T*, array of cards to copy
     * @param size => int, size of the array to be copied
     * @return card array copied
     */
    static T* deepCopy(T* t, const unsigned int size);

public:
    /**
     * @brief Deck => Class Deck constructor
     * @param s => int, maximum deck size
     */
    Deck(unsigned int s=52);

    /**
     * @brief Deck => Class Deck copy contructor
     * @param d => Deck, deck da copiare
     */
    Deck(const Deck& d);

    /**
     * @brief ~Deck => Class Deck destructor
     */
    ~Deck();

    /**
     * @brief getSize
     * @return number of cards present in the deck
     */
    int getSize() const;

    /**
     * @brief isEmpty
     * @return true if the deck is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * @brief push_top => Insertion at the top of the deck. Most efficient way to insert a card into the deck
     * @param t => T, card to add
     */
    void push_top(const T& t);

    /**
     * @brief push_bottom => Insertion at the bottom of the deck
     * @param t => T, card to add
     */
    void push_bottom(const T& t);

    /**
     * @brief drawCard
     * @return card drawn
     */
    T drawCard();

    /**
     * @brief shuffle => Shuffle the cards
     */
    void shuffle();

    /**
     * @brief operator =
     * @param d => Deck, deck to be copied
     * @return copied deck
     */
    Deck& operator=(const Deck& d);

    /**
     * @brief operator []
     * @param i => int, index of the card to be obtained
     * @return card
     */
    T& operator[](unsigned int i) const;

    //const Iterator: Visiting the deck displays the order in which the cards will be drawn: in particular, begin () refers to the next card that will be drawn, therefore the size-1 position of the array
    class Const_iterator
    {
        friend class Deck <T>;
    private:
        T* ptr;
        int size;
        int visited;

        /**
         * @brief Const_iterator => Class Const_iterator private contructor
         * @param p => T*, array to iterate
         * @param s => int, array size
         */
        Const_iterator(T* p, int s, int v);

    public:
        /**
         * @brief operator ++ prefix
         * @return next element of the iteration
         */
        Const_iterator& operator++();

        /**
         * @brief operator ++ (int) postfix
         * @return current element of the iteration and moves on to the next
         */
        Const_iterator operator++(int);

        /**
         * @brief operator -- prefix
         * @return previous element of the iteration
         */
        Const_iterator& operator--();

        /**
         * @brief operator -- (int) postfix
         * @return current element of the iteration and moves to the previous one
         */
        Const_iterator operator--(int);

        /**
         * @brief operator +=
         * @return element n successive positions with respect to the current one
         */
        Const_iterator& operator+=(int);

        /**
         * @brief operator -=
         * @return element n previous positions compared to the current one
         */
        Const_iterator& operator-=(int);

        /**
         * @brief operator ==
         * @param i => Const_iterator, iterator to compare passed by reference
         * @return true if the two iterators are equal, false otherwise
         */
        bool operator==(const Const_iterator& i) const;

        /**
         * @brief operator !=
         * @param i => Const_iterator, iterator to compare passed by reference
         * @return true if the two iterators are different, false otherwise
         */
        bool operator!=(const Const_iterator& i) const;

        /**
         * @brief operator >
         * @param i => Const_iterator, iterator to compare passed by reference
         * @return true if the calling iterator is greater than the one being compared
         */
        bool operator>(const Const_iterator& i) const;

        /**
         * @brief operator >=
         * @param i => Const_iterator, iterator to compare passed by reference
         * @return true if the calling iterator is greater than or equal to the one being compared
         */
        bool operator>=(const Const_iterator& i) const;

        /**
         * @brief operator <
         * @param i => Const_iterator, iterator to compare passed by reference
         * @return true if the calling iterator is less than the one being compared
         */
        bool operator<(const Const_iterator& i) const;

        /**
         * @brief operator <=
         * @param i => Const_iterator, iterator to compare passed by reference
         * @return true if the calling iterator is less than or equal to the one being compared
         */
        bool operator<=(const Const_iterator& i) const;

        /**
         * @brief operator *
         * @return T, pointer value dereferenced as a constant reference
         */
        const T& operator*() const;

        /**
         * @brief operator ->
         * @return constant pointer to the iterator
         */
        const T* operator->() const;
    };

    /**
     * @brief begin
     * @return start of the iterator
     */
    Const_iterator begin() const;

    /**
     * @brief end
     * @return end of iterator
     */
    Const_iterator end() const;
};

template <class T>
T* Deck<T>::deepCopy(T* t, const unsigned int size)
{
    T* aux= new T[size];

    for(unsigned int i=0; i<size; i++)
        aux[i]= t[i];

    return aux;
};

template <class T>
Deck<T>::Deck(unsigned int s): MAX_SIZE(s), size(0), cards(new T[MAX_SIZE]){};

template <class T>
Deck<T>::Deck(const Deck& d): MAX_SIZE(d.MAX_SIZE), size(d.size), cards(deepCopy(d.cards, d.size)){};

template <class T>
Deck<T>::~Deck(){delete[] cards;};

template <class T>
int Deck<T>::getSize() const
{
    return size;
};

template <class T>
bool Deck<T>::isEmpty() const
{
    return size==0;
};

template <class T>
void Deck<T>::push_top(const T& t)
{
    if(size < MAX_SIZE)
    {
        cards[size]=t;
        size++;
    }
    else throw std::length_error("Deck<T>::push_top(const T&): reached maximum size");
};

template <class T>
void Deck<T>::push_bottom(const T& t)
{
    if(size < MAX_SIZE)
    {
        T aux, aux2;
        aux= cards[0];
        cards[0]= t;

        for(int i=1; i<=size; i++)
        {
            aux2= cards[i];
            cards[i]= aux;
            aux= aux2;
        }
        size++;
    }
    else throw std::length_error("Deck<T>::push_bottom(const T&): reached maximum size");
};

template <class T>
T Deck<T>::drawCard()
{
    if(!isEmpty())
    {
        size--;
        T aux= cards[size];
        return aux;
    }
    else throw std::range_error("Deck<T>::drawCard(): Deck<T> is empty");
};

template <class T>
void Deck<T>::shuffle()
{
    if(size>1)
    {
        unsigned int n1, n2;
        T aux;

        for(unsigned int i=0; i<size; i++)
        {
            n1= (rand() % size);//first casual number
            n2= (rand() % size);//second casual number

            aux= cards[n1];
            cards[n1]= cards[n2];
            cards[n2]= aux;
        }
    }
};

template <class T>
Deck<T>& Deck<T>::operator=(const Deck& d)
{
    if(this != &d)
    {
        delete[] cards;
        cards= deepCopy(d.cards, d.size);
        size= d.size;
        MAX_SIZE= d.MAX_SIZE;
    }
    return *this;
};

template <class T>
T& Deck<T>::operator[](unsigned int i) const
{
    if(i<size && i>=0)
        return cards[i];
    else throw std::out_of_range("Deck<T>::operator[](int): index is out of range or Deck<T> is empty");
};

template <class T>
Deck<T>::Const_iterator::Const_iterator(T* p, int s, int v): ptr(p), size(s), visited(v){};

template <class T>
typename Deck<T>::Const_iterator& Deck<T>::Const_iterator::operator++()
{
    if(size>0)
    {
        ptr--;
        size--;
        visited++;
    }
    return *this;
};

template <class T>
typename Deck<T>::Const_iterator Deck<T>::Const_iterator::operator++(int)
{
    Const_iterator aux(*this);
    if(size>0)
    {
        ptr--;
        size--;
        visited++;
    }
    return aux;
};

template <class T>
typename Deck<T>::Const_iterator& Deck<T>::Const_iterator::operator--()
{
   if(visited>=0)
   {
       ptr++;
       size++;
       visited--;
   }
   return *this;
};

template <class T>
typename Deck<T>::Const_iterator Deck<T>::Const_iterator::operator--(int)
{
    Const_iterator aux(*this);
    if(visited>=0)
    {
        ptr++;
        size++;
        visited--;
    }
    return aux;
};

template <class T>
typename Deck<T>::Const_iterator& Deck<T>::Const_iterator::operator+=(int i)
{
    for(int j=0; j<i; j++)
        this->operator++();
    return *this;
};

template <class T>
typename Deck<T>::Const_iterator& Deck<T>::Const_iterator::operator-=(int i)
{
    for(int j=0; j<i; j++)
        this->operator--();
    return *this;
};

template <class T>
bool Deck<T>::Const_iterator::operator==(const Const_iterator& i) const
{
    return ptr== i.ptr;
};

template <class T>
bool Deck<T>::Const_iterator::operator!=(const Const_iterator& i) const
{
    return ptr != i.ptr;
};

template <class T>
bool Deck<T>::Const_iterator::operator>(const Const_iterator& i) const
{
    return ptr < i.ptr;
};

template <class T>
bool Deck<T>::Const_iterator::operator>=(const Const_iterator& i) const
{
    return ptr <= i.ptr;
};

template <class T>
bool Deck<T>::Const_iterator::operator<(const Const_iterator& i) const
{
    return ptr > i.ptr;
};

template <class T>
bool Deck<T>::Const_iterator::operator<=(const Const_iterator& i) const
{
    return ptr >= i.ptr;
};

template <class T>
const T& Deck<T>::Const_iterator::operator*() const
{
    return *ptr;
};

template <class T>
const T* Deck<T>::Const_iterator::operator->() const
{
    return ptr;
};

template <class T>
typename Deck<T>::Const_iterator Deck<T>::begin() const
{
    Const_iterator i(cards, 0, 0);
    return Const_iterator(&cards[size-1], size, 0);
};

template <class T>
typename Deck<T>::Const_iterator Deck<T>::end() const
{
    return Const_iterator(&cards[0]-1, 0, size-1);
};

template <class T>
std::ostream& operator<<(std::ostream& o, const Deck<T>& d)
{
    o << "{ ";
    for(auto cit= d.begin(); cit!=d.end(); cit++)
    {
        o << *cit << " ";
    }
    return o << "}";
};

#endif // DECK_H
