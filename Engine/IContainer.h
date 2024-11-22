#pragma once
#include "IObject.h"

template <typename T> class IIterator : public Object{

public:

	virtual void next() = 0;

	virtual const T* get() = 0;

	virtual bool equals(IIterator<T>*) = 0;
};

template <typename T> class IIterable : public Object{

public:
	virtual void start(IIterator<T>**) const = 0;

	virtual void end(IIterator<T>**) const = 0;

};

template <typename T> class IDynamicArray : public IIterable<T> {

public:

	virtual void appendLast(T&&) = 0;

	virtual void appendHead(T&&) = 0;

	virtual int getCapacity() = 0;

	virtual int getSize() = 0;

	virtual void pop() = 0;

	virtual void remove(IIterator<T>*) = 0;

	virtual void swap(IIterator<T>*, IIterator<T>*) = 0;

	virtual bool isEmpty() = 0;

	virtual void clear() = 0;

	virtual bool isFull() = 0;

	virtual void sort() = 0;

};

template <typename T> class LinkedList : public IIterable<T> {

public:

	virtual void append(T, int index) = 0;

	virtual int getSize() = 0;

	virtual void remove(int index) = 0;

	virtual void remove(IIterator<T>) = 0;

	virtual void swap(IIterator<T>, IIterator<T>) = 0;

	virtual bool isEmpty() = 0;

	virtual void clear() = 0;

	virtual bool isFull() = 0;

};

template <typename T> class IStack : public Object{

public:

	virtual void push(T) = 0;

	virtual T pop() = 0;

	virtual bool isEmpty() = 0;

	virtual void clear() = 0;

	virtual int getCapacity() = 0;

	virtual int getStackSize() = 0;

	virtual bool isFull() = 0;

};

template <typename T> class IQuene : public Object{

public:

	virtual void in(T) = 0;

	virtual T out() = 0;

	virtual bool isEmpty() = 0;

	virtual void clear() = 0;

	virtual int getCapacity() = 0;

	virtual int getQueneSize() = 0;

	virtual bool isFull() = 0;
};

template <typename T> class ISet : public IIterable<T>{

public:

	virtual void append(T) = 0;

	virtual void appendIfNotExist(T) noexcept = 0;

	virtual void remove(IIterator<T>) noexcept = 0;

	virtual bool isEmpty() = 0;

	virtual void clear() = 0;

	virtual int getCapacity() = 0;

	virtual int getSetSize() = 0;

	virtual bool isFull() = 0;

	virtual bool contains(T&&) = 0;

};

template <typename K, typename V> class IPair : public Object{

public:

	virtual void set0(K) = 0;

	virtual void set1(V) = 0;

	virtual K get0() = 0;

	virtual V get1() = 0;

};

template <typename K, typename V> class IMap : public IIterable<IPair<K,V>>{

public:

	virtual void set(K, V) = 0;

	virtual V& getValueFromKey(K&&) = 0;

	virtual bool isEmpty() = 0;

	virtual void clear() = 0;

	virtual int getCapacity() = 0;

	virtual int getMapSize() = 0;

	virtual bool isFull() = 0;

	virtual bool contains(K&&) = 0;

	virtual void remove(K&&) = 0;

	virtual const ISet<K>* getKeySet() = 0;

	

};

		

template <typename T> class ITreeLift : public IIterator<T> {

public:

	virtual bool isLastKid() = 0;

	virtual bool isLeaf() = 0;

	virtual bool hasParent() = 0;

	virtual void toLeaf() = 0;

	virtual void toKid() = 0;

	virtual void toParent() = 0;

	virtual void toRoot() = 0;

};

template <typename T> class ITree : public IIterable<T>{


public:

	virtual ITreeLift<T> getRoot() = 0;

	virtual void setValue(T val, ITreeLift<T> node) = 0;

	virtual void addToKid(ITreeLift<T> parent, T val) = 0;

	virtual ITreeLift<T> search(T val) = 0;


};