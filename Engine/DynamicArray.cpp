#include "DynamicArray.h"
#include "IContext.h"
#include "ISystem.h"
template <typename T> DynamicArrayIterator<T>::DynamicArrayIterator(DynamicArray<T>* array) {

	this->array = array;

}
template <typename T> DynamicArray<T>::DynamicArray(
	IContext* context,
	int size) {

	if (size <= 0)
		throw "DynamicArray's Size must be over 0!";

	unsigned long long sz = size * sizeof(T);
	void* d;
	context->getDefaultGameMemoryAllocator()->getCommon(&d, sz);
	data = reinterpret_cast<T*>(d);


}

template<typename T>
void DynamicArrayIterator<T>::next(){

	if (!array)
		throw "This iterator is pointed to a null container";
	T* head = array->data;
	if ((curPtr - head) / sizeof(T) + 1 >= array->size) {
		curPtr = nullptr;
	}
	else {
		++curPtr;
	}

}

template<typename T>
const T* DynamicArrayIterator<T>::get()
{
	return curPtr;
}

template<typename T>
bool DynamicArrayIterator<T>::equals(IIterator<T>* i)
{
	if (!i)
		return false;
	if (i->array != array)
		return false;
	return curPtr == i.get();
}

template<typename T>
void DynamicArray<T>::start(IIterator<T>** i) const
{

	DynamicArrayIterator<T>* iterator = new(context) DynamicArrayIterator<T>(this);
	iterator->curPtr = data;
	*i = iterator;

}

template<typename T>
void DynamicArray<T>::end(IIterator<T>** i) const
{
	DynamicArrayIterator<T>* iterator = new(context) DynamicArrayIterator<T>(this);
	iterator->curPtr = nullptr;
	*i = iterator;
}

template<typename T>
void DynamicArray<T>::appendLast(T&& t)
{

	if (size  >= capacity) {

		auto allocator = context->getDefaultGameMemoryAllocator();
		void* newData;
		allocator->getCommon(&newData, (capacity + selfGrowSize) * sizeof(T));
		allocator->memcpy(data, newData, capacity);
		capacity += selfGrowSize;
		allocator->retCommon(data);
		data = newData;
	}
	T* cur = data + size;
	*cur = t;
	++size;

}

template<typename T>
void DynamicArray<T>::appendHead(T&& t)
{
	auto allocator = context->getDefaultGameMemoryAllocator();
	if (size >= capacity) {
		void* newData;
		allocator->getCommon(&newData, (capacity + selfGrowSize) * sizeof(T));
		allocator->memcpy(data, newData + 1, capacity);
		allocator->retCommon(data);
		data = newData;
		capacity += selfGrowSize;

		*data = t;
		++size;
		return;
	}
	else {
		allocator->memcpy(data, data + 1, size);
		*data = t;
		++size;
	}

}
template<typename T>
int DynamicArray<T>::getCapacity()
{
	return capacity;
}

template<typename T>
int DynamicArray<T>::getSize()
{
	return size;
}

template<typename T>
void DynamicArray<T>::pop()
{
	if(size > 0)
		--size;

}

template<typename T>
void DynamicArray<T>::remove(IIterator<T>* i)
{

	if (!i) {
		throw "This iterator is nullptr!";
	}
	if (size <= 0){
		return;
	}
	const T* t = i->get();
	
	if(t >= data && t <= data + size - 1){
		int unit = t - data + 1;
		if (size - unit <= 0) {
			--size;
			return;
		}
		T* cur = data + unit;
		context->getDefaultGameMemoryAllocator()
			->memcpy(cur, cur - 1, sizeof(T) * (size - unit));
		--size;
	}


}
template<typename T>
void DynamicArray<T>::swap(IIterator<T>* i1, IIterator<T>* i2)
{
	const T* t1 = i1->get();
	const T* t2 = i2->get();

	if (t1 < data || t1 > data + size - 1 || t2 < data || t2 > data + size - 1) {
		return;
	}
	auto a = context->getDefaultGameMemoryAllocator();
	void* tmp;
	a->getCommon(&tmp, sizeof(T));
	a->memcpy(t1, tmp, sizeof(T));
	*t1 = *t2;
	*t2 = *tmp;
	a->retCommon(tmp);

}

template<typename T>
bool DynamicArray<T>::isEmpty()
{
	return size == 0;
}

template<typename T>
void DynamicArray<T>::clear()
{

	size = 0;

}

template<typename T>
bool DynamicArray<T>::isFull()
{
	return size == capacity;
}

template<typename T>
void DynamicArray<T>::sort()
{
	//还没开始写

}
