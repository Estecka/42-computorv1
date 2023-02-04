#!/bin/bash

echo -e "\n	# Pretty Parser" \
&& ./computor $@ "3.2x² + 2x¹ + 1.3x⁰" \
&& ./computor $@ "x⁹*x⁻⁷ + 3x⁻¹*x²" \
&& ./computor $@ "x⁹*x⁻⁷ + 3x⁻¹*x² = 0" \
&& ./computor $@ "0 = x⁹*x⁻⁷ + 3x⁻¹*x²" \
;
