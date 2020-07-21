#!/bin/bash
DIR=$(pwd)
TIMESTAMP=$(date "+%Y%m%d-%H%M%S")

if [ ! -d "result" ] 
then
	echo -e "Result directory does not exist. Creating ...\n"
	mkdir result
else
	echo -e "Result directory exists\n\n"
fi
if [ ! -d "build" ] 
then
	echo -e "Build directory does not exist. Creating ...\n"
	mkdir build
else
	echo -e "Build directory exists\n"
fi

cd build

echo -e "Running cmake and make in $(pwd)\n"

SUCCESS=$(cmake .. && make)

if [[ $SUCCESS ]]
then
	echo -e "\nExecuting benchmarks\n"
	if [[ $1 != "-n" ]]
	then
		cat $DIR/resource/random_ints.txt | ./stdin_bm -t $DIR/result/$TIMESTAMP.csv
	else
		cat $DIR/resource/random_ints.txt | ./stdin_bm
	fi
else
	echo -e "\nBuild failed\n"
fi