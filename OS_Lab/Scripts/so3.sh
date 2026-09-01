echo "Enter 3 no. : "
read a b c

l=$a
if [ $b -lt $l ] 
then
	l=$b
fi
if [ $c -lt $l ] 
then
	l=$c
fi
echo "smallest : $l"
