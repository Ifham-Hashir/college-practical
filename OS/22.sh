#!/bin/bash

# Prompt the user for input
echo "Enter a number:"
read b

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

# Display prime numbers up to b
echo "Prime numbers up to $b are:"
for ((num=2; num<=b; num++))
do
    if is_prime $num; then
        echo "$num"
    fi
done

# Enter a number:
# 10
# Prime numbers up to 10 are:
# 2
# 3
# 5
# 7