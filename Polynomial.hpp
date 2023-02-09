/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynomial.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:07:47 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 13:42:54 by abaur            ###   ########.fr       */
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
 * Represents a complex number.
 * - [0]	The Real portion of the number.
 * - [1]	The factor of i.
 */
typedef float	Complex[2];

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
 * Returns a string representation of the given complex number.
 */
std::string	ctoa(const Complex& n);


/**
 * Solves a polynomial equation
 * @param poly	The polynomial to solve
 * @param outSol	Outputs the solutions, and other informations about the polynomial
 */
void	PolySolve(const Polynomial& poly, Solution& outSol);

/**
 * Returns the value of the equation `poly` for the given value of x.
 */
float	PolyCompute(const Polynomial& poly, float x);
/**
 * Computes the value of the equation `poly` for the given value of x.
 * @param outResult	Outputs the result as a complex number.
 */
void	PolyCompute(const Polynomial& poly, const Complex& x, Complex outResult);

std::string	SolutionFormat(const Polynomial& poly, const Solution& sol, bool pretty=false);
