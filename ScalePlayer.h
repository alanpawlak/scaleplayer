// Alan Jakub Pawlak - U1561875
// Assignment: Console Application – MIDI Scale Player
#include <vector>
#include "midi.h"
class ScalePlayer
{
public:
    ScalePlayer();
    int getScaleType();
    int getStartingNote();
    int getScaleAscDes();
    int getInstrUsed();
    int getRepeatTime();
    int getNoteLenght();

    void setScaleType(int ScaleType);
    void setStartingNote(int StartingNote);
    void setScaleAscDes(int ScaleAscDes);
    void setInstrUsed(int InstrUsed);
    void setRepeatTime(int RepeatTime);
    void setNoteLenght(int NoteLenght);
    void setScaleNotes();
    void startPlayback();


private:

    std::vector<int> m_ScaleNotes;
    int m_ScaleType;
    int m_NoteLenght;
    int m_RepeatTime;
    int m_StartingNote;
    int m_ScaleAscDes;
    int m_InstrUsed;

};