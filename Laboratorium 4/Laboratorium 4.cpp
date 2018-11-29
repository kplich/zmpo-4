#include "pch.h"
#include "KnapsackProblem.h"
#include <string>
#include <iostream>
#include "Individual.h"

int main()
{
	std::ifstream problem_file("problem1.txt");
	KnapsackProblem problem(&problem_file);

	if(problem.is_valid())
	{
		std::cout << problem.to_string();
	}
	else
	{
		std::cout << "got one more more problem\n";
	}

	Individual first(problem.get_number_of_items());
	std::cout << first.to_string();

	Individual second(first);
	std::cout << second.to_string();

	second.mutate(0.1);
	std::cout << second.to_string();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
