# Assignment

## Scenario

The Mars Curiosity Rover has been instructed to autonomously vector across a
flat region for two meters. It has to either deal with the problems it encounters
itself or ask for help from Earth.

## Task

The Mars Rover, being so distant, must be able to react autonomously to problems with its locomotion, such as obstacles or changes in the surface it is traversing (rocks, loose sand, holes etc).  

- [x] Using a subsumption architecture implemented with Condition Variables, implement a wheel control system for six wheels that monitors the state of each wheel (blocked, freewheeling, sinking), and activates a sequence of events to counter that problem.
For Example:
– [x] Stopping and choosing a new direction.
– [x] Lift a wheel.
– [x] Lower a wheel.

- [x] You system must be able to differentiate between two levels of difficulty:-
– [x] Rover can solve this problem itself.
– [x] Rover needs to send a status update describing the problem and await instructions.
4.1 Sample Problems:
- [x] A wheel encounters a rock to large to bump over.
- [x] Loose sand causes a wheel to spin, making it loose track of how far it has
travelled.
- [x] A wheel drops, indicating the presence of a hole or possibly a cliff edge.
- [x] More than one wheel encounters a problem.
- [x] The first attempt at an autonomous solution fails.
- [x] Pick a solution, implement it, test if it worked, and if it did carry on.
- [x] Testing will be via random number generation, so this is not required to
be a complex aspect of your solution. Since there is this random element,
your program can and will fail to find successful paths on it’s own.

## Requirements

- [x] The program must run on the modules Linux server.
- [x] You must submit a program that can be easily compiled and run without alteration.
- [x] Submitting a non compiled source code file and expecting us to do any work figuring out how to compile it will mean your marks will go down. If we cannot compile it your marks will suffer, so include a compilation solution. If you don’t understand this, talk to a member of the module teaching team.
- [x] If your program is not fully automatic, you need to include some form of easy to use, preferably menu based, problem selection method.
- [x] A threaded menu system where problems can be selected for the Rover to encounter is good.
- [x] Automatic problem selection would be preferred, the above option is presented should this not be possible.
- [x] If the automatic problem selection is also threaded that would be even better.

Sample problems for your rover simulation to encounter:

- [x] Single rock.
- [x] Wheel/s sinking/freewheeling in loose sand.
- [x] Wheel failure.

- [x] Condition Variables must be used for passing control between threads within the subsumption architecture. Failure to use them will impact your marks significantly.
- [x] The Rover must maintain a log of problems and the solutions it chose.
- [x] This log to be recorded in a text file.

## Implementation

- [x] You must use a Subsumption model for the wheel problem solving.
- [x] This subsumption model must be threaded, and those threads must pass control between themselves via Condition Variables.
- [x] Within the subsumption model portion of your code, no thread is allowed to do more than one task (for example raise a wheel).
Outside of that portion this restriction does not apply.
- [x] If you have a thread that does more than one job, you need to make it clear where in the threading hierarchy it belongs if you don’t want to risk losing marks.

- [x] Solutions as they are attempted, and the outcome of the attempt must be recorded in the log.
- [x] A request for help from controllers on Earth can be considered a successful outcome, and recorded as such in the log.
- [x] Success for the two meter vectoring task will be determined by vectoring the two meters or by not becoming stuck.
- [x] During vectoring at least five problems must be encountered and dealt with so distance measuring can be determined by five problems occurring.
- [x] Of these five problems I will expect it to resolve at least two itself, although not on every run. I will want to see this happening, therefore submitting a non functional program will impact your grade.
