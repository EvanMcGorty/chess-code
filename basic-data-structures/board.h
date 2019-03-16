#include<vector>

#include"square.h"

#include"../assertions.h"

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
		generic_assert([](){return ((height!=0)&&(width!=0))||((height==0)&&(width==0));});
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

	size_t height()
	{
		return data.size();
	}

	size_t length()
	{
		generic_assert([&]()->bool
		{
			if(height()==0) {return false;}
			size_t f = data[0].size();
			for(auto it:data)
			{
				if(it.size()!=f) {return false;}
			}
			return true;
		});

		return data[0].size();
	}

	std::vector<std::vector<t>> data;
};

template<typename square_t>
class board
{
	
	board(std::vector<std::vector<square_t>> a = {8,8}) :
		squares(std::move(a))
	{
		generic_assert([](){return a.length()==8 && a.width()==8;});
	}


private:

	std::vector<std::vector<square_t>> squares;
};