echo -n "Enter a number : "
read num
n=$num
rem=1
bn=""
while [ $num -gt 0 ] 
do
	rem=$((num%5))
	bn=$rem$bn
	num=$((num/5))
	
done
echo "Binary of $n : $bn"
