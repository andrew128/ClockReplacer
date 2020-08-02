// #include<iostream>
#include "clock_replacer.h"

ClockReplacer::ClockReplacer(int num_pages) {
  clockPointer = 0;
  numPages = num_pages;
  numFramesInClockReplacer = 0;

  inClockReplacer.resize(num_pages);
  pinned.resize(num_pages);
  clockRefFlag.resize(num_pages);
}

bool ClockReplacer::AccessFrame(int frame_id) {
  if (frame_id < 0 || frame_id >= numPages || pinned[frame_id]) return false;

  inClockReplacer[frame_id] = true; // called even if frame already in clock replacer
  clockRefFlag[frame_id] = true;
  numFramesInClockReplacer++;
  return true;
}

bool ClockReplacer::VictimizeFrame(int *frame_id) {
  while (numFramesInClockReplacer != 0) {
    if (inClockReplacer[clockPointer] && !pinned[clockPointer]) {
      if (clockRefFlag[clockPointer]) {
        clockRefFlag[clockPointer] = false;
      } else {
        *frame_id = clockPointer;
        inClockReplacer[clockPointer] = false;
        numFramesInClockReplacer--;
        return true;
      }
    }
    clockPointer = (clockPointer + 1) % numPages;
  }

  return false;
}

void ClockReplacer::Pin(int frame_id) {
  if (frame_id < 0 || frame_id >= numPages || !inClockReplacer[frame_id]) 
    return; 

  pinned[frame_id] = true;
  numFramesInClockReplacer--;
}

void ClockReplacer::Unpin(int frame_id) {
  if (frame_id < 0 || frame_id >= numPages || !inClockReplacer[frame_id]) 
    return; 

  pinned[frame_id] = false;
  numFramesInClockReplacer++;
}

int ClockReplacer::Size() {
  return numFramesInClockReplacer;
}