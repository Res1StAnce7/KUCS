#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

template <typename T>
class ListInterface
{
    public:
    virtual ~ListInterface() {}
    virtual int length() const = 0;
    virtual T entry(int index) const = 0;
    virtual void insert(T entry) = 0;
    virtual void clear() = 0;
};

#include "ListInterface.cpp"
#endif
