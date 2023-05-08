#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "graphics.hpp"
#include "CheckBox.hpp"
#include <iostream>
#include<functional>

using namespace std;
using namespace genv;


class Button : public CheckBox{
protected:

function<void()> _f;
bool megynyom;


public:

Button(int x, int y, int sx, int sy , char r, char g , char b );

virtual void rajz() override;
virtual void eventloop(event ev) override;
virtual bool pressed();



};





#endif // BUTTON_HPP
