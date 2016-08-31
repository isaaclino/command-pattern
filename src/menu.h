#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include "command.h"

using namespace std;

class Menu {
	private:
		signed int history_index;
		vector<Command*> history;

	public:
		//Base constructor to set up all necessary members
		Menu() {
			history_index = -1; 
		} 
			
		//Prints the current commands value (based on history_index)
			//if no commands exist print 0 by default
		void execute() { 
			if (history_index == -1) {
				cout << "0" << endl;
			}
			
			else {
				cout << history.at(history_index)->execute() << endl; 
			}
		}
			
		//Return true if the history has been primed with a single op instruction
			//This is necessary because that is the base of a calculation
		bool initialized() {
			if (history_index != -1) {
				return true;
			}
			return false;
		}
		
		//Adds a command to history in the appropriate positIon 
			//(based on history_index)
		void add_command(Command* cmd) {
			if (history_index == history.size() - 1 || history_index == -1) {
				history.push_back(cmd);
			}
			else {
				history.at(history_index + 1) = cmd;
				history.resize(history_index + 2);
			}
			++history_index;
		}
		
		//Returns the command in history we are currently referring to (based on history_index)
		Command* get_command() {
			if (history_index < 0) {
				cout << "history_index is less than 0"; 
			}
			return history.at(history_index);
		} 
		
		//Moves to the last command in history (if possible)
		void undo() {
			//cout << "after inside undo - index position: " << history_index << endl;
			if (history_index > 0) { //POSSIBLY TRY -1 INSTEAD OF 0
				--history_index;
				
			}
			//cout << "before inside undo - index position: "  << history_index << endl;
		}
		
		//Moves to the next command in history (if possible)
		void redo() {
			//cout << "after inside redo - index position: " << history_index << endl;
			if (history_index < history.size() - 1) {
				++history_index;
			}
			//cout << "after inside redo - index position: " << history_index << endl;
		} 
		
};

#endif //__MENU_CLASS__
