#!/bin/bash

echo -e "\n	# 0th degree" \
&& ./computor $@ "0" \
&& ./computor $@ "0 = 0" \
&& ./computor $@ "42 = 42" \
&& ./computor $@ "-42.1 = 42.1" \
&& ./computor $@ "6 = 7" \
&& ./computor $@ "100 = -56" \
;
