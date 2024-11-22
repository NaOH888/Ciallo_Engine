#include "Allocator.h"

PoolAllocator::PoolAllocator(unsigned long long min_alloc_size, int capacity, int alignedSize)
{

	this->unit_size = (min_alloc_size / alignedSize + 1) * alignedSize;
	this->capacity = capacity;
	size = 0;
	alignedAllocator = new AlignedAllocator();
	data = alignedAllocator->alignedMemoryAlloc(unit_size * capacity, alignedSize);
	usable_mask = new bool[capacity];
	this->alignedSize = alignedSize;
}

void* PoolAllocator::memoryAlloc()
{
	if (size < capacity) {
		int ind = findFirstUsableUnit();
		void* res = reinterpret_cast<void*>(reinterpret_cast<char*>(data) + size * ind);
		++size;
		return res;

	}

	return nullptr;
}
unsigned long long PoolAllocator::getUnitSize()
{
	return unit_size;
}
int PoolAllocator::getUnitCount()
{
	return size;
}
int PoolAllocator::getUsableUnitCount()
{
	return capacity - size;
}
void PoolAllocator::clear()
{
	for (int i = 0; i < capacity; ++i) {
		usable_mask[i] = true;
	}
	size = 0;

}
void PoolAllocator::free(void* address)
{
	int ind = getUnitIndex(address);
	if (ind == -1)
		return;
	usable_mask[ind] = true;
}

int PoolAllocator::findFirstUsableUnit()
{
	for (int i = 0; i < capacity; ++i) {
		if (usable_mask[i]) {
			return i;
		}
	}
	return -1;
}
int PoolAllocator::getUnitIndex(void* address)
{
	unsigned long long addr = reinterpret_cast<unsigned long long>(address);
	unsigned long long start = reinterpret_cast<unsigned long long>(data);
	unsigned long long end = start + size * capacity;
	if (addr < start || addr >= end) {
		return -1;
	}
	int unit_ind = int((addr - start) / unit_size) * unit_size;
	return unit_ind;
}
void PoolAllocator::freeUnit(int index)
{

	if (index >= 0 && index < capacity) {
		usable_mask[index] = true;
	}

}
#include "Utils.h"
void PoolAllocator::setCapacity(int capa)
{

	if (capa == capacity)
		return;
	if (capa <= 0)
		throw "capacity must be over 0";
	void* newData = alignedAllocator->alignedMemoryAlloc(unit_size * capa, alignedSize);
	bool* newMask = new bool[capa];
	Utils::memoryCopy(data, unit_size * Utils::min(capa, capacity), newData);
	int m = Utils::min(capa, capacity);
	for (int i = 0; i < m; ++i) {
		*(newMask + i) = *(usable_mask + i);
	}
	alignedAllocator->tryFree(data);
	delete[] usable_mask;

	data = newData;
	usable_mask = newMask;
	capacity = capa;
	size = Utils::min(size,capa);
}
unsigned long long PoolAllocator::getFullPoolSize()
{
	return capacity * unit_size;
}

PoolAllocator::~PoolAllocator()
{

	alignedAllocator->tryFree(data);
	delete[] usable_mask;
	usable_mask = nullptr;
	data = nullptr;
	capacity = 0;

}