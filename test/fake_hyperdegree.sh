#!/bin/bash

echo -e "\n	# Degree not really out of range" \
&& ./computor $@ "X^4 - X^4" \
&& ./computor $@ "2X^4 = 2X^4" \
&& ./computor $@ "X^3 * X^-1" \
&& ./computor $@ "X^6 * X^-1 = X^5" \
;
