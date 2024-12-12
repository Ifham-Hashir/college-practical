#!/bin/bash

# Prompt the user for a number
echo "Enter a number to display its multiplication table:"
read number

# Loop through 1 to 10 to calculate and display the table
echo "Multiplication table for $number:"
for i in {1..10}
do
    result=$((number * i))
    echo "$number x $i = $result"
done

# Enter a number to display its multiplication table:
# 7
# Multiplication table for 7:
# 7 x 1 = 7
# 7 x 2 = 14
# 7 x 3 = 21
# 7 x 4 = 28
# 7 x 5 = 35
# 7 x 6 = 42
# 7 x 7 = 49
# 7 x 8 = 56
# 7 x 9 = 63
# 7 x 10 = 70