/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:34:52 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 14:48:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

/**
 * Representation of a complex number.
 */
struct Complex {
	Complex(void);
	Complex(float r, float i=0);
	Complex(const Complex&);

	Complex&	operator=(const Complex&);
	Complex&	operator=(float r);
	bool	operator==(const Complex&);
	bool	operator!=(const Complex&);
	bool	operator==(float r);
	bool	operator!=(float r);

	/**
	 * The Complex portion of the number
	 */
	float i;
	/**
	 * The Real portion of the number
	 */
	float r;
};

std::ostream&	operator<<(std::ostream& cout, const Complex& n);
