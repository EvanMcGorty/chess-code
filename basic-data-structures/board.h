#include<vector>

#include"square.h"

template<typename t>
struct matrix
{
	
	matrix() = default;
	matrix(matrix const&) = default;
	matrix(matrix&&) = default;
	matrix& operator=(matrix const&) = default;
	matrix& operator=(matrix&&) = default;
	~matrix() = default;

	matrix(std::vector<std::vector<t>>&& a) :
		data(std::move(a))
	{}

	matrix(size_t height, size_t width, t const& initval = t{})
	{
		for(auto i = 0; i!=height; ++i)
		{
			data.emplace_back({})
			for(auto i = 0; i!=width; ++i)
			{
				data[i].emplace_back(initval);
			}
		}
	}

	std::vector<t>& row(size_t ind)
	{
		return data[ind];
	}

	std::vector<t> const& row(size_t ind) const
	{
		return data[ind];
	}

	std::vector<std::vector<t>> data;	
};

template<typename square_t>
class board
{
	
	board() :
		squares(8,8)
	{}


private:

	std::vector<std::vector<square_t>> squares;
};