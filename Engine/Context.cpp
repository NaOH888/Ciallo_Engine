#include "Context.h"
#include "GameMemoryAllocator.h"
void Context::initialize()
{

	defaultGameMemoryAllocator = new GameMemoryAllocator();
	defaultGameMemoryAllocator->initialize();

}
void Context::addSystem(ISystem*)
{

	//咱不是先

}
const IGameMemoryAllocator* Context::getDefaultGameMemoryAllocator()
{
	return defaultGameMemoryAllocator;
}
IContext* IContext::getContext()
{
	return new Context;
}