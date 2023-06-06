#pragma once

#ifndef FUNCTIONAL_H_
#define FUNCTIONAL_H_

// ôàéë ñ äîïîëíèòåëüíûìè ôóíêöèÿìè


#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Tourist.h"
#include "Room.h"

std::map<std::string, Tourist> tourists;
std::map<int, Room> rooms;

//1.Displaying information about tourist on the screen.
void show_tourists() {
	if (tourists.empty()) std::cout << "no information about tourists" << std::endl;
	else {
		for (auto p = tourists.cbegin(); p != tourists.cend(); p++) {
			std::cout << p->second << std::endl;
		}
	}
}

//2.Displaying information about rooms on the screen.
void show_rooms() {
	if (rooms.empty()) std::cout << "no information about rooms" << std::endl;
	else {
		for (auto p = rooms.cbegin(); p != rooms.cend(); p++) {
			std::cout << p->second << std::endl;
		}
	}
}

//3.Adding information about a new tourist.
void add_tourist() {
	std::cout << "enter information about the tourist" << std::endl;

	Tourist value;
	while (!(std::cin >> value)) {
		std::cout << "something went wrong, try typing again" << std::endl;
	}

	std::string key = value.get_lastname() + " " + value.get_firstname();
	tourists.insert(std::pair<std::string, Tourist>(key, value));
}

//4.Adding information about a new room.
void add_room() {
	std::cout << "enter the room information" << std::endl;

	Room value;
	while (!(std::cin >> value)) {
		std::cout << "something went wrong, try typing again" << std::endl;
	}

	int key = value.get_room_number();
	rooms.insert(std::pair<int, Room>(key, value)); // åñëè ýëåìåíò ñ òàêèì êëþ÷îì óæå ñóùåñòâóåò, òî âåðí¸òñÿ íà íåãî óêàçàòåëü
}

//5.Deleting information about a tourist by last name and first name entered from the keyboard.
void remote_tourist() {
	std::string lastname, firstname;
	std::cout << "lastname: ";
	getline(std::cin >> std::ws, lastname);

	std::cout << "firstname: ";
	getline(std::cin >> std::ws, firstname);

	std::string key = lastname + " " + firstname;
	if (!tourists.erase(key)) std::cout << "couldn't delete  information about tourist" << std::endl;
	else std::cout << "the information has been deleted" << std::endl;
}

//6.Deleting information about the room whose number is entered from the keyboard.
void remote_room() {
	int room_number;
	std::cout << "room number: ";
	std::cin >> room_number;

	int key = room_number;
	if (!rooms.erase(key)) std::cout << "couldn't delete  information about room" << std::endl;
	else std::cout << "the information has been deleted" << std::endl;
}

//7.Editing information about a tourist by last name and first name entered from the keyboard.
void edit_tourist() {
	std::string lastname, firstname;
	std::cout << "lastname: ";
	getline(std::cin >> std::ws, lastname);

	std::cout << "firstname: ";
	getline(std::cin >> std::ws, firstname);

	std::string key = lastname + " " + firstname;
	if (tourists.erase(key)) add_tourist();
	else std::cout << "it was not possible to edit the information, because the data about the tourist was not found" << std::endl;
}

//8.Editing information about the room whose number is entered from the keyboard.
void edit_room() {
	int room_number;
	std::cout << "room number: ";
	std::cin >> room_number;

	int key = room_number;
	if (rooms.erase(key)) add_room();
	else std::cout << "couldn't edit because the room doesn't exist" << std::endl;
}

//9.Creating a text file Tourist.txt containing information about tourists.
void write_tourist_file() {
	if (tourists.empty()) {
		std::cout << "there is no data to write to the file" << std::endl;
	}
	else {
		std::fstream of("./Turist.txt", std::fstream::out);
		if (of.is_open()) {
			for (auto p = tourists.cbegin(); p != tourists.cend(); p++)
				of << p->second << std::endl;
			std::cout << "information about tourists was recorded" << std::endl;
		}
		else std::cout << "could not open the file for writing" << std::endl;
	}
	
}

//10.Creating a Room.text file.a txt containing information about the rooms.
void write_room_file() {
	if (rooms.empty()) {
		std::cout << "there is no data to write to the file" << std::endl;
	}
	else {
		std::fstream of("./Room.txt", std::fstream::out);
			if (of.is_open()) {
				for (auto p = rooms.cbegin(); p != rooms.cend(); p++)
					of << p->second << std::endl;
				std::cout << "information about rooms was recorded" << std::endl;
			}
			else std::cout << "could not open the file for writing" << std::endl;
	}
	
}

//12.Displaying of the most expensive and cheapest room on the screen.
void show_price_room() {
	if (rooms.empty()) std::cout << "no information about rooms" << std::endl;
	else {
		std::vector<double> price;
		for (auto r = rooms.begin(); r != rooms.end(); r++)
				price.push_back(r->second.get_price());
			
		std::cout << "minimum price: " <<  *(std::min_element(price.begin(), price.end())) << std::endl;
		std::cout << "maximum price: " << *(std::max_element(price.begin(), price.end())) << std::endl;
	}
	
}
#endif // !FUNCTIONAL_H_
