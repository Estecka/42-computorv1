#!/bin/bash

echo -e "\n	# No Solution" \
&& ./computor $@ "3.46x^2 + 2x + 1" \
&& ./computor $@ "1 + 2x² + 3x²" \
&& ./computor $@ "4*x*X^1 -   2 *3 * x^1   +   2 = 1x^2 - 15" \
&& ./computor $@ "4*X^2  +  3 * x^1  +  2 = 0" \
;
