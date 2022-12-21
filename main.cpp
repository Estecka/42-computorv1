/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:33:32 by abaur             #+#    #+#             */
/*   Updated: 2022/12/21 19:03:38 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include <iostream>

extern int	main(int argc, char** argv){
	if (argc != 4)
		std::cerr << "Wrong number of arguments" << std::endl, exit(EXIT_FAILURE);


	Polynomial	poly;
	for (int i=0; i<3; i++){
		poly[2-i] = atoi(argv[i+1]);
		std::cout << poly[2-i] << ' ';
	}

	std::cout << " ->  " << ptoa(poly) << std::endl;
}
