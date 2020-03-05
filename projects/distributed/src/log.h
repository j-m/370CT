#include <iostream>

template<typename MessageType>
void myLogDefinitelyNotUsedByOtherThings(MessageType message) {
  std::cout << message;
}
 
template<typename MessageType, typename ValueType, typename... ArgumentsType> 
void myLogDefinitelyNotUsedByOtherThings(MessageType message, ValueType value, ArgumentsType... arguments) {
  while (*message != '\0') {
    if (*message == '%') {
     myLogDefinitelyNotUsedByOtherThings(value);
     myLogDefinitelyNotUsedByOtherThings(message + 1, arguments...);
     return;
    }
    myLogDefinitelyNotUsedByOtherThings(*message);
    message++;
  }
}
