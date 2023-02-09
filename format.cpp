/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:10:21 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 16:06:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"
#include "logutil/logcolors.hpp"

#include <sstream>

std::string	SolutionFormat(const Polynomial& poly, const Solution& sol, bool pretty){
	std::stringstream format;

	format << "Reduced form: " << LOG_CYAN << ptoa(poly, pretty) << LOG_CLEAR << std::endl
	       << "Polynomial degree: " << sol.degree << std::endl
	       ;
	
	if (sol.degree == 2)
		format << "Discriminant: " << sol.discriminant << std::endl;

	if (sol.solutionCount < 0)
		format << "Every real number is a solution." << std::endl;
	else if (sol.solutionCount == 0)
		format << "The equation has no real solution." << std::endl;
	else if (sol.solutionCount == 1){
		format << "The solution is: " << std::endl
		       << '\t' << LOG_CYAN << *sol.solutions << LOG_CLEAR << std::endl
		       ;
	}
	else if (sol.solutionCount == 2){
		if (sol.discriminant < 0)
			format << "The Complex solutions are: " << std::endl;
		else
			format << "The Real solutions are: " << std::endl;
		format << '\t' << LOG_CYAN << sol.solutions[0] << LOG_CLEAR << std::endl
		       << '\t' << LOG_CYAN << sol.solutions[1] << LOG_CLEAR << std::endl
		       ;
	}

	return format.str();
}
