#!/bin/bash

# Prompt the user for a number
echo "Enter a number to find its factorial:"
read n

# Initialize factorial to 1
factorial=1

# Calculate the factorial using a loop
for ((i=1; i<=n; i++))
do
    factorial=$((factorial * i))
done

# Display the result
echo "The factorial of $n is $factorial"

# Enter a number to find its factorial:
# 5
# The factorial of 5 is 120