#!/bin/bash

make \
&& ./computor $@ "3x^2  +  2x + 1" \
&& ./computor $@ "4*X^2  +  3 * x^1  +  2 = 0" \
&& ./computor $@ "4*x*X^1 -   2 *3 * x^1   +   2 = 1x^2 - 15" \
;
