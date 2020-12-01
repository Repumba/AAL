#!/bin/bash
for i in $(seq 1 1 $1)
do
	./main.e < test$i.in > test$i.out
done
