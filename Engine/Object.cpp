#include "IObject.h"
#include "IContext.h"
#include "ISystem.h"

void* Object::operator new(unsigned long long size, IContext* c) {

	void* ret = nullptr;
	const IGameMemoryAllocator* allocator = c->getDefaultGameMemoryAllocator();
	allocator->getCommon(&ret, size);
	return ret;

}

void Object::operator delete(void* ptr, IContext* c)
{

	auto allocator = c->getDefaultGameMemoryAllocator();
	allocator->retCommon(ptr);// 需要修改！

}