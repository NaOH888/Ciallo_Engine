#pragma once

class ISystem {

public:

	virtual void initialize() = 0;

	virtual void setLogCallback(void(*)(char*)) = 0;

	virtual ~ISystem() = 0;

};

class IFrameUpdateSystem : public ISystem {

public:

	virtual void start() = 0;

	virtual void update() = 0;

};

class IPassiveSystem : public ISystem {



};

class IGameMemoryAllocator : public IPassiveSystem {
/// IGameMemoryAllocator
/// 
///		[1] Single_Frame_Allocator 
///		[2] 64B Pool Allocator
///		[3] 1kB Pool Allocator
/// 	[4] 64kB Pool Allocator
/// 	[5] 1mB Pool Allocator
/// 	[6] 64mB Pool Allocator
/// 	[7] Large Memory Allocator
public:

	

};
class IString;
class IStringInternManager : public IPassiveSystem {

public:

	virtual int internString(const wchar_t*) = 0;

	virtual int internString(const IString*) = 0;

	virtual const wchar_t* get(int) = 0;

};


class IEditorFileSystem : public IPassiveSystem{

public:

	

	virtual const IString* getProjectPath() = 0;

	virtual void updateFiles() = 0;

	virtual unsigned long copyFileToSystem(IString*) = 0;

	

};