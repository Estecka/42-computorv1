/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:32 by abaur             #+#    #+#             */
/*   Updated: 2022/12/22 18:15:01 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

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
	std::cout << "┌─ " << expr << std::endl << "└> ";
	try {
		Polynomial	poly;
		atop(expr, poly);
		std::cout << ptoa(poly, pretty) << std::endl;
	}
	catch (std::exception& e){
		std::cerr << "[ERR] " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}
