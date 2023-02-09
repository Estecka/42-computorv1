/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:34:52 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 17:22:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

/**
 * Representation of a complex number.
 */
struct Complex {
	Complex(void);
	Complex(double r, double i=0);
	Complex(const Complex&);

	Complex&	operator=(const Complex&);
	Complex&	operator=(double r);
	bool	operator==(const Complex&) const;
	bool	operator!=(const Complex&) const;
	bool	operator==(double r) const;
	bool	operator!=(double r) const;
	bool	operator!() const;
	explicit operator bool() const;

	/**
	 * The Real portion of the number
	 */
	double r;
	/**
	 * The Complex portion of the number
	 */
	double i;
};

std::ostream&	operator<<(std::ostream& cout, const Complex& n);
