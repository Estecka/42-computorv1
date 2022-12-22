/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:14:57 by abaur             #+#    #+#             */
/*   Updated: 2022/12/22 18:05:31 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include <cstring>
#include <stdexcept>


static const char*	SkipSpace(const char* str){
	while (std::isspace(*str))
		str++;
	return str;
}

/**
 * @param outPower	The resulting power of X, or 0 if none was found.
 * @return	Whether a valid power of X was found.
 */
static bool	GetXPower(const char*& str, int& outPower){
	if (*str!='X' && *str!='x'){
		outPower = 0;
		return false;
	}
	else {
		str++;
		if (*str == '^'){
			char* terminator;
			str++;
			outPower = std::strtol(str, &terminator, 10);
			if (str == terminator)
				throw std::runtime_error("Invalid exponent");
			else
				str = terminator;
		}
		else
			outPower = 1;
		return true;
	}
}

/**
 * @param outFactor	The resulting float, or 1 if none was found.
 * @return	Whether a valid float was found.
 */
static bool	GetFloat(const char*& str, float& outFactor){
	char* terminator;
	outFactor = std::strtof(str, &terminator);
	if (str == terminator){
		outFactor = 1;
		return false;
	}
	else {
		str = terminator;
		return true;
	}
}

/**
 * Parses nX^b.
 * Input string may ommit either n or X, but must contain at least.
 * @param outfactor	n, or 1 if ommited.
 * @param outPower	b, or 0 if ommited.
 */
static void	GetMulOperand(const char*& str, float& outFactor, int& outPower){
	bool hasData = false;

	str = SkipSpace(str);
	hasData |= GetFloat(str, outFactor);
	hasData |= GetXPower(str, outPower);

	if (!hasData)
		throw std::runtime_error("Invalid operand");
}

static bool	GetMul(const char*& str){
	str = SkipSpace(str);
	if (*str == '*')
		return str++, true;
	else
		return false;
}


static void	GetAddOperand(const char*& str, float& outFactor, int& outPower){
	outFactor = 1;
	outPower  = 0;

	do {
		float fac;
		int   pow;
		GetMulOperand(str, fac, pow);
		outFactor *= fac;
		outPower  += pow;
	} while(GetMul(str));
}

/**
 * Parses a '+' or a '-'
 * @return +1 or -1 if an operator is found, 0 otherwise.
 */
static int	GetAdd(const char*& str){
	str = SkipSpace(str);
	if (*str == '+')
		return str++, 1;
	else if (*str == '-')
		return str++, -1;
	else
		return 0;
}


/**
 * Parses one half of an equation; separated by '='.
 */
static void GetEqHalf(const char*& str, Polynomial& outPoly){
	int   sign = 1;
	float factor;
	int   power;

	do {
		GetAddOperand(str, factor, power);
		if (power < 0 || 2 < power)
			throw std::out_of_range("Unsupported power of X");
		outPoly[power] += factor * sign;
	} while( (sign=GetAdd(str)) );
}

extern void	atop(const char* str, Polynomial& outPoly){
	bzero(outPoly, sizeof(Polynomial));
	GetEqHalf(str, outPoly);

	if (*str == '='){
		Polynomial anti;
		bzero(anti, sizeof(Polynomial));
		GetEqHalf(++str, anti);

		for (int i=0; i<2; i++)
			outPoly[i] -= anti[i];
	}

	if (*str)
		throw std::runtime_error("Unexpected character in equation");
}
