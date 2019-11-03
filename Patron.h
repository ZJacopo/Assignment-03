// Patron.h

#ifndef PATRON_H
#define PATRON_H
#include <string>

using std::string;

class Patron{
	
	public:
	//constructor
	Patron(string user_name, int card_number, bool fee);
	//I think it can be intresting to create a default Patron for a new member, where you insert name and fee 
	//but the card_number is created via program
	
	//get fcts
	string get_user_name() const;
	int get_card_number() const;
	string get_complete_card() const;
	bool get_fee() const;
	
	//fcts that modifies parameters
	void set_name(string new_name);
	void set_card_number(int new_number);
	void set_fee(int new_fee);
	
	//this fct returns a new card_number
	string new_complete_card() const;
	string new_complete_card(int n) const;
	
	private:
	string user_name;
	int card_number; //this contains only the integer part
	string complete_card; //this contains the real code c-c-n-n-n-n
	bool fee;
	
};

	string new_number();
	string new_number(int n);
	
#endif
