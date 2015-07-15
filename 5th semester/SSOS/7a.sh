#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Empty argument list; Enter arguments"
	exit
fi

echo "Number of arguments = $#"
echo "Original: $*"

rev=" "

for i in $*
do
	rev=$i" "$rev
done

echo "Reversed: $rev"
