#pragma once
#include "ISystem.h"
class IPoolAllocator;
class GameMemoryAllocator : public IGameMemoryAllocator {

public:

	void initialize() override;

	void setLogCallback(void(*)(const char*)) override;

	~GameMemoryAllocator() override;

	void getCommon(void** buffer, unsigned long long size) const override;

	bool retCommon(void* buf) const override;

	bool memcpy(void* origin, void* des, unsigned long long size) const override;

private:

	IPoolAllocator* _64B_allocator = nullptr;
	IPoolAllocator* _1kB_allocator = nullptr;
	IPoolAllocator* _64kB_allocator = nullptr;
	IPoolAllocator* _1mB_allocator = nullptr;
	IPoolAllocator* _64mB_allocator = nullptr;

	void(*callback)(const char*);

};