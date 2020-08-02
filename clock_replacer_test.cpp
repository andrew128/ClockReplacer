/*

*/
#include<iostream>
#include "clock_replacer.h"

int testBasic() {
  ClockReplacer clock_replacer(7);
  clock_replacer.AccessFrame(1);
  clock_replacer.AccessFrame(3);
  clock_replacer.AccessFrame(5);

  if (clock_replacer.Size() != 3) {
    return 1;
  }

  int victimized_frame_id;
  
  if (!clock_replacer.VictimizeFrame(&victimized_frame_id) 
      || victimized_frame_id != 1) {
    return 1;
  }

  if (!clock_replacer.VictimizeFrame(&victimized_frame_id) 
      || victimized_frame_id != 3) {
    return 1;
  }

  clock_replacer.AccessFrame(4);

  if (!clock_replacer.VictimizeFrame(&victimized_frame_id) 
      || victimized_frame_id != 5) {
    return 1;
  }

  if (!clock_replacer.VictimizeFrame(&victimized_frame_id) 
      || victimized_frame_id != 4) {
    return 1;
  }

  return 0;
}

int testWithPinning() {
  ClockReplacer clock_replacer(5);

  clock_replacer.AccessFrame(1);
  clock_replacer.AccessFrame(2);
  clock_replacer.AccessFrame(4);

  clock_replacer.Pin(2);

  int victimized_frame_id;

  if (!clock_replacer.VictimizeFrame(&victimized_frame_id) 
      || victimized_frame_id != 1) {
    return 1;
  }

  if (!clock_replacer.VictimizeFrame(&victimized_frame_id) 
      || victimized_frame_id != 4) {
    return 1;
  }

  clock_replacer.Unpin(2);

  if (!clock_replacer.VictimizeFrame(&victimized_frame_id) 
      || victimized_frame_id != 2) {
    return 1;
  }

  return 0;
}

int main() {
  std::cout << "Test Basic: " << 
    (testBasic() == 0 ? "Passed" : "Failed") << std::endl;
    
  std::cout << "Test With Pinning: " << 
    (testWithPinning() == 0 ? "Passed" : "Failed") << std::endl;
  return 0;
}