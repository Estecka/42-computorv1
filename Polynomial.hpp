/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:07:47 by abaur             #+#    #+#             */
/*   Updated: 2023/01/09 17:03:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

/**
 * Represents a polynomial of degree 0 to 2.
 * Each index representing the factor for the corresponding power of X.
 */
typedef float	Polynomial[3];

struct	Solution {
	int  	degree;
	float	discriminant;
	/*
 	 * The number of solutions between 0 and 2, or -1 if all real numbers 
	 * are solutions.
	 */
	int  	solutionCount;
	float	solutions[2];
};

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
 * @param outSol	Outputs the solutions, and other informations about the polynomial
 */
void	Solve(const Polynomial& poly, Solution& outSol);

std::string	Format(const Polynomial& poly, const Solution& sol);
