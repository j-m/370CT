#pragma once
enum SimulationFlag {
  BLOCKED_SMALL_OBSTACLE = 1,
  BLOCKED_LARGE_OBSTACLE = 2,
  FAILURE = 4,
  FREEWHEELING = 8,
  SINKING = 16
};
