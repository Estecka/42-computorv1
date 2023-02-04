#!/bin/bash

echo -e "\n	# 2nd Degree" \
&& ./computor $@ "2x² + 3x²" \
&& ./computor $@ "2x²+ 4x +2" \
&& ./computor $@ "1x²+ 4x + 4" \
&& ./computor $@ "4x²+ 4x + 1" \
&& ./computor $@ "-4x²+ 3x + 1" \
&& ./computor $@ "-7x²+ -6x + 0.2" \
&& ./computor $@ "700x²+ -60x + 0.2156" \
;
