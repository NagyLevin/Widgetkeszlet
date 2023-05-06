#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "graphics.hpp"
#include "box.hpp"
#include <iostream>

using namespace std;
using namespace genv;


class Number : public Box{
protected:
int _szam;
public:

Number(int x, int y, int sx, int sy , char r, char g , char b , int szam);

virtual void rajz() override;

};





#endif // NUMBER_HPP
