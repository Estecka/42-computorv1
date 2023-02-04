#!/bin/bash

cd $(dirname $(realpath "$0"));

make \
&& ./test/bad_syntax.sh -r $@ \
&& ./test/hyperdegree.sh -r $@ \
&& ./test/fake_hyperdegree.sh -r $@ \
&& ./test/pretty_syntax.sh -r $@ \
&& ./test/no_solution.sh $@ \
&& ./test/0th_degree.sh $@ \
&& ./test/1st_degree.sh $@ \
&& ./test/2nd_degree.sh $@ \
|| echo "Test failed" \
;
