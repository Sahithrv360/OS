echo -n "Enter a number : "
read num
n=$num
rem=1
bn=""
while [ $num -gt 0 ] 
do
	rem=$((num%2))
	bn=$rem$bn
	num=$((num/2))
	
done
echo "Binary of $n : $bn"
