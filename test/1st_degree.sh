#!/bin/bash

echo -e "\n	# 1st Degree" \
&& ./computor $@ "2x + 1" \
&& ./computor $@ "3x - 5" \
&& ./computor $@ "5.5x + 2 = -15.666" \
&& ./computor $@ "7.2x + 2 = 0" \
;
