#!/bin/bash

make \
&& ./computor $@ 0 0 0 \
&& ./computor $@ 0 0 1 \
&& ./computor $@ 0 1 1 \
&& ./computor $@ 1 1 1 \
&& ./computor $@ 4 3 2 \
&& ./computor $@ 3 2 1 \
&& ./computor $@ 2 1 0 \
&& ./computor $@ 1 2 3 \
&& ./computor $@ 0 1 2 \
;
