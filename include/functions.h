#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "KenoBet.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include <random>

using String=std::vector<std::string>;

namespace fc{
	/*!Open the file and adds data to variable data.
		@param dest the name of the file open.
		@param data Vector to string to save the file data.
		@return 0 if the file is read; -1 if the file is not found.*/
	int open_file(const char *dest, String &data);

	/*!Read the bet made by the user.
		@param data The vector to string with the file data.
		@param keno Class KenoBet.*/
	void read_bet(String &data,KenoBet &keno);

	/*!Read vector with table and print on screen.
		@param tabela Vector with table.
		@return Vector with table data. */
	std::vector<float> print_table(std::string tabela);

	/*Chooses 20 different random numbers between 1 and 80.
		@return The vector short int with the chosen numbers. */
	set_of_numbers_type Hits();

	/*!Organize the vector in ascending order.
		@param first Iterator to beginnig.
		@param end Iterator to end. */
	void sort(set_of_numbers_type::iterator first,set_of_numbers_type::iterator last);
	/*!Print the vector.
		@param nums Vector a ser impresso. */
	void print(set_of_numbers_type nums);
}

#endif