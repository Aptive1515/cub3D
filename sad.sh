#!/bin/bash
make all
valgrind \
--leak-check=full --show-leak-kinds=all --log-file=log \
./cub3D $1;
code log