#pragma once
#include<exception>

using chess_code_generic_logic_error = std::logic_error;

template<typename callable>
void generic_assert(callable condition)
{
#ifndef NDEBUG
	if(!condition())
	{
		throw chess_code_generic_logic_error("generic chess-code logic error");
	}
#endif
}