#!/bin/bash

export LD_PRELOAD="$(pwd)/lib/libfoo.so"

gdb ./main/main
