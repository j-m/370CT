#pragma once
enum RoverCommands {
  NONE,
  RAISE_WHEEL,
  LOWER_WHEEL,
  CHANGE_DIRECTION,
  CALL_FOR_HELP
};

static const std::array<std::string, 5> RoverCommandsToString = {
  "NONE",
  "RAISE_WHEEL",
  "LOWER_WHEEL",
  "CHANGE_DIRECTION",
  "CALL_FOR_HELP"
};
