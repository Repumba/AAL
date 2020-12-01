#!/bin/bash
for i in $(seq 1 1 $1)
do
	./gen.e $2 $3 > test$i.in
done
