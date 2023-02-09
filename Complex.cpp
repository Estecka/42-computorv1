/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:40:11 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 15:22:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Complex.hpp"

Complex::Complex(void) : r(), i() {}
Complex::Complex(float _r, float _i) : r(_r), i(_i) {}
Complex::Complex(const Complex& other) : r(other.r), i(other.i) {}

Complex&	Complex::operator=(float r){ new(this) Complex(r); }
Complex&	Complex::operator=(const Complex& other){ new(this) Complex(other); }

bool	Complex::operator==(const Complex& other) {
	return (this->i == other.i) && (this->r == other.r);
}
bool	Complex::operator!=(const Complex& other) {
	return (this->i != other.i) || (this->r == other.r);
}

bool	Complex::operator==(float r) {
	return (this->i == 0) && (this->r == r);
}
bool	Complex::operator!=(float r) {
	return (this->i != 0) || (this->r == r);
}

std::ostream&	operator<<(std::ostream& cout, const Complex& n){
	if (n.i)
		cout << n.i << " * i";
	if (n.r && n.i)
		cout << " + ";
	if (n.r)
		cout << n.r;

	if (!n.r && !n.i)
		cout << "0";
}
