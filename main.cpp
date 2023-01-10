/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:32 by abaur             #+#    #+#             */
/*   Updated: 2023/01/10 14:27:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include "./logutil/logutil.hpp"

#include <iostream>
#include <stdexcept>

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
	std::cout << "Base form: " LOG_BOLD_CLEAR << expr << LOG_CLEAR << std::endl;
	try {
		Polynomial	poly;
		Solution	solution;
		std::string	format;

		atop(expr, poly);
		PolySolve(poly, solution);
		std::cout << SolutionFormat(poly, solution, pretty) << std::endl;
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
