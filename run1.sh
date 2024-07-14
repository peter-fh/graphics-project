#!/bin/bash

cleanup() {
    rm part1.out
}

trap cleanup exit

g++ -o part1.out array.cpp
./part1.out
