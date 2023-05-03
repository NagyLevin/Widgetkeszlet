#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include "graphics.hpp"
#include "box.hpp"
#include <iostream>

using namespace std;
using namespace genv;


class CheckBox : public Box{
protected:

bool beXelve;

public:

CheckBox(int x, int y, int sx, int sy , char r, char g , char b );

virtual void rajz() override;
virtual void eventloop(event ev) override;

};





#endif // CHECKBOX_HPP
