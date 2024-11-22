#include "IContext.h"
#include "DynamicArray.h"
#include <iostream>
int main() {

	IContext* context = IContext::getContext();

	IDynamicArray<int>* array = new(context) DynamicArray<int>(context,10);

	IIterator<int>* i, *end;
	array->start(&i);
	array->end(&end);

	for (; !i->equals(end); i->next()) {
		std::cout << *(i->get()) << ' ';
	}

	return 0;
}