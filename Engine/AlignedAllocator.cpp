#include "Allocator.h"
#include <malloc.h>
/// 
/// 
/// 
/// 
/// 要注意的是
/// 返回的指针的上4个字节（转换为int*）代表着，返回的指针往前移动多少字节
/// 为初始申请的内存
/// 
void* AlignedAllocator::alignedMemoryAlloc(unsigned long long sz, int alignment)
{

	if (sz <= 0)
		throw "Size to alloc must be over 0";
	if (alignment < 0)
		throw "Alignment must be positive";

	unsigned long long to_alloc_sz = sz + alignment + sizeof(int);
	int* res = reinterpret_cast<int*>(malloc(to_alloc_sz));
	int* a = reinterpret_cast<int*>(
		((reinterpret_cast<unsigned long long>(res) / alignment) + 1)
		* alignment);
	int bias = a - res;
	*(a - 1) = bias;
	return reinterpret_cast<void*>(a);
	

}

void AlignedAllocator::tryFree(void* address)
{

	int* addr = reinterpret_cast<int*>(address);
	int bias = *(addr - 1);
	free(reinterpret_cast<void*>(reinterpret_cast<char*>(addr) - bias));

}