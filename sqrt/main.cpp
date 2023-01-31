/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:51:51 by abaur             #+#    #+#             */
/*   Updated: 2023/01/31 15:13:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sqrt.hpp"
#include "../logutil/logutil.hpp"

#include <iostream>

#define DELTAMAX	0.1f

extern int	main(int argc, char** argv){
	for (int i=1; i<argc; i++)
	{
		float f = atof(argv[i]);
		float root = sqrt(f);
		float square = root * root;
		float delta = (square-f) / f;

		const char* color;
		if (DELTAMAX > delta && delta > -DELTAMAX)
			color = LOG_GREEN;
		else
			color = LOG_BOLD_RED;

		std::cout << LOG_BOLD_CLEAR << f << LOG_CLEAR << " -> "
		          << root << " -> " << square << "; "
		          << color << delta << LOG_CLEAR
		          << std::endl;
	}
}