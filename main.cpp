/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:32 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 17:35:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include "./logutil/logutil.hpp"

#include <iostream>
#include <stdexcept>

#define DELTA_MAX	1e-14
#define CHECK_DELTA_REAL(n)	(DELTA_MAX >= n && n >= -DELTA_MAX)
#define CHECK_DELTA_CPLX(n)	(CHECK_DELTA_REAL(n.r) && CHECK_DELTA_REAL(n.i))

static int	Check(const Polynomial& poly, Solution sol){
	Complex r[2] = { 0, 0 };
	Complex t[2] = { 0, 0 };

	if (sol.solutionCount >= 2)
		r[1] = PolyCompute(poly, t[1]=sol.solutions[1]);
	if (sol.solutionCount >= 1)
		r[0] = PolyCompute(poly, t[0]=sol.solutions[0]);
	if (sol.solutionCount < 0){
		r[0] = PolyCompute(poly, t[0]=rand()/double(RAND_MAX));
		r[1] = PolyCompute(poly, t[1]=rand()/double(RAND_MAX));
	}

	if (sol.solutionCount == 0){
		// std::cout << LOG_BOLD_YELLOW "Check manually" LOG_CLEAR << std::endl;
		return EXIT_SUCCESS;
	}
	else if (!r[0] && !r[1]){
		std::cout << LOG_BOLD_GREEN "Solutions OK" LOG_CLEAR << std::endl;
		return EXIT_SUCCESS;
	}
	else 
	{
		bool ok[2] = {
			CHECK_DELTA_CPLX(r[0]),
			CHECK_DELTA_CPLX(r[1]),
		};

		if (ok[0] && ok[1])
			std::cout << LOG_BOLD_GREEN "Solution acceptable" << std::endl;

		for (int i=0; i<2; i++) 
		if(r[i]) {
			if (ok[i])
				std::cout << LOG_BOLD_YELLOW;
			else
				std::cout << LOG_BOLD_RED "KO: ";

			std::cout <<"f("<<t[i]<<") = " << r[i] << LOG_CLEAR << std::endl;
		}

		return (ok[0] && ok[1]) ? EXIT_SUCCESS : EXIT_FAILURE;
	}
}

static void	Reduce(const char* expr, bool pretty){
	std::cout << "┌─ " LOG_BOLD_CLEAR << expr << std::endl << LOG_CLEAR "└> ";
	try {
		Polynomial	poly;
		atop(expr, poly);
		std::cout << LOG_CYAN << ptoa(poly, pretty) << LOG_CLEAR << std::endl;
	}
	catch (std::exception& e){
		std::cerr << LOG_BOLD_RED "[ERR] " LOG_RED << e.what() << LOG_CLEAR << std::endl;
		exit(EXIT_FAILURE);
	}
}

static void	Solve(const char* expr, bool pretty){
	std::cout << "Input form:   " LOG_BOLD_CLEAR << expr << LOG_CLEAR << std::endl;
	try {
		Polynomial	poly;
		Solution	solution;
		std::string	format;

		atop(expr, poly);
		PolySolve(poly, solution);
		std::cout << SolutionFormat(poly, solution, pretty);
		int r = Check(poly, solution);
		std::cout << std::endl;
		exit (r);
	}
	catch (std::exception& e){
		std::cerr << LOG_BOLD_RED "[ERR] " LOG_RED << e.what() << LOG_CLEAR << std::endl;
		exit(EXIT_FAILURE);
	}
}

extern int	main(int argc, char** argv){
	bool pretty = false;
	bool reduce = false;

	argc++, argv++;
	for ( ; argc>0; argc++, argv++){
		std::string a = *argv;
		if (a=="--pretty" || a=="-p")
			pretty = true;
		else if (a=="--reduce" || a=="-r")
			reduce = true;
		else
			break;
	}

	if (argc < (1)){
		std::cerr << "Not enough arguments" << std::endl;
		exit(EXIT_FAILURE);
	}

	const char* expr = argv[0];
	if (reduce)
		Reduce(expr, pretty);
	else
		Solve(expr, pretty);
}
