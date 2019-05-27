// Alan Jakub Pawlak - U1561875
// Assignment: Console Application – MIDI Scale Player
#include "ScalePlayer.h"
ScalePlayer::ScalePlayer()
{
    m_ScaleType = 0;
    m_StartingNote = 0;
    m_ScaleAscDes = 0;
    m_InstrUsed = 0;
    m_RepeatTime = 0;
    m_NoteLenght = 0;
}

void ScalePlayer::setScaleType(int ScaleType)
{
    m_ScaleType = ScaleType;
}
void ScalePlayer::setInstrUsed(int InstrUsed)
{
    m_InstrUsed = InstrUsed;
}
void ScalePlayer::setStartingNote(int StartingNote)
{
    m_StartingNote = StartingNote;
}
void ScalePlayer::setScaleAscDes(int ScaleAscDes)
{
    m_ScaleAscDes = ScaleAscDes;
}
void ScalePlayer::setRepeatTime(int RepeatTime)
{
    m_RepeatTime = RepeatTime;
}
void ScalePlayer::setNoteLenght(int NoteLenght)
{
    m_NoteLenght = NoteLenght;
}
int ScalePlayer::getScaleType()
{
    return m_ScaleType;
}
int ScalePlayer::getInstrUsed()
{
    return m_InstrUsed;
}
int ScalePlayer::getStartingNote()
{
    return m_StartingNote;
}
int ScalePlayer::getScaleAscDes()
{
    return m_ScaleAscDes;
}
int ScalePlayer::getRepeatTime()
{
    return m_RepeatTime;
}
int ScalePlayer::getNoteLenght()
{
    return m_NoteLenght;
}
void ScalePlayer::setScaleNotes()
{
	m_ScaleNotes.clear();
    if (m_ScaleType == 1) // CHROMATIC
    {
        m_ScaleNotes.push_back(m_StartingNote);
        for (int ScaleSize = 1; ScaleSize <= 12; ScaleSize++)
        {
            m_ScaleNotes.push_back(m_ScaleNotes[ScaleSize - 1] + 1);
        }
    }
    else if (m_ScaleType == 2) // MAJOR
    {
        m_ScaleNotes.push_back(m_StartingNote);
        for (int ScaleSize = 1; ScaleSize <= 7; ScaleSize++)
        {
            m_ScaleNotes.push_back(m_ScaleNotes[ScaleSize - 1] + 1);
            if (ScaleSize == 1 || ScaleSize == 2 || ScaleSize == 4 || ScaleSize == 5 || ScaleSize == 6)
            {
                m_ScaleNotes[ScaleSize] = m_ScaleNotes[ScaleSize] + 1;
            }
        }
    }
    else if (m_ScaleType == 3) // MINOR
    {
        m_ScaleNotes.push_back(m_StartingNote);
        for (int ScaleSize = 1; ScaleSize <= 7; ScaleSize++)
        {
            m_ScaleNotes.push_back(m_ScaleNotes[ScaleSize - 1] + 1);
            if (ScaleSize == 1 || ScaleSize == 3 || ScaleSize == 4 || ScaleSize == 6 || ScaleSize == 7)
            {
                m_ScaleNotes[ScaleSize] = m_ScaleNotes[ScaleSize] + 1;
            }
        }
    }
    if (m_ScaleAscDes == 0)
    {
        std::reverse(m_ScaleNotes.begin(), m_ScaleNotes.end());
    }
}
void ScalePlayer::startPlayback()
{
    CMidiAudio midi;
    midi.sendMidiMessage(0xC0, m_InstrUsed, 0x7f);
    for (int repeat = 0; repeat < m_RepeatTime; repeat++)
    {
        for (unsigned int note = 0; note < m_ScaleNotes.size(); note++)
        {
            midi.sendMidiMessage(0x90, m_ScaleNotes[note], 0x7f);
            midi.pause(m_NoteLenght);
            midi.sendMidiMessage(0x80, m_ScaleNotes[note], 0x7f);
        }
    }
}