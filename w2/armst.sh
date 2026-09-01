echo -n "Enter a number : "
read n
count=0
sum=0
temp=$n
while [ $temp -gt 0 ]
do
	temp=$((temp/10))
	count=$((count+1))
done
temp=$n
while [ $temp -gt 0 ] 
do
	rem=$((temp%10))
	pow=1
	for((i=1;i<=$count;i++))
do
	pow=$((pow*rem))
done
	sum=$((sum+pow))	
	temp=$((temp/10))	
done
if [ $sum -eq $n ]
then 
	echo "$n is a armstrong"
	exit 0
fi
echo "$n is not a armstrong"
