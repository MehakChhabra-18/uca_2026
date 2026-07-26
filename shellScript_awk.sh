#!/bin/bash

# task 1
cat data.txt | awk -F, '{print $1 " " $2}'

# task 2
awk -F, '$2=="Engineering"' data.txt

# task 3
awk -F, '{print $1 " gross pay: $" $3*$4}' data.txt

# task 4
awk -F, '{print NR "(" NF "fields):" $0}' data.txt

# task 5
awk -F, '
    BEGIN {
        total = 0
    }
    $2 == "Engineering" {
        total += $3 * $4
    }
    END {
        print "Total Engineering payroll: $" total
    }' data.txt
