# Building a Linux Memory Manager in C

This repository holds the implementation of the course's code
[Operating System Project - Develop Heap Memory Manager in C](https://www.udemy.com/course/os-project-lmm/)
from [Udemy](https://www.udemy.com/).

The aim of the course is to design and implement a scheme in the form of a _library_ that
takes the responsibility to allocate and de-allocate memory to the userspace process while
taking care of the problems of [heap](https://en.wikipedia.org/wiki/Memory_management#HEAP)
internal and external fragmentation behind the scenes.

In other words, it solves the problem of _heap_ internal and external fragmentation which
grows and magnifies over a period of time when a process is in execution and make much
of the part of _heap_ memory unusable.
