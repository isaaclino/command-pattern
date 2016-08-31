#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"
//encapsulate the current state of calculation

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		
		//evaluates the composite tree that the command holds 
		double execute() {
			return root->evaluate();
		};
		
		//returns the commands tree so that it can be used as a subtree 
			//in another commands tree 
		Base* get_root() {
			return root;
		};
};


//each of which will have a single constructor that adds the proper new operator
//last command tree uses new operator, with last commands tree as one child and the newly input value as other

//OpCommand takes in a value and creates a single Op Composite Node 
class OpCommand : public Command {
	public: 
		OpCommand(int newInput){
			Op* A = new Op(newInput); 
			root = A; 
		}
		
};

class AddCommand : public Command {
	public:
		AddCommand(Command *n, int newInput) {
			Op* B = new Op(newInput); 
			Add* A = new Add(n->get_root(), B); 
			root = A;
		}

		
};

class SubCommand : public Command {
	public: 
		SubCommand(Command* n, int newInput) {
			Op* B = new Op(newInput); 
			Sub* A = new Sub(n->get_root(), B); 
			root = A; 
		}
};

class MultCommand : public Command {
	public: 
		MultCommand(Command* n, int newInput) {
			Op* B = new Op(newInput); 
			Mult* A = new Mult(n->get_root(), B); 
			root = A; //set root = A 
		}
};

//SqrCommand only takes in a subtree 
class SqrCommand : public Command { 
	public: 
		SqrCommand(Command *n) {
			Sqr* C = new Sqr(n->get_root());
			root = C; 
		};
};

#endif //__COMMAND_CLASS__
