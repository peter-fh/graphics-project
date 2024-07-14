#!/bin/bash

cleanup() {
    rm part2.out
}


trap cleanup exit

g++ -o part2.out driver.cpp point.cpp triangle.cpp 
./part2.out
