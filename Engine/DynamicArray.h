#pragma once
#include "IContainer.h"
 class IContext;
template <typename T> class DynamicArrayIterator;
template <typename T> class DynamicArray : public IDynamicArray<T>{

public:
	DynamicArray(
		IContext* context,
		int size);

	void start(IIterator<T>**) const override;

	void end(IIterator<T>**) const override;

	void appendLast(T&&) override;

	void appendHead(T&&) override;

	int getCapacity() override;

	int getSize() override;

	void pop() override;

	void remove(IIterator<T>*) override;

	void swap(IIterator<T>*, IIterator<T>*) override;

	bool isEmpty() override;

	void clear() override;

	bool isFull() override;

	void sort() override;


private:

	 T* data = nullptr;

	 int size = 0;

	 int capacity = 1;

	 int selfGrowSize = 20;
	 
	 IContext* context;
	 friend class DynamicArrayIterator<T>;
}; 
template <typename T> class DynamicArrayIterator : public IIterator<T> {

public:

	void next() override;

	const T* get() override;

	bool equals(IIterator<T>*) override;

private:
	DynamicArrayIterator(DynamicArray<T>* array);

	DynamicArray<T>* array = nullptr;

	T* curPtr = nullptr;

	friend class DynamicArray<T>;

};