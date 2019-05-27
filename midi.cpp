#include "midi.h"

CMidiAudio::CMidiAudio()
{
  // RtMidiOut constructor
  try {
    midiout = new RtMidiOut();
  }
  catch ( RtError &error ) {
    error.printMessage();
    exit( EXIT_FAILURE );
  }

  // Call function to select port.
  try {
    if ( chooseMidiPort( midiout ) == false )
	{
		delete midiout;
	}
  }
  catch ( RtError &error ) {
    error.printMessage();
    delete midiout;
  }

  	message.push_back(0);
	message.push_back(0);
	message.push_back(0);

}

CMidiAudio::~CMidiAudio()
{
	delete midiout;
}

void CMidiAudio::sendMidiMessage(unsigned char status, unsigned char data1, unsigned char data2)
{
	message[0] = status;
	message[1] = data1;
	message[2] = data2;
	midiout->sendMessage( &message );
}

void CMidiAudio::pause(int ms)
{
	SLEEP(ms);
}

bool CMidiAudio::chooseMidiPort( RtMidiOut *rtmidi )
{
  std::string portName;
  unsigned int i = 0, nPorts = rtmidi->getPortCount();
  if ( nPorts == 0 ) {
    std::cout << "No output ports available!" << std::endl;
    return false;
  }

  if ( nPorts == 1 ) {
    std::cout << "\nOpening " << rtmidi->getPortName() << std::endl;
  }
  else {
    for ( i=0; i<nPorts; i++ ) {
      portName = rtmidi->getPortName(i);
      std::cout << "  Output port #" << i << ": " << portName << '\n';
    }

    do {
      std::cout << "\nChoose a port number: ";
      std::cin >> i;
    } while ( i >= nPorts );
  }

  std::cout << "\n";
  rtmidi->openPort( i );

  return true;
}