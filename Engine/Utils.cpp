#include "Utils.h"
#include <string.h>
namespace Utils {

	void memoryCopy(void* src,
		unsigned long long copy_count,
		void* des)
	{

		memcpy(des, src, copy_count);

	}

	double max(double a, double b) {

		return a > b ? a : b;

	}

	double min(double a, double b) {

		return a < b ? a : b;

	}

}
