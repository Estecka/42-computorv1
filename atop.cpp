/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:14:57 by abaur             #+#    #+#             */
/*   Updated: 2023/01/08 16:18:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

#include <map>
#include <stdexcept>
#include <cstring>

/**
 * Represents a polynomial of an arbitrary degree
 */
typedef std::map<int, float>	PolyDraft;


static const char*	SkipSpace(const char* str){
	while (std::isspace(*str))
		str++;
	return str;
}

static char	GetPrettyChar(const char*& str){
	static const char*const charset[] = {"⁰","¹","²","³","⁴","⁵","⁶","⁷","⁸","⁹","⁺","⁻"};
	static const char*const transchar = "0123456789+-";
	for (int chr=0; chr<12; chr++)
	for (int bit=0; true;   bit++){
		if (!charset[chr][bit]){
			str = str+bit;
			return transchar[chr];
		}
		if (charset[chr][bit] != str[bit])
			break;
	}

	return '\0';
}

static bool	GetPrettyExponent(const char*& str, int& outPower){
	char c;
	int sign = 1;
	bool hasDigit = false;

	if (!(c = GetPrettyChar(str)))
		return false;
	outPower = 0;
	if (c == '-')
		sign = -1;
	else if (c != '+')
		hasDigit=true, outPower = c - '0';

	while((c = GetPrettyChar(str))){
		if ('0' < c && c < '9')
			hasDigit=true, outPower = (10*outPower) + (sign*(c-'0'));
		else
			throw std::runtime_error("Invalid pretty exponent");
	}

	if (!hasDigit)
		throw std::runtime_error("Invalid pretty exponent");

	return true;
}

static bool	GetExponent(const char*& str, int& outPower){
	if (*str != '^')
		return false;
	else {
		char* terminator;
		str++;
		outPower = std::strtol(str, &terminator, 10);
		if (str == terminator)
			throw std::runtime_error("Invalid exponent");
		else
			str = terminator;
		return true;
	}
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
		outPower = 1;
		GetExponent(str, outPower) || GetPrettyExponent(str, outPower);
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
static void GetEqHalf(const char*& str, PolyDraft& outPolydraft){
	int   sign = 1;
	float factor;
	int   power;

	do {
		GetAddOperand(str, factor, power);
		outPolydraft[power] += factor * sign;
	} while( (sign=GetAdd(str)) );
}

extern void	atop(const char* str, Polynomial& outPoly){
	PolyDraft	left;

	GetEqHalf(str, left);

	if (*str == '='){
		PolyDraft right;
		GetEqHalf(++str, right);

		for (PolyDraft::iterator it=right.begin(); it!=right.end(); it++)
			left[it->first] -= it->second;
	}

	if (*str)
		throw std::runtime_error("Unexpected character");

	bzero(outPoly, sizeof(Polynomial));
	for (PolyDraft::iterator it=left.begin(); it!=left.end(); it++)
	{
		int   pow = it->first;
		float fac = it->second;

		if (0<=pow && pow<=2)
			outPoly[pow] += fac;
		else if (fac != 0)
			throw std::out_of_range("Unsupported power of X");
	}
}
