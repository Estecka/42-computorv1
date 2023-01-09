/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:07:47 by abaur             #+#    #+#             */
/*   Updated: 2023/01/08 17:22:15 by abaur            ###   ########.fr       */
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
 * @throw
 * 	std::runtime_error if the expression is invalid.
 * 	std::out_of_range if the polynomial is of a degree greater than 2.
 */
void	atop(const char* str, Polynomial& outPoly);

/**
 * Returns	A reduced string representation of the given polynomial.
 * @param pretty	Will return a prettier, more condensed representation,
 *  using special characters for exponents.
 */
std::string	ptoa(const Polynomial& poly, bool pretty=false);

/**
 * Solves a polynomial equation
 * @param poly	The polynomial to solve
 * @param outDeg	Outputs the degree of the polynomial.
 * @param outDis	Outputs the discriminant of the polynomial.
 * @param outSol	Outputs the solution(s) of the polynomial.
 * @return	The number of solutions, between 0 and 2. 
 * 	Or -1 if all real numbers are solutions.
 */
int	Solve(const Polynomial& poly, int& outDeg, float& outDis, float (&outSol)[2]);
