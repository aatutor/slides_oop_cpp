#include "verify.h"

#include <iostream>

void PublicTest() {
	using namespace std;
	Point a{1, 2}, b{3, 4};

	cout << a.ToString() << endl; // (1, 2)
	cout << b.ToString() << endl; // (3, 4)
}
void FullTest() {
	// using namespace std;
	Verify pts("Points");
	
	Point a{1, 2}, b{3, 4};

	pts.Assert<int>( GET(a.x_), 1 ); // Test 1
	pts.Assert<int>( GET(a.y_), 2 ); // Test 2

	pts.Assert( GET(b.x_ == 3 && b.y_ == 4) );	// Test 3

	pts.Assert<std::string>( GET(a.ToString()), "(1, 2)" ); // Test 4
	pts.Assert<std::string>( RUN(return b.ToString();), "(3, 4)" ); // Test 5

	pts.Total();
}