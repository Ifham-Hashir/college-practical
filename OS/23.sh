#!/bin/bash

# Prompt the user to enter numbers
echo "Enter numbers separated by spaces:"
read -a numbers

# Sort the numbers in descending order
sorted_numbers=$(echo "${numbers[@]}" | tr ' ' '\n' | sort -nr)

# Display the sorted numbers
echo "Numbers sorted in descending order:"
echo "$sorted_numbers"

# Enter numbers separated by spaces:
# 5 8 2 1 3
# Numbers sorted in descending order:
# 8
# 5
# 3
# 2
# 1