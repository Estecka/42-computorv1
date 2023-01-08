#!/bin/bash

echo -e "\n	# Degree out of range" \
&& ! ./computor $@ "X^3" \
&& ! ./computor $@ "X³" \
&& ! ./computor $@ "X^-1" \
&& ! ./computor $@ "X⁻¹" \
&& ! ./computor $@ "X² = X^4" \
;
