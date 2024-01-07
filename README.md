# Overview

This program contains multiple sorting algorithms with a test harness.
The four sorting algorithms are:
-Insertion sort
-Batcher's odd even merge sort
-Heap sort
-Quick sort

## Using the program

To create the program you must first run the Makefile, you can do this by using the
commands; '$make', '$make all', or '$make sorting'. You can use '$make clean' to 
get rid of the extra files.

After you have created the executable, you can run it with ./sorting [-ahbiqr:n:p:H]
The following are the details for these command line options:
-a	        enables all sorting algorithms.
-h          enables heap sort.
-b          enables Batcher's odd even merge sort.
-i          enables insertion sort.
-q          enables quick sort.
-r seed     sets seed for random numbers.
-n length   sets length of random array.
-p print    sets the amount of items to print from the final sorted arrays.
-H          prints usage for the program

