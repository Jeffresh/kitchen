#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include "list_d_enla.hpp"
#include <cassert>



struct Furniture
{
	float pos_;
	float len_;

	Furniture( float len = 0 , float pos = 0 ): pos_(pos), len_(len){}

};





class Kitchen
{

public:

	Kitchen(float lw): len_wall_{lw},wall{}{}
	void add(Furniture& F, float pos);
	bool fit(const Furniture&, float pos);
	Furniture ifurniture(std::size_t);
	void del_ifurniture(std::size_t);
	void move_to_ifurniture(std::size_t);
	~Kitchen(){wall.~Lista();}





private:

	float len_wall_;
	Lista<Furniture> wall;

};


bool Kitchen::fit(const Furniture& f, float pos)
{
	assert(pos+f.len_<len_wall_);

	bool fi = false;

	Lista<Furniture>::posicion p = wall.primera();

	while(p!=wall.fin() && wall.elemento(p).pos_ < pos+f.len_)
		p = wall.siguiente(p);


	if(p == wall.primera())
		fi = true;
	else if(wall.elemento(wall.anterior(p)).pos_+wall.elemento(wall.anterior(p)).len_ <= pos)
			fi = true;
	
	return fi;
}


void Kitchen::add(Furniture&f, float pos)
{
	Lista<Furniture>::posicion p = wall.primera();

	if(fit(f,pos))
	{
		while(wall.elemento(p).pos_ < pos)
			p= wall.siguiente(p);

		f.pos_ = pos;
		wall.insertar(f,p);



	}

}











#endif //KITCHEN_HPP