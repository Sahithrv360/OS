echo -n "Enter a number : "
read n
num=$n
rev=0	
while [ $num -gt 0 ] 
do
	rev=$((rev*10+num%10))
	num=$((num/10))
	
done
if [ $rev -eq $n ]
then 
	echo "$n is a palindrome"
	exit 0
fi
echo "$n is not a palindrome"
