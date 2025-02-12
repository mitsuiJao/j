#!/bin/bash

num1=$1
num2=$2
max=$num1

#less than
if [ "$num1" -lt "$num2" ]; then
	max=$num2
fi
