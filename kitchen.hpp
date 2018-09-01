#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include "list_d_enla.hpp"
#include <cassert>
#include <iostream>



struct Furniture
{
	float pos_;
	float len_;

	Furniture( float len = 0 , float pos = 0 ): pos_(pos), len_(len){}

};

std::ostream& operator <<(std::ostream& os,  const Furniture& f)
{

	os<<"[.";


	for(int i = 1; i < (int)f.len_; i ++)
	{
		os<<"|.";
	}


	return os<<"]"	;
}








class Kitchen
{

public:

	Kitchen(float lw): len_wall_{lw},wall{}, n_furnitures{0}{}
	void add(Furniture& F, float pos);
	bool fit(const Furniture&, float pos);
	Furniture ifurniture(std::size_t)const;
	void del(std::size_t);
	void move_ifurniture(std::size_t);
	~Kitchen(){wall.~Lista();}


	friend std::ostream& operator <<(std::ostream& os,  const Kitchen& k);





private:

	float len_wall_;
	std::size_t n_furnitures;
	Lista<Furniture> wall;

};


bool Kitchen::fit(const Furniture& f, float pos)
{
	assert(pos+f.len_<=len_wall_);

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
		while(p!= wall.fin()&& wall.elemento(p).pos_ < pos)
			p= wall.siguiente(p);

		f.pos_ = pos;
		wall.insertar(f,p);


		n_furnitures++;



	}

}

void Kitchen::del(std::size_t pos)
{
	assert(pos<=n_furnitures);
	Lista<Furniture>::posicion p = wall.primera();

	for(int i = 1 ; i<pos; i++)
		p= wall.siguiente(p);


	wall.eliminar(p);

	n_furnitures--;
}

Furniture Kitchen::ifurniture(std::size_t pos)const
{
	assert(pos<= n_furnitures);

	Lista<Furniture>::posicion p = wall.primera();

	for(int i = 1 ; i<pos; i++)
		p= wall.siguiente(p);



	return wall.elemento(p);
}

void Kitchen::move_ifurniture(std::size_t pos)
{

	assert(pos <= n_furnitures);

	Lista<Furniture>::posicion p = wall.primera();

	for(int i = 1; i<pos; i++)
		p = wall.siguiente(p);


	if(p == wall.primera())
		wall.elemento(p).pos_=0;
	else
	{
		wall.elemento(p).pos_= wall.elemento(wall.anterior(p)).pos_+ wall.elemento(wall.anterior(p)).len_;
	}


}

std::ostream& operator <<(std::ostream& os,  const Kitchen& k)
{

	int points = 0;
	int blanks = 0;
	
	for(Lista<Furniture>::posicion p = k.wall.primera(); p != k.wall.fin(); p = k.wall.siguiente(p))
	{
		if(p == k.wall.primera())
			for(int i = 0 ; i< k.wall.elemento(p).pos_; i++ )
					os<<" _ ";
		else
		{

			points = (int)(k.wall.elemento(p).pos_ -(k.wall.elemento(k.wall.anterior(p)).pos_+ k.wall.elemento(k.wall.anterior(p)).len_));
			blanks = (int)k.len_wall_ - ((int)((k.wall.elemento(p).pos_ + (k.wall.elemento(p).len_))));
			if(points>1)
			{
				for(int i = 0; i<=points; i++)
					os<<" _ ";
			}
		}

		os<<k.wall.elemento(p);

	}

	if(blanks > 0)
		for(int i = 0; i<=blanks; i++)
					os<<" _ ";



	return os;
}














#endif //KITCHEN_HPP