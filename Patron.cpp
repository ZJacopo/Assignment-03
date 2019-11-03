// Patron.cpp

#include "Patron.h"
#include <iostream>
#include <ostream>

using std::cout;
using std::cerr;
using std::to_string;//ma non penso serva

// this is global because is used in more fcts
const string abc{"abcdefghijklmnopqrstuvwxyz_-ABCDEFGHIJKLMNOPQRSTUVWXYZ"};


Patron::Patron(string new_user_name, int new_card_number, bool new_fee)
	:user_name{new_user_name}, card_number{new_card_number}, fee{new_fee} //complete_card{new_user_name.at(0)+new_user_name.at(1)+new_card_number}
	
	{	//validation
		//card_number must be a string of c-c-n-n-n-n where c = char, n = int
		//c-c are the first and second letter of the Patron name 
		//the integer part is created new for every new patron by a fct or it can be all inserted by set_card_number
		if(user_name.length() < 2){cerr<<"this name: "<<user_name<<" is too short, there must be an error \n"; exit(1);}
		else complete_card = user_name.substr(0,2) + to_string(new_card_number);
		
		string::size_type pos;
		pos = user_name.find_first_not_of(abc);
		if(pos != string::npos){cerr<<"there is an incorrect character in the string "<<user_name<<" \n"; exit(1);}
		
		if(card_number > 9999 || card_number < 0){cerr<<"this card_number "<<card_number<<" is out range \n"; exit(1);}
		
		if(fee < 0 || fee > 1){cerr<<"fee is a bool so "<<fee<<" is not contemplated \n"; exit(1);}
		
		
	}

//simple get fcts
string Patron::get_user_name() const
{return user_name;}

int Patron::get_card_number() const
{return card_number;}

string Patron::get_complete_card() const
{return complete_card;}

bool Patron::get_fee() const
{return fee;}


// apply this fct to a Patron to change its name
void Patron::set_name(string new_name) 
{
	if(new_name.length() < 2){cerr<<"this name: "<<user_name<<" is too short, there must be an error \n"; exit(1);}
	
	string::size_type pos;
	pos = new_name.find_first_not_of(abc);
	if(pos != string::npos){cerr<<"there is an incorrect character in the string "<<new_name<<" \n"; exit(1);}
		
	user_name = new_name;
	complete_card = user_name.substr(0,2) + to_string(card_number);
}

//apply this fct to a Patreon to change all its code with a new_number inserted by the operator
void Patron::set_card_number(int new_number)
{
	if(new_number > 9999 || new_number < 0){cerr<<"this card_number "<<new_number<<" is ot of range \n"; exit(1);}
	
	card_number = new_number;
	complete_card = user_name.substr(0,2) + to_string(new_number);
}

void Patron::set_fee(int new_fee)
{fee = new_fee;}

//apply this fct to a Patron to give him a new code by program and modifie in the same process all his caratteristics
string Patron::new_complete_card() const
{	
	string a = new_number();
	return user_name.substr(0,2) + a;
}

//apply this fct to a Patron to give him a new code by operator and modifie in the same process all his caratteristics 
string Patron::new_complete_card(int n) const
{
	string a = new_number(n);
	return user_name.substr(0,2) + a;
}

//this fct creates on p
string new_number()
{
	static int a{-1};
	a++;
	
	string a1 = to_string(a);
	
	if(a1.length() < 2){return "000"+a1;}
	else if(a1.length() < 3){return "00"+a1;}
		else if(a1.length() < 4){return "0"+a1;}
			else if(a1.length() < 5){return a1;}
				else {cerr<<"maximum value of card reached \n"; exit(1);}
	
}

string new_number(int new_value)
{
	string a1 = to_string(new_value);
	
	if(a1.length() < 2){return "000"+a1;}
	else if(a1.length() < 3){return "00"+a1;}
		else if(a1.length() < 4){return "0"+a1;}
			else if(a1.length() < 5){return a1;}
				else {cerr<<"maximum value of card reached \n"; exit(1);}
	
}






