#pragma once
class IContext;
class Object {

public:

	void* operator new(unsigned long long size) = delete;

	void operator delete(void* ptr) = delete;

	void* operator new(unsigned long long size, IContext* c);

	void operator delete(void* ptr, IContext* c);

};