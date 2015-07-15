#!/bin/bash
if [ $# -ne 2 ]
then
	echo "Insufficient arguments"
exit
fi

fp1=`ls -l $1 | cut -c 2-10`
fp2=`ls -l $2 | cut -c 2-10`
if [ $fp1 = $fp2 ]
then
	echo "Same file permissions"
else
echo "File permissions are different"
echo "File permission 1 = $fp1"
echo "File permission 2 = $fp2"
fi
