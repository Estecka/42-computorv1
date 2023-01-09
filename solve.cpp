/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:36:52 by abaur             #+#    #+#             */
/*   Updated: 2023/01/09 16:53:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

static int	Deg0Solve (const Polynomial& poly, float& outDis, float (&outSol)[2]){
	outDis = 0;
	if (poly[0])
		return 0;
	else
		return -1;
}

static int	Deg1Solve (const Polynomial& poly, float& outDis, float (&outSol)[2]){
	outDis = poly[1] * poly[1];
	*outSol = -poly[0] / poly[1];
	return 1;
}

static int	Deg2Solve (const Polynomial& poly, float& outDis, float (&outSol)[2]){
	outDis = (poly[1] * poly[1]) - (4 * poly[2] * poly[0]);

	if (outDis == 0){
		*outSol = (-poly[1]) / (2*poly[2]);
		return 1;
	}
	else if (outDis > 0){
		float disRoot = -1; // to do
		outSol[0] = (-poly[1] - disRoot) / (2*poly[2]);
		outSol[1] = (-poly[1] + disRoot) / (2*poly[2]);
		return 2;
	} 
	else
		return 0;
}

extern int	Solve(const Polynomial& poly, int& outDeg, float& outDis, float (&outSol)[2]){
	if (poly[2] != 0)
		outDeg = 2;
	else if (poly[1] != 0)
		outDeg = 1;
	else
		outDeg = 0;

	switch (outDeg){
		case 2: return Deg2Solve(poly, outDis, outSol);
		case 1: return Deg1Solve(poly, outDis, outSol);
		case 0: return Deg0Solve(poly, outDis, outSol);
		default: return 0;
	}
}
