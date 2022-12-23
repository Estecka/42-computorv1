#!/bin/bash

echo -e "\n	# Bad Syntax" \
&& ! ./computor $@ "X = X^2 = 2" \
&& ! ./computor $@ boop \
&& ! ./computor $@ xBoop \
&& ! ./computor $@ "x + Boop" \
&& ! ./computor $@ "x * Boop" \
&& ! ./computor $@ xX \
&& ! ./computor $@ Xx \
&& ! ./computor $@ XX^2 \
&& ! ./computor $@ XX² \
&& ! ./computor $@ X⁴⁻³ \
&& ! ./computor $@ X⁴⁺ \
&& ! ./computor $@ X⁺ \
&& ! ./computor $@ X⁴⁻ \
&& ! ./computor $@ X⁻ \
;
