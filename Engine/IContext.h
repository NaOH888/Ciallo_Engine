#pragma once

class IContext {

public:
	/// *************************************************************************
	///								initialize function
	/// *************************************************************************
	/// 
	/// [1] initialize all singletons systems
	/// 
	virtual void initialize() = 0;

};