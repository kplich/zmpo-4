#include "pch.h"
#include "KnapsackProblem.h"
#include <string>
#include <iostream>
#include "Individual.h"
#include "Algorithm.h"

void solve_problem();

void debugging();

int main()
{
	solve_problem();
}

void solve_problem()
{
	int min_population = 4;
	int max_population = 256;

	int repeats_per_population = 30;

	std::ifstream problem_file("problem1.txt");
	KnapsackProblem problem(&problem_file);

	std::ofstream results_file("results.txt");
	for (int pop = min_population; pop < max_population; pop *= 2)
	{
		results_file << pop << "\t";
		std::cout << "pop: " << pop << "\n";
		for (int i = 0; i < repeats_per_population; i++)
		{
			Algorithm my_algorithm(&problem, 5, pop);
			Individual* found = my_algorithm.solve();

			std::cout << found->to_string();

			results_file << evaluate_fitness(found, &problem) << "\t";
		}
		results_file << "\n";
	}
}

void debugging()
{
	std::ifstream problem_file("problem1.txt");
	KnapsackProblem problem(&problem_file);

	Algorithm my_algorithm(&problem, 5, 8, 0.03, 0.6);
	Individual* found = my_algorithm.solve();

	std::cout << found->to_string();
}