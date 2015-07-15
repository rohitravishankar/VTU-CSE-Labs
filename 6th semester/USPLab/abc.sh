#! /bin/bash
i=1
while [ $i -ne 100 ]
do
	./a.out>>temp
	i=`expr $i + 1`
done
