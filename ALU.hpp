
/***********************************************************************************************************************
*                                                                                                                      *
*   created by: MPZinke                                                                                                *
*   on 2022.11.04                                                                                                      *
*                                                                                                                      *
*   DESCRIPTION: TEMPLATE                                                                                              *
*   BUGS:                                                                                                              *
*   FUTURE:                                                                                                            *
*                                                                                                                      *
***********************************************************************************************************************/


#pragma once


#include "Port.hpp"
#include "Adder.hpp"


enum Flags  // The bit numbers of the flags
{
	CARRY,
	NEGATIVE,
	ZERO,
	OVERFLOW
};


class ALU
{
	public:
		ALU();

		Port<8> operator[](int index) const;  // Getter
		Port<8>& operator[](int index);  // Setter

	private:
		Port<8> _operand1;
		Port<8> _operand2;
		Port<8> _result;

		Port<4> _flags;
		Port<4> _instruction;

		void (ALU::*_instructions[1])() = {&ALU::_add};

		Adder _adder;


		void _add();
};
