#include "kitchen.hpp"


int main()
{

	Kitchen k(10); Furniture a(2),b(3),c(1);

	k.add(a,4); k.add(b,0); k.add(c,9);

	std::cout<<k<<std::endl;

	k.del(3);

	std::cout<<k<<std::endl;

	k.add(c,9); k.move_ifurniture(3);

	std::cout<<k<<std::endl;

}