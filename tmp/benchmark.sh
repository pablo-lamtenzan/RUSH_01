#!/usr/bin/env bash

# Abort on errors
set -e

SIZES=("128" "256" "512" "1024")
MYDIR="$(dirname "$(readlink -f "$0")")"

PATH="$PATH:$MYDIR"

for size in "${SIZES[@]}"; do
    genmap.pl "$size" > "$size".map
done

for size in "${SIZES[@]}"; do
    echo "$size:"
    time ./rush < "$size".map
done

for size in "${SIZES[@]}"; do
    rm -f "$size".map
done
