#include <string>

#include "convert.h"

struct Point {
	int x_, y_;

	std::string ToString() {
		return Format( std::to_string(x_), std::to_string(y_) );
	}
};
