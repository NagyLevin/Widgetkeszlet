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
int _maximum;
int _minimum;
int _korbeforog;

public:

Number(int x, int y, int sx, int sy , char r, char g , char b , int szam, int minimum, int maximum,int korbeforog);

virtual void rajz() override;
virtual void eventloop(event ev) override;

virtual void plusz(int mennyi);
virtual void minusz(int mennyi);

int adjszamot();


};





#endif // NUMBER_HPP
