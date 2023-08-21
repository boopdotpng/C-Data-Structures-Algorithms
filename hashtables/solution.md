## hashtables 

A hashtable is a dictionary with keys and values corresponding to each key. 

### solution

First, we check if the strings are the same length. Otherwise, it can't be an anagram because there'd be unused letters. Then we create a map of each character and how many times it is encountered in the first string. Example:

for "abcc":

a: 1
b: 1
c: 2

This is what our map would look like. 

Then, if we have the string "abce" that we want to compare:
a: 1-1 = 0
b: 1-1 = 0
c 2-1 = 1

Since there are leftover elements in the map, the two strings cannot be anagrams.