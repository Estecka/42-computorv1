/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:56:34 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 15:25:56 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

extern inline float	PolyCompute(const Polynomial& poly, float x){
	return (poly[2]*x*x) + (poly[1]*x) + (poly[0]);
}

extern Complex	PolyCompute(const Polynomial& poly, const Complex& x){
	Complex result;
	result.r = PolyCompute(poly, x.r) - (poly[2]*x.i*x.i);
	result.i = (2*poly[2]*x.i*x.r) + (poly[1]*x.i);
	return result;
}
