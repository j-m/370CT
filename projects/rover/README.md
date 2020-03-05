# Assignment

## Scenario

The Mars Curiosity Rover has been instructed to autonomously vector across a
flat region for two meters. It has to either deal with the problems it encounters
itself or ask for help from Earth.

## Task

The Mars Rover, being so distant, must be able to react autonomously to problems with its locomotion, such as obstacles or changes in the surface it is traversing (rocks, loose sand, holes etc).  

- [ ] Using a subsumption architecture implemented with Condition Variables, implement a wheel control system for six wheels that monitors the state of each wheel (blocked, freewheeling, sinking), and activates a sequence of events to counter that problem.
For Example:
– [ ] Stopping and choosing a new direction.
– [ ] Lift a wheel.
– [ ] Lower a wheel.

- [ ] You system must be able to differentiate between two levels of difficulty:-
– [ ] Rover can solve this problem itself.
– [ ] Rover needs to send a status update describing the problem and await instructions.
4.1 Sample Problems:
- [ ] A wheel encounters a rock to large to bump over.
- [ ] Loose sand causes a wheel to spin, making it loose track of how far it has
travelled.
- [ ] A wheel drops, indicating the presence of a hole or possibly a cliff edge.
- [ ] More than one wheel encounters a problem.
- [ ] The first attempt at an autonomous solution fails.
- [ ] Pick a solution, implement it, test if it worked, and if it did carry on.
- [ ] Testing will be via random number generation, so this is not required to
be a complex aspect of your solution. Since there is this random element,
your program can and will fail to find successful paths on it’s own.

## Requirements

- [ ] The program must run on the modules Linux server.
- [ ] You must submit a program that can be easily compiled and run without alteration.
- [ ] Submitting a non compiled source code file and expecting us to do any work figuring out how to compile it will mean your marks will go down. If we cannot compile it your marks will suffer, so include a compilation solution. If you don’t understand this, talk to a member of the module teaching team.
- [ ] If your program is not fully automatic, you need to include some form of easy to use, preferably menu based, problem selection method.
- [ ] A threaded menu system where problems can be selected for the Rover to encounter is good.
- [ ] Automatic problem selection would be preferred, the above option is presented should this not be possible.
- [ ] If the automatic problem selection is also threaded that would be even better.

Sample problems for your rover simulation to encounter:

- [ ] Single rock.
- [ ] Wheel/s sinking/freewheeling in loose sand.
- [ ] Wheel failure.

- [ ] Condition Variables must be used for passing control between threads within the subsumption architecture. Failure to use them will impact your marks significantly.
- [ ] The Rover must maintain a log of problems and the solutions it chose.
- [ ] This log to be recorded in a text file.

## Implementation

- [ ] You must use a Subsumption model for the wheel problem solving.
- [ ] This subsumption model must be threaded, and those threads must pass control between themselves via Condition Variables.
- [ ] Within the subsumption model portion of your code, no thread is allowed to do more than one task (for example raise a wheel).
Outside of that portion this restriction does not apply.
- [ ] If you have a thread that does more than one job, you need to make it clear where in the threading hierarchy it belongs if you don’t want to risk losing marks.

- [ ] Solutions as they are attempted, and the outcome of the attempt must be recorded in the log.
- [ ] A request for help from controllers on Earth can be considered a successful outcome, and recorded as such in the log.
- [ ] Success for the two meter vectoring task will be determined by vectoring the two meters or by not becoming stuck.
- [ ] During vectoring at least five problems must be encountered and dealt with so distance measuring can be determined by five problems occurring.
- [ ] Of these five problems I will expect it to resolve at least two itself, although not on every run. I will want to see this happening, therefore submitting a non functional program will impact your grade.

## Feedback

### Feedback 1

### Feedback 2

### Feedback 3

### Feedback 4
