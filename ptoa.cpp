/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptoa.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:51:57 by abaur             #+#    #+#             */
/*   Updated: 2022/12/21 18:43:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include <sstream>

/**
 * Prints a reduced form of "a * X^b".
 * This will print nothing if the expression reduces to 0.
 * @param factor	a
 * @param power 	b
 * @return	True if anything was output. False if the expression is 0.
 */
static bool	PowToString(std::stringstream& cout, float factor, int power){
	bool printX = power && factor;
	bool printPower = printX && (power > 1);
	bool printFactor = factor && (factor!=1 || !printX);

	if (printFactor)
		cout << factor;
	if (printFactor && printX)
		cout << " * ";
	if (printX)
		cout << "X";
	if (printPower)
		cout << "^" << power;

	return printFactor || printX || printPower;
}

std::string	ptoa(const Polynomial& poly){
	std::stringstream	cout;
	bool empty = true;

	for (int i=2; 0<=i; i--)
	if (poly[i]) {
		if (empty)
			PowToString(cout, poly[i], i);
		else if (poly[i] < 0){
			cout << " - ";
			PowToString(cout, -poly[i], i);
		}
		else {
			cout << " + ";
			PowToString(cout, poly[i], i);
		}
		empty = false;
	}

	if (empty)
		return "0";
	else
		return cout.str();
}
