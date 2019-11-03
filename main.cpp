#include "Patron.h"
#include <iostream>

using std::cout;

int main()
{
	Patron p1 = Patron("Jacopo_Zerbinato", 1528, true);//miuscole 
	Patron p2 = Patron("jacopo_zerbinato", 18, 45);//45--------non si accorge del 45
	Patron p3 = Patron("jacopo_zerbinato", 8, false);//tutto ok
	Patron p4 = Patron("jacopo_zerbinato", 8, true);//tutto ok
	//Patron("ja5opo_zerbinato", 988, true);//5
	//Patron("Jacopo_Zerbinato", 15258, false);//15258
	Patron p5 = Patron("---", 1528, false);//"" -> ora è rilevato
	//"---" -> è classificata come stringa valida, bisognerebbe vericficare che ci siano almeno due lettere
	
	
	cout<<"Ptron 1 name: "<<p1.get_user_name()<<"\n";
	cout<<"Ptron 1 number: "<<p1.get_card_number()<<"\n";
	cout<<"Ptron 1 complete: "<<p1.get_complete_card()<<"\n";/*
	cout<<"Ptron 2 number: "<<p2.get_card_number()<<"\n";
	cout<<"Ptron 3 complete: "<<p3.get_complete_card()<<"\n";
	cout<<" new_card Ja0000 "<<p1.new_complete_card()<<"\n";
	cout<<" new_card Ja001 "<<p1.new_complete_card()<<"\n";
	cout<<" new_card Ja02 "<<p1.new_complete_card()<<"\n";
	cout<<" new_card Ja3 "<<p1.new_complete_card()<<"\n";
	cout<<" new_card Ja4 "<<p1.new_complete_card()<<"\n";
	cout<<" new_card Ja5 "<<p1.new_complete_card()<<"\n";
	*/
	
	p1.set_name("Qwerty_uiop");
	cout<<"Patron 1 name "<<p1.get_user_name()<<"\n";
	cout<<"Ptron 1 complete: "<<p1.get_complete_card()<<"\n";
	
	p1.set_card_number(998);
	cout<<"Patron 1 number "<<p1.get_card_number()<<"\n";
	cout<<"Ptron 1 complete: "<<p1.get_complete_card()<<"\n";
}

