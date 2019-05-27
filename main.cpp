// Alan Jakub Pawlak - U1561875
// Assignment: Console Application – MIDI Scale Player
#include <iostream>
#include <fstream>
#include <string>
#include "ScalePlayer.h"

using namespace std;

int menuChose = 0;
int NoteLenght = 0;
int RepeatTime = 0;
int ReadOutput[6] = { 0, 0, 0, 0, 0, 0 };

string s_ScaleType;
string s_StartingNote;
string s_InstrUsed;
string s_ScaleAscDes;
string s_FileName;
string s_SaveInput;

void Header();
void InputScaleType();
void InputStartingNote();
void InputNoteLenght();
void InputInstrUsed();
void InputScaleAscDes();
void InputRepeatTime();
void InputSaveInput();
void ReadFileName();
void ReadInput();
void ReadPlayback();
void Footer();
void WrongChoice();

ifstream readdata;
ofstream savedata;

ScalePlayer ScalePlayerInput;

int main()
{
	Header();
    cin >> menuChose;
    if (menuChose == 1)
    {
		InputScaleType();
		InputStartingNote();
		InputNoteLenght();
		InputInstrUsed();
		InputScaleAscDes();
		InputRepeatTime();
		ScalePlayerInput.setScaleNotes();
		ScalePlayerInput.startPlayback();
		InputSaveInput();
		Footer();
		main();
    }
    else if (menuChose == 2)
    {
		ReadFileName();
		ReadInput();
		ReadPlayback();
		Footer();
		main();
    }
    else if (menuChose == 3)
    {
		Footer();
        return 0;
    }
    else
    {
		WrongChoice();
		main();
    }
}
void Header()
{
	cout << "Console Application  MIDI Scale Player" << endl;
	cout << "1. Enter new data and play scale " << endl;
	cout << "2. Load data from file and play scale" << endl;
	cout << "3. Quit the application" << endl;
}
void InputScaleType()
{
	do
	{
		cout << "Insert the scale type (chromatic, major or minor)." << endl;
		cin >> s_ScaleType;
		if (s_ScaleType == "chromatic")
		{
			ScalePlayerInput.setScaleType(1); // 1 = chromatic
		}
		else if (s_ScaleType == "major")
		{
			ScalePlayerInput.setScaleType(2); // 2 = major
		}
		else if (s_ScaleType == "minor")
		{
			ScalePlayerInput.setScaleType(3); // 3 = minor
		}
		else
		{
			WrongChoice();
		}
	} while (s_ScaleType != "chromatic" && s_ScaleType != "major" && s_ScaleType != "minor");
}
void InputStartingNote()
{
	do
	{
		cout << "Insert starting note of the scale [C, C#, D, D#, E, F, F#, G, G#, A, A#, B]" << endl;
		cin >> s_StartingNote;
		if (s_StartingNote == "C")
		{
			ScalePlayerInput.setStartingNote(60); 
		}
		else if (s_StartingNote == "C#")
		{
			ScalePlayerInput.setStartingNote(61); 
		}
		else if (s_StartingNote == "D")
		{
			ScalePlayerInput.setStartingNote(62); 
		}
		else if (s_StartingNote == "D#")
		{
			ScalePlayerInput.setStartingNote(63); 
		}
		else if (s_StartingNote == "E")
		{
			ScalePlayerInput.setStartingNote(64); 
		}
		else if (s_StartingNote == "F")
		{
			ScalePlayerInput.setStartingNote(65); 
		}
		else if (s_StartingNote == "F#")
		{
			ScalePlayerInput.setStartingNote(66); 
		}
		else if (s_StartingNote == "G")
		{
			ScalePlayerInput.setStartingNote(67); 
		}
		else if (s_StartingNote == "G#")
		{
			ScalePlayerInput.setStartingNote(68); 
		}
		else if (s_StartingNote == "A")
		{
			ScalePlayerInput.setStartingNote(69); 
		}
		else if (s_StartingNote == "A#")
		{
			ScalePlayerInput.setStartingNote(70); 
		}
		else if (s_StartingNote == "B")
		{
			ScalePlayerInput.setStartingNote(71); 
		}
		else
		{
			WrongChoice();
		}
	} while (s_StartingNote != "C" && s_StartingNote != "C#" && s_StartingNote != "D"  && s_StartingNote != "D#" && s_StartingNote != "E"&& s_StartingNote != "F" && s_StartingNote != "F#" && s_StartingNote != "G"&& s_StartingNote != "G#" && s_StartingNote != "A" && s_StartingNote != "A#" && s_StartingNote != "B");
}
void InputNoteLenght()
{
	do
	{
		cout << "Insert the length of each note (100 to 2000 milliseconds)" << endl;
		cin >> NoteLenght;
		if (NoteLenght >= 100 && NoteLenght <= 2000)
		{
			ScalePlayerInput.setNoteLenght(NoteLenght);
		}
		else
		{
			WrongChoice();
		}
	} while (NoteLenght < 100 || NoteLenght > 2000);
}
void InputInstrUsed()
{
	do
	{
		cout << "Select the instrument used to play the scale (either piano, trumpet, guitar or violin)" << endl;
		cin >> s_InstrUsed;
		if (s_InstrUsed == "piano")
		{
			ScalePlayerInput.setInstrUsed(0);
		}
		else if (s_InstrUsed == "trumpet")
		{
			ScalePlayerInput.setInstrUsed(56);
		}
		else if (s_InstrUsed == "guitar")
		{
			ScalePlayerInput.setInstrUsed(25);
		}
		else if (s_InstrUsed == "violin")
		{
			ScalePlayerInput.setInstrUsed(40);
		}
		else
		{
			WrongChoice();
		}
	} while (s_InstrUsed != "piano" && s_InstrUsed != "trumpet" && s_InstrUsed != "guitar" && s_InstrUsed != "violin");
}
void InputScaleAscDes()
{
	do
	{
		cout << "Insert whether the scale ascends or descends" << endl;
		cin >> s_ScaleAscDes;
		if (s_ScaleAscDes == "ascends")
		{
			ScalePlayerInput.setScaleAscDes(1);
		}
		else if (s_ScaleAscDes == "descends")
		{
			ScalePlayerInput.setScaleAscDes(0);
		}
		else
		{
			WrongChoice();
		}
	} while (s_ScaleAscDes != "ascends" && s_ScaleAscDes != "descends");
}
void InputRepeatTime()
{
	do
	{
		cout << "How many times the scale should be played (1 to 5)" << endl;
		cin >> RepeatTime;
		if (RepeatTime >= 1 && RepeatTime <= 5)
		{
			ScalePlayerInput.setRepeatTime(RepeatTime);
		}
		else
		{
			WrongChoice();
		}
	} while (RepeatTime < 1 || RepeatTime > 5);
}
void InputSaveInput()
{
	do
	{
		cout << "Would you like to save your input choices to a file for later playback? [y/n]" << endl;
		cin >> s_SaveInput;
		if (s_SaveInput == "y")
		{
			cout << "Enter file name" << endl;
			cin >> s_FileName;
			savedata.open(s_FileName);
			savedata << ScalePlayerInput.getStartingNote() << " " << ScalePlayerInput.getScaleType() << " " << ScalePlayerInput.getScaleAscDes() << " " << ScalePlayerInput.getRepeatTime() << " " << ScalePlayerInput.getNoteLenght() << " " << ScalePlayerInput.getInstrUsed();
			savedata.close();
		}
		else if (s_SaveInput == "n")
		{
			//Nothing
		}
		else
		{
			WrongChoice();
		}
	} while (s_SaveInput != "y" && s_SaveInput != "n");
}
void ReadFileName()
{
	cout << "Enter file name" << endl;
	cin >> s_FileName;
}
void ReadInput()
{
	readdata.open(s_FileName);
	if (readdata.is_open())
	{
		cout << "File opened." << endl;
		for (int i = 0; i <= 7; i++)
		{
			readdata >> ReadOutput[i];
		}
			ReadPlayback();
			ScalePlayerInput.setScaleNotes();
			ScalePlayerInput.startPlayback();
	}
	else
	{
		cout << "Loading... Error opening file." << endl;
	}
	readdata.close();
}
void ReadPlayback()
{
	ScalePlayerInput.setStartingNote(ReadOutput[0]);
	ScalePlayerInput.setScaleType(ReadOutput[1]);
	ScalePlayerInput.setScaleAscDes(ReadOutput[2]);
	ScalePlayerInput.setRepeatTime(ReadOutput[3]);
	ScalePlayerInput.setNoteLenght(ReadOutput[4]);
	ScalePlayerInput.setInstrUsed(ReadOutput[5]);
}
void Footer()
{
	cout << "Alan Jakub Pawlak - U1561875" << endl;
}
void WrongChoice()
{
	cout << "Wrong choice!!! Please try again." << endl;
	cin.clear();
	cin.ignore();
}