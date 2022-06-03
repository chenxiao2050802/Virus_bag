#!/usr/bin/bash
# -*- coding:utf-8 -*-

i=0
while True:
    file = open("temp"+i,'w+')
    for x in range(0,1000):
        file.write(str(x**x))
