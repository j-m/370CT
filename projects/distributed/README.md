# Portfolio Two - Distributed

## Part One - Cluster Status

- [ ] Write a program which collects data on the total data processing capabilities of the cluster, displayed on a node by node basis.  
This should include:
- [ ] Node Count (head node only)  
- [ ] Number and clock speed of cores, real or virtual.  
- [ ] This should be displayed both per node,and, through also sending the value to the head node for summing, a final cluster total.  
- [ ] System RAM of each node, listed by node name.  
These outputs may be printed to screen by each core on the nodes, depending on how your code is written. Try to avoid this.

## Part Two - Data Distribution

- [ ] Write a program using that loads a poem from Urula K Le-Guin into a vector. (You should already have some code you can use to help with this).  
Using a combination of OpenMP and MPI do the following:  
- [ ] Spilt this poem up between your nodes, keeping the original on the head node.
- [ ] The nodes should then mix up the words in each line they have (only within the lines, not words between lines, we can't make this problem intractable).
- [ ] Once the words have been jumbled up enough (as an example, move each word five times).
- [ ] Print them out to verify they really are jumbled.
- [ ] Pick two words randomly from each line, and send them to the head node (along with their original array index in the untouched poem) to check if they were originally adjacent.

## Part Three - Order Checking

- [ ] Checking for the correct order would involve lots of order swapping, which is a little wasteful, though you will need to do some swapping if you move up to three or more words.  
Your program should do this for each node until it gets at least one right answer.  
Whether you send these per line or collectively is up to you, so long as it happens.  
It's possible it won't, but unlikely, even if it might take a while.  
However, the grades in this case are more concerned with the functionality of your program, since grading solely on the chance you'll reconstruct a portion of a line is a little unfair.  
- [ ] If you feel up to it, and your program does prove successful, try sending three words to check for matches. This may start to get more difficult. Two may be hard enough.
- [ ] Four word matches seem less likely, closer to infinite monkey territory.

## Part Four - Distributed Arithmetic

- [ ] Write a program which passes an integer from one randomly picked node to another, altering it with some arithmetical operation on each node it reaches.  
Your program must achieve the following.  
- [ ] The destination node cannot be either the current node or the previous node.
- [ ] The arithmetical operation must not be the one which was performed previously.
