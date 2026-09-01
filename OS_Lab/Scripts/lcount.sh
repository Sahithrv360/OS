#!/bin/bash

echo "Enter a string:"
read str

v=0
c=0
d=0

for ((i=0;i<${#str};i++))
do
    ch=${str:i:1}

    if [[ $ch =~ [AEIOUaeiou] ]]; then
        ((v++))
    elif [[ $ch =~ [A-Za-z] ]]; then
        ((c++))
    elif [[ $ch =~ [0-9] ]]; then
        ((d++))
    fi
done

echo "Vowels = $v"
echo "Consonants = $c"
echo "Digits = $d"