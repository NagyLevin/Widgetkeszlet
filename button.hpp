#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "graphics.hpp"
#include "Textbox.hpp"
#include <iostream>
#include<functional>

using namespace std;
using namespace genv;


class Button : public TextBox{
protected:

function<void()> _f;
bool megynyom;


public:

Button(int x, int y, int sx, int sy , char r, char g , char b ,string szoveg);

virtual void rajz() override;
virtual void eventloop(event ev) override;
virtual bool pressed();
string funkcio();


};





#endif // BUTTON_HPP
