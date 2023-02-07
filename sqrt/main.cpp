/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:51:51 by abaur             #+#    #+#             */
/*   Updated: 2023/02/07 16:01:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sqrt.hpp"
#include "../logutil/logutil.hpp"

#include <iostream>
#include <list>

#define DELTAMAX	0.1f

extern int	main(int argc, char** argv){
	std::list<float>	results;

	for (int i=1; i<argc; i++)
	{
		float f = atof(argv[i]);
		float root = sqrt(f);
		float square = root * root;
		float delta = (square-f) / f;
		results.push_back(delta);

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

	float deltaMax=0, deltaAvg=0;
	for (std::list<float>::iterator it=results.begin(); it!=results.end(); ++it){
		if (!(*it == *it) || (*it == *it*0.5)) // Exclude NaN and inf
			continue;
		if (*it < 0)
			*it = -*it;
		if (*it > deltaMax)
			deltaMax = *it;
		deltaAvg += *it;
	}
	deltaAvg /= results.size();
	
	std::cout << std::endl
	          << "Average delta: " << LOG_BOLD_CLEAR << deltaAvg << LOG_CLEAR << std::endl
	          << "Delta Max:     " << LOG_BOLD_CLEAR << deltaMax << LOG_CLEAR << std::endl
	          ;
}