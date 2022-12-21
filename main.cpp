/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:32 by abaur             #+#    #+#             */
/*   Updated: 2022/12/21 20:20:20 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include <iostream>

extern int	main(int argc, char** argv){
	bool pretty = false;
	const char*const* factors = argv+1;
	if (argc >= 2) {
		std::string a = argv[1];
		if (a=="--pretty" || a=="-p") {
			pretty = true;
			factors++;
		}
	}
	if (argc < (4+pretty))
		std::cerr << "Not enough arguments" << std::endl, exit(EXIT_FAILURE);


	Polynomial	poly;
	for (int i=0; i<3; i++){
		poly[2-i] = atoi(factors[i]);
		std::cout << poly[2-i] << ' ';
	}

	std::cout << " ->  " << ptoa(poly, pretty) << std::endl;
}
