#include <vector>

class ClockReplacer {
 public:
   /**
   * Create a new ClockReplacer.
   * @param num_pages is the size of the ClockReplacer
   */
  ClockReplacer(int num_pages);

  virtual ~ClockReplacer() = default;

  /**
   * User accesses a frame, to either read from existing page at frame
   * or add a new page to that frame
   * @param int representing frame to be accessed
   * @return true if successfully accessed a frame
   */
  bool AccessFrame(int frame_id);

  /**
   * Least recently used frame according to clock algorithm is removed
   * @param pointer to int representing frame id removed
   * @return true if operation is successful
   */
  bool VictimizeFrame(int *frame_id);

  /**
   * A frame is pinned, meaning it can't be victimized.
   * Accessing a pinned frame won't have any affect because the frame 
   * is not in the clock replacer.
   * @param int representing frame to be pinned
   */
  void Pin(int frame_id);

  /**
   * Puts frame back into replacement consideration
   * @param int representing frame to be unpinned
   */
  void Unpin(int frame_id);

  /**
   * @return number of frames currently in clock replacer that are unpinned
   *         (which can be victimized)
   */
  int Size();

 private:
  int clockPointer;
  int numPages;
  int numFramesInClockReplacer;

  std::vector<bool> inClockReplacer;
  std::vector<bool> clockRefFlag;
  std::vector<bool> pinned;
};
