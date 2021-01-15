#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>
class DeepPtr
{
private:
    T* ptr;
public:
    /**
     * @brief DeepPtr => Costruttore della classe DeepPtr
     * @param p => T*, puntatore all'oggetto
     */
    DeepPtr(T* p=nullptr);

    /**
     * @brief DeepPtr => Costruttore di copia della classe DeepPtr
     * @param p => DeepPtr, oggetto da copiare passato per riferimento costante. Il tipo T deve implementare il metodo clone
     */
    DeepPtr(const DeepPtr& p);

    /**
     * @brief Distruttore della classe DeepPtr
     */
    ~DeepPtr(){delete ptr;};

    /**
     * @brief operator =
     * @param p => DeepPtr, oggetto da assegnare passato per riferimento costante
     * @return DeepPtr, dereferenzizione di this con ptr clonato ritornato per referenza
     */
    DeepPtr& operator=(const DeepPtr& p);

    /**
     * @brief get
     * @return T*, puntatore interno alla classe
     */
    T* get() const;

    /**
     * @brief operator ->
     * @return T*, puntatore interno alla classe
     */
    T* operator->() const;

    /**
     * @brief operator *
     * @return T, dereferenziazione del puntatore interno alla classe passato per referenza
     */
    T& operator*() const;

    /**
     * @brief operator ==
     * @param p => DeepPtr, oggetto da confrontare
     * @return true se sono uguali, altrimenti false
     */
    bool operator==(const DeepPtr& p) const;

    /**
     * @brief operator !=
     * @param p => DeepPtr, oggetto da confrontare
     * @return true se sono diversi, altrimenti false
     */
    bool operator!=(const DeepPtr& p) const;
};

template <class T>
DeepPtr<T>::DeepPtr(T* p):ptr(p!=nullptr? p->clone() : nullptr){};

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr& p): ptr(p.ptr? p.ptr->clone() : nullptr){};

template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& p)
{
    if(this != &p)
    {
        delete ptr;
        ptr= p.ptr? p.ptr->clone() : nullptr;
    }
    return *this;
};

template <class T>
T* DeepPtr<T>::get() const
{
    return ptr;
};

template <class T>
T* DeepPtr<T>::operator->() const
{
    return ptr;
};

template <class T>
T& DeepPtr<T>::operator*() const
{
    return *ptr;
};

template <class T>
bool DeepPtr<T>::operator==(const DeepPtr& p) const
{
    return p.ptr == ptr;
};

template <class T>
bool DeepPtr<T>::operator!=(const DeepPtr& p) const
{
    return p.ptr != ptr;
};
#endif // DEEPPTR_H
