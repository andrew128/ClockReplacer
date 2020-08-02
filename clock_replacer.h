#include <vector>

class ClockReplacer {
 public:
  ClockReplacer(int num_pages);

  virtual ~ClockReplacer() = default;

  // User accesses a frame, to either read from existing page at frame
  // or add a new page to that frame
  // Returns true if successfully accessed a frame
  bool AccessFrame(int frame_id);

  // Least recently used frame according to clock algorithm is removed
  bool VictimizeFrame(int *frame_id);

  // A frame is pinned, meaning it can't be victimized
  // Accessing a pinned frame won't have any affect because the frame 
  // is not in the clock replacer (clockRefFlag are false)
  void Pin(int frame_id);

  // Puts frame back into replacement consideration
  void Unpin(int frame_id);

  // Return number of frames currently in clock replacer
  int Size();

 private:
  int clockPointer;
  int numPages;
  int numFramesInClockReplacer;

  std::vector<bool> inClockReplacer;
  std::vector<bool> clockRefFlag;
  std::vector<bool> pinned;
};
