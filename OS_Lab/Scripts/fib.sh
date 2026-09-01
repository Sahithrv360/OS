#!/bin/bash

echo "Enter number of terms:"
read n

a=0
b=1

for ((i=1;i<=n;i++))
do
    echo -n "$a "
    temp=$((a+b))
    a=$b
    b=$temp
done

echo