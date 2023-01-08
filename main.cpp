/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:32 by abaur             #+#    #+#             */
/*   Updated: 2023/01/08 16:13:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include "./logutil/logutil.hpp"

#include <iostream>
#include <stdexcept>

extern int	main(int argc, char** argv){
	bool pretty = false;
	if (argc >= 2) {
		std::string a = argv[1];
		if (a=="--pretty" || a=="-p") {
			pretty = true;
		}
	}
	if (argc < (2+pretty))
		std::cerr << "Not enough arguments" << std::endl, exit(EXIT_FAILURE);

	const char* expr = argv[1+pretty];
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
