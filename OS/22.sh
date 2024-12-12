#!/bin/bash

# Prompt the user for the number of prime numbers to display
echo "Enter the number of prime numbers to display:"
read n

# Function to check if a number is prime
is_prime() {
    local num=$1
    if [ "$num" -le 1 ]; then
        return 1 # Not prime
    fi
    for ((i=2; i*i<=num; i++))
    do
        if [ $((num % i)) -eq 0 ]; then
            return 1 # Not prime
        fi
    done
    return 0 # Prime
}

# Generate the first n prime numbers
count=0
current=2
echo "The first $n prime numbers are:"
while [ $count -lt $n ]
do
    if is_prime $current; then
        echo $current
        ((count++))
    fi
    ((current++))
done

# Enter the number of prime numbers to display:
# 5
# The first 5 prime numbers are:
# 2
# 3
# 5
# 7
# 11