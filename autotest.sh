#!/bin/bash

cd $(dirname $(realpath "$0"));

make \
&& ./test/bad_syntax.sh $@ \
&& ./test/pretty_syntax.sh $@ \
&& echo -e "\n\t# OTHER" \
&& ./computor $@ "3x^2  +  2x + 1" \
&& ./computor $@ "1 + 2x + 3x^2" \
&& ./computor $@ "1 + 2x² + 3x²" \
&& ./computor $@ "0 + 2x² + 3x²" \
&& ./computor $@ "4*x*X^1 -   2 *3 * x^1   +   2 = 1x^2 - 15" \
&& ./computor $@ "4*X^2  +  3 * x^1  +  2 = 0" \
;
