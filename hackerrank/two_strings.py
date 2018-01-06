#!/bin/python

import sys

def twoStrings(s1, s2):
    s1 = set(list(s1))
    s2 = set(list(s2))

    result = None
    result = s1.intersection(s2)
    if result != set([]):
        return "YES"
    else:
        return "NO"
    
    

q = int(raw_input().strip())
for a0 in xrange(q):
    s1 = raw_input().strip()
    s2 = raw_input().strip()
    result = twoStrings(s1, s2)
    print(result)
