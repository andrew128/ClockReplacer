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
  
  if (!clock_replacer.VictimizeFrame(&victimized_frame_id)) {
    return 1;
  }
  if (victimized_frame_id != 1) {
    return 1;
  }


  if (!clock_replacer.VictimizeFrame(&victimized_frame_id)) {
    return 1;
  }
  if (victimized_frame_id != 3) {
    return 1;
  }

  clock_replacer.AccessFrame(4);

  if (!clock_replacer.VictimizeFrame(&victimized_frame_id)) {
    return 1;
  }
  if (victimized_frame_id != 5) {
    return 1;
  }

  if (!clock_replacer.VictimizeFrame(&victimized_frame_id)) {
    return 1;
  }
  if (victimized_frame_id != 4) {
    return 1;
  }

  return 0;
}

int testWithPinning() {
  return 0;
}

int main() {
  std::cout << testBasic() << std::endl;
  return 0;
  // ClockReplacer clock_replacer(7);

//   // Scenario: unpin six elements, i.e. add them to the replacer.
//   clock_replacer.Unpin(1);
//   clock_replacer.Unpin(2);
//   clock_replacer.Unpin(3);
//   clock_replacer.Unpin(4);
//   clock_replacer.Unpin(5);
//   clock_replacer.Unpin(6);
//   clock_replacer.Unpin(1);

//////////// Add 6 pages to the replacer (mark as being used)

//   EXPECT_EQ(6, clock_replacer.Size());

//   // Scenario: get three victims from the clock.
//   int value;
//   clock_replacer.Victim(&value);
//   EXPECT_EQ(1, value);
//   clock_replacer.Victim(&value);
//   EXPECT_EQ(2, value);
//   clock_replacer.Victim(&value);
//   EXPECT_EQ(3, value);

//////////////// Victimize 3 pages

//   // LOG_INFO("clock replacer size: %zu", clock_replacer.Size());

//   // Scenario: pin elements in the replacer.
//   // Note that 3 has already been victimized, so pinning 3 should have no effect.
//   clock_replacer.Pin(3);
//   clock_replacer.Pin(4);
  
//   EXPECT_EQ(2, clock_replacer.Size());

//   // Scenario: unpin 4. We expect that the reference bit of 4 will be set to 1.
//   clock_replacer.Unpin(4);

//   // Scenario: continue looking for victims. We expect these victims.
//   clock_replacer.Victim(&value);
//   EXPECT_EQ(5, value);
//   clock_replacer.Victim(&value);
//   EXPECT_EQ(6, value);
//   clock_replacer.Victim(&value);
//   EXPECT_EQ(4, value);
}