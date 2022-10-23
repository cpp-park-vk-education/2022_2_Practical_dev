#!/bin/sh

cmake --build build/ --target full_test_COVERAGE -s | grep -E '\-{20,}.*' -A 100 >> foo.txt
cat foo.txt
grep -E 'TOTAL .*' foo.txt | python3 scripts/coverage_stat.py
rm foo.txt
