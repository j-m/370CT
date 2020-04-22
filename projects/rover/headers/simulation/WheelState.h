#pragma once
enum WheelState {
  OK,
  BLOCKED_SMALL_OBSTACLE,
  BLOCKED_LARGE_OBSTACLE,
  FAILURE,
  FREEWHEELING,
  SUSPENDED,
  length
};

static const std::array<std::string, 6> WheelStateToString = {
  "OK",
  "BLOCKED_SMALL_OBSTACLE",
  "BLOCKED_LARGE_OBSTACLE",
  "FAILURE",
  "FREEWHEELING",
  "SUSPENDED"
};
