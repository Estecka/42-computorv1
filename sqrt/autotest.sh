#!/bin/bash

make all \
&& ./sqrt.out 0 1 2 4 9 16 \
&& ./sqrt.out 10 100 100 1000 1e+5 1e+6 1e+7 1e+8 1e+9 1e+10 \
&& ./sqrt.out 2e+20 3e+30 9e+30 4e+40 \
&& ./sqrt.out 1e-1 2e-2 3e-3 4e-4 5e-5 6e-6 7e-7 8e-8 9e-9 10e-10 \
&& ./sqrt.out 2e-20 3e-30 4e-40 9e-40 5e-50 \
;