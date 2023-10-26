#include <iostream>
#include "mymath.h"

int main()
{
	int iterations = 1000000; // 1 million iterations

	for (int i = 0; i <= iterations; i++)
	{
		int a = 10;
		int b = 5;
		int sum = mymath::add(a, b);
		int difference = mymath::subtract(a, b);

		// Printing results in each iteration is optional
		std::cout << "Iteration " << i + 1 << ": Sum: " << sum << ", Difference: " << difference << std::endl;
	}

	// Printing the results after all iterations
	std::cout << "All iterations completed." << std::endl;

	return 0;
}
