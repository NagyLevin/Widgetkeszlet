#ifndef TEXTEDIT_HPP_INCLUDED
#define TEXTEDIT_HPP_INCLUDED

#include "graphics.hpp"
#include "textbox.hpp"
using std::string;



class Textedit : public TextBox {
protected:
    bool _irhato;
    string saveszoveg = "";
public:
    Textedit(int x, int y, int sx, int sy ,char r, char g , char b, string szoveg);
    virtual void rajz() override;
    virtual void eventloop(genv::event ev) override;

};


#endif // TEXTEDIT_HPP_INCLUDED
