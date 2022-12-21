/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:07:47 by abaur             #+#    #+#             */
/*   Updated: 2022/12/21 17:24:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * Represents a polynomial of degree 0 to 2.
 * Each index representing the factor for the corresponding power of X.
 */
typedef float	Polynomial[3];

/**
 * Parses a string representing a polynomial.
 * @param str	The string to parse.
 * @param outPoly	Ouputs the resulting polynomial.
 * @return	The first invalid character in the expression.
 * 	A valid will still be produced for the preceding characters.
 * 	This will point to the null-terminator if the expression is valid.
 */
const char*	atop(const char* str, Polynomial& outPoly);

/**
 * Solves a polynomial equation
 * @param poly	The polynomial to solve
 * @param outDeg	Outputs the degree of the polynomial.
 * @param outDis	Outputs the discriminant of the polynomial.
 * @param outSol	Outputs the solution(s) of the polynomial.
 * @return	A formatted string presenting all the results.
 */
std::string	Solve(const Polynomial& poly, int& outDeg, float& outDis, float (&outSol)[2]);
