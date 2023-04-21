#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include "graphics.hpp"
#include "box.hpp"
#include <iostream>

using namespace std;
using namespace genv;


class TextBox : public Box{
protected:
string _szoveg;
public:

TextBox(int x, int y, int sx, int sy , char r, char g , char b , string szoveg);

virtual void rajz() override;

};





#endif // TEXTBOX_HPP
