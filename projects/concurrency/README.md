# Portfolio One - Concurrency

## Part One

- [x] Write a program that loads the a poem of your choice from the work of Ursula K le Guin link You should save it to a local text file first.
- [x] Each line of the poem should be stored as a separate string array in a vector. If you are using C syntax and not vectors this would be an array of chars.

## Part Two

- [ ] Create a thread to display these lines to screen. Each line should be displayed when a short (programmed) delay has transpired. I recommend one second, but this is not a requirement.
- [ ] Each line of the poem must only be displayed once. Failure to adhere to this requirement will reduce your grade.

### Part Two - Questions

Am I supposed you use a thread for each line read?

## Part Three

- [ ] Using Condition Variables, create a producer consumer program that transfers your poem one character at a time to the consumer.
- [ ] Display each line as it is built up character by character. You will need to introduce a delay into your program to do this properly.
- [ ] Add each completed line to the poem, and display the poem that you've collected so far.
- [ ] Once the entire poem has been transferred, state this and display the completed poem.

### Part Three - Questions

- Does character by character mean 1 buffer sized one, then?
- What output do you actually want displayed?
