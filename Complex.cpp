/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:40:11 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 17:22:59 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Complex.hpp"

Complex::Complex(void) : r(), i() {}
Complex::Complex(double _r, double _i) : r(_r), i(_i) {}
Complex::Complex(const Complex& other) : r(other.r), i(other.i) {}

Complex&	Complex::operator=(double r){ return *new(this) Complex(r); }
Complex&	Complex::operator=(const Complex& other){ return *new(this) Complex(other); }

bool	Complex::operator==(const Complex& other) const {
	return (this->i == other.i) && (this->r == other.r);
}
bool	Complex::operator!=(const Complex& other) const {
	return (this->i != other.i) || (this->r == other.r);
}

bool	Complex::operator==(double r) const {
	return (this->i == 0) && (this->r == r);
}
bool	Complex::operator!=(double r) const {
	return (this->i != 0) || (this->r == r);
}

bool	Complex::operator!() const { return !this->i && !this->r; }
Complex::operator bool() const { return this->i || this->r; }

std::ostream&	operator<<(std::ostream& cout, const Complex& n){
	if (!n)
		return cout << "0";

	if (n.r)
		cout << n.r;
	if (n.r && n.i)
		cout << ((n.i<0) ? " - " : " + ");
	if (n.i)
		cout << ((n.i<0 && n.r) ? -n.i : n.i) << " i";

	return cout;
}
