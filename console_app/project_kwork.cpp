#include "functional.h"

//+----------------------------------------------------------------------+
//+												                         +
//+	   [-] добавить валидацию даты (Tourist.сpp)                         +
//+	   [-] добавить проверку, существует ли комната (Tourist.сpp)        +
//+	   [-] по хорошему ещё избавиться от public гетов                    +
//+	   [-]                                                               +
//+	                                                                     +
//+----------------------------------------------------------------------+

int main() {
	setlocale(LC_ALL, "rus");
	std::cout << "Добро пожаловать!" << std::endl;

	std::cout << "1.Displaying information about tourist on the screen." << std::endl;
	std::cout << "2.Displaying information about rooms on the screen." << std::endl;
	std::cout << "3.Adding information about a new tourist." << std::endl;
	std::cout << "4.Adding information about a new room." << std::endl;
	std::cout << "5.Deleting information about a tourist by last name and first name entered from the keyboard." << std::endl;
	std::cout << "6.Deleting information about the room whose number is entered from the keyboard." << std::endl;
	std::cout << "7.Editing information about a tourist by last name and first name entered from the keyboard." << std::endl;
	std::cout << "8.Editing information about the room whose number is entered from the keyboard." << std::endl;
	std::cout << "9.Creating a text file Tourist.txt containing information about tourists." << std::endl;
	std::cout << "10.Creating a Room.text file.a txt containing information about the rooms." << std::endl;
	std::cout << "11.Displaying of the most expensive and cheapest room on the screen." << std::endl;
	std::cout << "12.Exit." << std::endl << std::endl;


	std::cout << "to perform an action, enter its number: ";
	int command = 0;
	while (std::cin >> command && command != 12) {
			switch (command) {
			case 1:
				show_tourists();
				break;
			case 2:
				show_rooms();
				break;
			case 3:
				add_tourist();
				break;
			case 4:
				add_room();
				break;
			case 5:
				remote_tourist();
				break;
			case 6:
				remote_room();
				break;
			case 7:
				edit_tourist();
				break;
			case 8:
				edit_room();
				break;
			case 9:
				write_tourist_file();
				break;
			case 10:
				write_room_file();
				break;
			case 11:
				show_price_room();
				break;
			default:
				std::cout << "Please enter the available command number from the list: ";
				break;
			}
			std::cout << std::endl << std::endl << "enter command number: ";
	}
	std::cout << "Bye!" << std::endl;
}
