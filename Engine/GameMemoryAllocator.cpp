#include "GameMemoryAllocator.h"
#include "Allocator.h"
void GameMemoryAllocator::initialize()
{
	_64B_allocator = new PoolAllocator(64, 10, 4);
	_1kB_allocator = new PoolAllocator(1024, 10, 4);
	_64kB_allocator = new PoolAllocator(1024 * 64, 10, 4);
	_1mB_allocator = new PoolAllocator(1024 * 1024, 10, 4);
	_64mB_allocator = new PoolAllocator(1024 * 1024 * 64, 10, 4);



}
void GameMemoryAllocator::setLogCallback(void(*cb)(const char*))
{
	callback = cb;
}

GameMemoryAllocator::~GameMemoryAllocator()
{


	delete _64B_allocator;
	delete _1kB_allocator;
	delete _64kB_allocator;
	delete _1mB_allocator;
	delete _64mB_allocator;

}

void GameMemoryAllocator::getCommon(void** buffer, unsigned long long size) const
{

	if (size <= 0)
		throw "Size to alloc should be over 0";

	if (size > 1024ULL * 1024ULL * 64ULL) {
		*buffer = nullptr;
		return;
	}
	if (size <= 64) {
		*buffer = _64B_allocator->memoryAlloc();
	}
	else if (size <= 1024){
		*buffer = _1mB_allocator->memoryAlloc();
	}
	else if (size <= 1024ULL * 64ULL) {
		*buffer = _64kB_allocator->memoryAlloc();
	}
	else if (size <= 1024ULL * 1024ULL) {
		*buffer = _1mB_allocator->memoryAlloc();
	}
	else {
		*buffer = _64mB_allocator->memoryAlloc();
	}
	return;

}
bool GameMemoryAllocator::retCommon(void* buf) const
{
	if (!buf)
		return false;
	if (_64B_allocator->getUnitIndex(buf) != -1) {
		_64B_allocator->free(buf);
	}
	else if (_1kB_allocator->getUnitIndex(buf) != -1) {
		_1kB_allocator->free(buf);
	}
	else if (_64kB_allocator->getUnitIndex(buf) != -1) {
		_64kB_allocator->free(buf);
	}
	else if (_1mB_allocator->getUnitIndex(buf) != -1) {
		_1mB_allocator->free(buf);
	}
	else if (_64mB_allocator->getUnitIndex(buf) != -1) {
		_64mB_allocator->free(buf);
	}
	return true;
}
#include "Utils.h"
bool GameMemoryAllocator::memcpy(void* origin, void* des, unsigned long long size) const
{
	if (!origin)
		return false;
	if (!des)
		return false;
	if (size <= 0)
		return false;
	Utils::memoryCopy(origin, size, des);
	return true; //?
}