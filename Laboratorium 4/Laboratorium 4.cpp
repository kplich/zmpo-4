#include "pch.h"
#include "KnapsackProblem.h"
#include <string>
#include <iostream>
#include "Individual.h"
#include "Algorithm.h"

void solve_with_stats();

void debugging();

int main()
{
	debugging();
}

void solve_with_stats()
{
	int min_iterations = 5;
	int max_iterations = 50;

	int repeats = 30;

	std::ifstream problem_file("problem-wojtek.txt");
	KnapsackProblem problem(&problem_file);

	std::ofstream results_file("results.txt");
	for (int iter = min_iterations; iter < max_iterations; iter +=2)
	{
		results_file << iter << "\t";
		std::cout << "pop: " << iter << "\n";
		for (int i = 0; i < repeats; i++)
		{
			Algorithm my_algorithm(&problem, iter, 32, 0.01, 0.5);
			Individual* found = my_algorithm.solve();

			std::cout << found->to_string();

			results_file << found->get_fitness() << "\t";
		}
		results_file << "\n";
	}
}

void debugging()
{
	std::ifstream problem_file("problem-wojtek.txt");
	KnapsackProblem problem(&problem_file);

	Algorithm my_algorithm(&problem, 15, 32, 0.01, 0.7);
	Individual* found = my_algorithm.solve();

	if (found != nullptr) {
		std::cout << found->to_string();
	}
}