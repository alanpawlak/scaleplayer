#include <iostream>
#include <cstdlib>
#include "RtMidi.h"

// Platform-dependent sleeps and includes.
#if defined(__WINDOWS_MM__)
  #include <windows.h>
  #pragma comment(lib, "winmm.lib")
  #define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants
  #include <unistd.h>
  #define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

#ifndef __PILCMIDIAUDIO
#define __PILCMIDIAUDIO

//class definitions
class CMidiAudio
{
public:
	CMidiAudio();
	~CMidiAudio();
	void sendMidiMessage(unsigned char status, unsigned char data1, unsigned char data2);
	bool chooseMidiPort( RtMidiOut *rtmidi );
	void pause(int ms);

private:	
	RtMidiOut *midiout;
    std::vector<unsigned char> message;
};

#endif