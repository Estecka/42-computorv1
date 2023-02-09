/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:14:08 by abaur             #+#    #+#             */
/*   Updated: 2023/02/09 18:23:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SQRT_ITER_MAX	600

extern double	sqrt(double f){
	bool ok = 0;
	double root[2] = { (1 + f) * 0.5 };

	for (int i=0; i<SQRT_ITER_MAX; i++) {
		root[!ok] = (root[ok] + (f/root[ok])) * 0.5;
		if (root[!ok] >= root[ok])
			break;
		else
			ok = !ok;
	}

	return root[ok];
}
