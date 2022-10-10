#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>
class DeepPtr
{
private:
    T* ptr;
public:
    /**
     * @brief DeepPtr => Class DeepPtr constructor
     * @param p => T*, pointer to the object
     */
    DeepPtr(T* p=nullptr);

    /**
     * @brief DeepPtr => Class DeepPtr copy contructor
     * @param p => DeepPtr, object to copy passed by constant reference. Type T must implement the clone method
     */
    DeepPtr(const DeepPtr& p);

    /**
     * @brief Class DeepPtr destructor
     */
    ~DeepPtr(){delete ptr;};

    /**
     * @brief operator =
     * @param p => DeepPtr, object to assign passed by constant reference
     * @return DeepPtr, dereferencing this with cloned ptr returned by reference
     */
    DeepPtr& operator=(const DeepPtr& p);

    /**
     * @brief get
     * @return T*, pointer inside the class
     */
    T* get() const;

    /**
     * @brief operator ->
     * @return T*, pointer inside the class
     */
    T* operator->() const;

    /**
     * @brief operator *
     * @return T, dereference of the internal pointer to the class passed by reference
     */
    T& operator*() const;

    /**
     * @brief operator ==
     * @param p => DeepPtr, object to compare
     * @return true if they are equal, false otherwise
     */
    bool operator==(const DeepPtr& p) const;

    /**
     * @brief operator !=
     * @param p => DeepPtr, object to compare
     * @return true if they are different, false otherwise
     */
    bool operator!=(const DeepPtr& p) const;
};

template <class T>
DeepPtr<T>::DeepPtr(T* p):ptr(p!=nullptr? p->clone() : nullptr){delete p;};

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
