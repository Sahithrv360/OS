echo "Enter a Base-5 number:"
read num
dec=0
base=1
while [ $num -gt 0 ]
do
    rem=$((num % 10))
    dec=$((dec + rem * base))
    base=$((base * 5))
    num=$((num / 10))
done
echo "Decimal = $dec"