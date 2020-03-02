# Portfolio Two - Parallel

## Part One

Write a program which collects data on the total data processing capabilities of the machine.  
This should include:

- [ ] Total core count (real or virtual, either is good).  
- [ ] Clock speed of cores.  
- [ ] System Ram.  
- [ ] The size of your home folder.  

## Part Two

- [ ] Write a program capable of accepting its schedule type at runtime.  

It doesn't matter whether the program itself is going to be able to take full advantage of this variable schedule, only that it can be set, and at least one parallel region in your program makes use of it.

## Part Three

Using the program completed in step two (if you were unable to get it working, use what you have) to create a parallel application that solves the following problem:

- [ ] Given the ten vectors

```
  5  14  10
  7  -8 -14
 -2   9   8
 15  -6   3
 12   4  -5
  4  20  17
-16   5  -1
-11   3  16
  3  10 -19
-16   7   4
```

- [ ] Assume each is a position in a Cartesian co-ordinate system.  
- [ ] Further assume each vector represents an object moving by one step in a random direction in one of the three available directions per iteration, hence the omission of velocity vectors  
- [ ] Only one of the three values in a vector can be altered per step, being either incremented or decremented. It doesn't matter if you go into negative values, since it's moving in three dimensional space.
- [ ] In this way it's different from true movement, but that would be far harder.
- [ ] Now using your practice building a basic time series, iterate these vectors through ten steps.
- [ ] Your program should print the original state of these vectors, their state at five steps, then their state at the ten step point.

## Part Four

Once again, using the code from part three as a starting point.

- [ ] Work out, for each vector, which other in the set is closest (if there are two, pick one).
- [ ] Locate the centre for this set of particles (the point around which they are all grouped)
- [ ] For ten steps, move the vectors towards this point by either adding or subtracting one from an element of the current subject vector (the one being currently processed).
- [ ] Display the progress of the entire set at five, ten, then twenty steps.
- [ ] Print both the final distance between all the particles and this central point and their original distance from it.
