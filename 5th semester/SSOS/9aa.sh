#!/bin/bash
if [ $# -eq 0 ]
then
	echo "Usage Error"
exit
fi
for i in "$*"
do
echo "echo extracting $i file" >> f.sh
		cat $i >> f.sh
		echo "EOF" >> f.sh
done
cat f.sh
