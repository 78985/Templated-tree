#include<iostream>
#include "methods.cpp"
using namespace std;

template <typename R>
class Container
{
public:
    virtual void INSERT(R value) = 0;
    virtual void EXISTS(R value) = 0;
    virtual void REMOVE(R value) = 0;
    virtual void PRINT() = 0;
    virtual ~Container();
};

template <typename R>
Container<R>::~Container<R>() { }

