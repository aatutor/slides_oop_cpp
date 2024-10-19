// #define _CRT_SECURE_NO_WARNINGS
#include "solve.h"

#include "test/tests.cc"

int main ()
{
#if PUB
	PublicTest();
#else
	FullTest();
#endif

	return 0;
}
