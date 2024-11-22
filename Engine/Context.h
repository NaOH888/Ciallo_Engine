#include "IContext.h"

class Context : public IContext {

public:

	void initialize() override;

	void addSystem(ISystem*) override;

	const IGameMemoryAllocator* getDefaultGameMemoryAllocator() override;

private:

	IGameMemoryAllocator* defaultGameMemoryAllocator;

};