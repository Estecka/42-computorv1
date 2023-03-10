/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:36:52 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 17:23:44 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"
#include "sqrt/sqrt.hpp"

#include <cstring>

static void	Deg0Solve (const Polynomial& poly, Solution& outSol){
	outSol.discriminant = 0;
	if (poly[0])
		outSol.solutionCount = 0;
	else
		outSol.solutionCount = -1;
}

static void	Deg1Solve (const Polynomial& poly, Solution& outSol){
	outSol.discriminant = poly[1] * poly[1];
	*outSol.solutions = -poly[0] / poly[1];
	outSol.solutionCount = 1;
}

static void	Deg2Solve (const Polynomial& poly, Solution& outSol){
	outSol.discriminant = (poly[1] * poly[1]) - (4 * poly[2] * poly[0]);

	if (outSol.discriminant == 0){
		*outSol.solutions = (-poly[1]) / (2*poly[2]);
		outSol.solutionCount = 1;
	}
	else if (outSol.discriminant > 0){
		double disRoot = sqrt(outSol.discriminant);
		outSol.solutions[0] = (-poly[1] - disRoot) / (2*poly[2]);
		outSol.solutions[1] = (-poly[1] + disRoot) / (2*poly[2]);
		outSol.solutionCount = 2;
	} 
	else {
		double disRoot = sqrt(-outSol.discriminant);
		outSol.solutions[0].r = (-poly[1]) / (2*poly[2]);
		outSol.solutions[0].i = (-disRoot) / (2*poly[2]);
		outSol.solutions[1].r =  outSol.solutions[0].r;
		outSol.solutions[1].i = -outSol.solutions[0].i;
		outSol.solutionCount = 2;
	}
}

extern void	PolySolve(const Polynomial& poly, Solution& outSol){
	bzero(&outSol, sizeof(outSol));

	if (poly[2] != 0){
		outSol.degree = 2;
		Deg2Solve(poly, outSol);
	}
	else if (poly[1] != 0){
		outSol.degree = 1;
		Deg1Solve(poly, outSol);
	}
	else{
		outSol.degree = 0;
		Deg0Solve(poly, outSol);
	}
}
