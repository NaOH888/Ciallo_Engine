#pragma once
#include "IAllocator.h"
class AlignedAllocator : public IAlignedAllocator{

public:

	void* alignedMemoryAlloc(unsigned long long sz, int alignment) override;

	void tryFree(void* adress) override;

};

class PoolAllocator : public IPoolAllocator {

public:

	PoolAllocator(
		unsigned long long min_alloc_size,
		int capacity,
		int alignedSize);

	void* memoryAlloc() override;

	unsigned long long getUnitSize() override;

	int getUnitCount() override;

	int getUsableUnitCount() override;

	void clear() override;

	void free(void*) override;

	int getUnitIndex(void*) override;

	void freeUnit(int index) override;

	void setCapacity(int) override;

	~PoolAllocator() override;

	unsigned long long getFullPoolSize() override;

	int findFirstUsableUnit();

private:

	void* data = nullptr;

	bool* usable_mask = nullptr;

	IAlignedAllocator* alignedAllocator = nullptr;

	unsigned long long unit_size;

	int capacity;

	int size;

	unsigned long long alignedSize;

};