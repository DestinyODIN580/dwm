#! /bin/bash

mr="$(awk '/^Mem/ {print $3}' <(free -h))" 
mt="$(awk '/^Mem/ {print $2}' <(free -h))"

echo "Mem: $mr/$mt"

