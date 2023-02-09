/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptoa.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:51:57 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 13:55:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include <sstream>
#include <cstring>

/**
 * Prints a reduced form of "a * X^b".
 * This will print nothing if the expression reduces to 0.
 * @param factor	a
 * @param power 	b
 * @return	True if anything was output. False if the expression is 0.
 */
static bool	PowToString(std::stringstream& cout, float factor, int power, bool pretty){
	bool printX = power && factor;
	bool printPower = printX && (power > 1);
	bool printFactor = factor && (factor!=1 || !printX);

	if (printFactor)
		cout << factor;
	if (printFactor && printX && !pretty)
		cout << "*";
	if (printX)
		cout << (pretty?"x":"X");
	if (printPower)
		cout << (pretty?"²":"^2");

	return printFactor || printX || printPower;
}

std::string	ptoa(const Polynomial& poly, bool pretty){
	std::stringstream	cout;
	bool empty = true;

	for (int i=2; 0<=i; i--)
	if (poly[i]) {
		if (empty)
			PowToString(cout, poly[i], i, pretty);
		else if (poly[i] < 0){
			cout << " - ";
			PowToString(cout, -poly[i], i, pretty);
		}
		else {
			cout << " + ";
			PowToString(cout, poly[i], i, pretty);
		}
		empty = false;
	}

	if (empty)
		return "0 = 0";
	else {
		cout << " = 0";
		return cout.str();
	}
}

std::string	ctoa(const Complex& n){
	std::stringstream	cout;
	
	if (n[1])
		cout << n[1] << " * i";
	if (n[0] && n[1])
		cout << " + ";
	if (n[0])
		cout << n[0];

	return (!n[0] && !n[1]) ? "0" : cout.str();
}
