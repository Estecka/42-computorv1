/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:56:34 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 14:06:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynomial.hpp"

extern inline float	PolyCompute(const Polynomial& poly, float x){
	return (poly[2]*x*x) + (poly[1]*x) + (poly[0]);
}

extern void	PolyCompute(const Polynomial& poly, const Complex& x, Complex outResult){
	outResult[0] = PolyCompute(poly, x[0]) - (poly[2]*x[1]*x[1]);
	outResult[1] = (2*poly[2]*x[1]*x[0]) + (poly[1]*x[1]);
}
