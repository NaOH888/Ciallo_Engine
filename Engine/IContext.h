#pragma once

 class ISystem;
 class IGameMemoryAllocator;

class IContext {

public:
	/// *************************************************************************
	///								initialize function
	/// *************************************************************************
	/// 
	/// [1] initialize all singletons systems
	/// 
	virtual void initialize() = 0;

	virtual void addSystem(ISystem*) = 0;
	virtual const IGameMemoryAllocator* getDefaultGameMemoryAllocator() = 0;
	static IContext* getContext();
};