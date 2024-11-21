#pragma once

class IAlignedAllocator {

public:

	virtual void* alignedMemoryAlloc(unsigned long long sz, int alignment) = 0;

};

class IStackAllocator {

public:

	virtual const void* getStackTop() = 0;

	virtual void* memoryAlloc(unsigned long long sz) = 0;

	virtual bool isFull() = 0;

	virtual void freeTo(void* address) = 0;

	virtual void clear() = 0;

	virtual unsigned long long getFullStackSize() = 0;

	virtual unsigned long long getAllocatedSize() = 0;

	virtual void setFullStackSize(unsigned long long) = 0;
};

class IDoubleEndStackAllocator {

	virtual const void* getStackTop1() = 0;

	virtual const void* getStackTop2() = 0;

	virtual void clear() = 0;

	virtual void clear1() = 0;

	virtual void clear2() = 0;

	virtual unsigned long long getFullStackSize() = 0;

	virtual unsigned long long getAllocatedSize1() = 0;

	virtual unsigned long long getAllocatedSize2() = 0;

	virtual void memoryAlloc1(unsigned long long sz) = 0;

	virtual void memoryAlloc2(unsigned long long sz) = 0;

	virtual void freeTo1(void* address) = 0;

	virtual void freeTo2(void* address) = 0;

	virtual bool canAlloc(unsigned long long sz) = 0;

	virtual void setFullStackSize(unsigned long long) = 0;

};

class IPoolAllocator {

	virtual void* memoryAlloc(unsigned long long sz) = 0;

	virtual unsigned long long getUnitSize() = 0;

	virtual int getUnitCount() = 0;

	virtual int getUsableUnitCount() = 0;

	virtual bool canAlloc(unsigned long long sz) = 0;

	virtual void clear() = 0;

	virtual void free(void*) = 0;

	virtual int getUnitIndex(void*) = 0;

	virtual void freeUnit(int index) = 0;

	virtual void setFullPoolSize(unsigned long long) = 0;
	
	virtual unsigned long long getFullPoolSize() = 0;

	
};