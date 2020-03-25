#include "../Rover.h"


void Rover::sensorControl() {
  // Dead reckoning
  
  // Detect at destination 
  
  // Issues occur when
  // data - previousData != predictedData
  
  // Possible issues
  // Off course (angle) -> rectify -> call for help 
  // Off course (position) -> rectify -> call for help 
  // Freewheel (odometer too high) -> go around -> call for help
  // Blocked by obstacle. (odometer too low) -> go around -> if odometer is the same again then wheel is unresponsive -> call for help
  // Wheel cannot go forwards motor issue -> try again -> call for help
  // Wheel cannot go forwards power issue -> wait for charge -> call for help
  // Wheel cannot go backwards motor issue -> try again -> call for help
  // Wheel cannot go backwards power issue -> wait for charge -> call for help
  // Wheel cannot turn motor issue (unexpected SAS)-> try again -> call for help
  // Wheel cannot turn power issue -> wait for charge -> call for help
  // Power depleating too quickly 
}
