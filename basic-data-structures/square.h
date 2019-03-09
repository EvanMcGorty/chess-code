#pragma once

enum class piece
{
	none, pawn, knight, bishop, rook, queen, king
};

enum class color
{
	none, white, black
};

enum class state
{
	none, normal, can_castle, is_en_passant
}; 
//is_en_passant means that this pawn has just moved two squares the previous turn and could be taken by a pawn on its side



class square
{

	square(piece cp, color cc, state cs)
	{
		p = cp;
		c = cc;
		s = cs;
	}

	square() = delete;
	square(square const&) = default;
	square(square&&) = default;
	square& operator=(square const&) = default;
	square& operator=(square&&) = default;
	~square() = default;


	piece get_piece() const
	{
		return p;
	}

	void set_piece(piece n)
	{
		p = n;
	}


	color get_color() const
	{
		return c;
	}

	void set_color(color n)
	{
		c = n;
	}


	state get_state() const
	{
		return s;
	}

	void set_state(state n)
	{
		s = n;
	}




private:
	piece p;
	color c;
	state s;
};