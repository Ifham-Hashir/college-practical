#!/bin/bash

# Prompt the user to enter a string
echo "Enter a string to check if it is a palindrome:"
read str

# Reverse the string
rev_str=$(echo "$str" | rev)

# Check if the original string matches the reversed string
if [ "$str" == "$rev_str" ]; then
    echo "The string '$str' is a palindrome."
else
    echo "The string '$str' is not a palindrome."
fi

# Enter a string to check if it is a palindrome:
# racecar
# The string 'racecar' is a palindrome.
