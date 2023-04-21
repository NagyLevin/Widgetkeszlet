#ifndef BOXX_HPP
#define BOXX_HPP

#include "graphics.hpp"
using namespace genv;


struct Box{
private:
int _x;
int _y;
int _sx;
int _sy;
int ablakszele = 20;
int fx,fy;
int ex,ey;

bool kijelolve;
bool fogva;


int _XX;
int _YY;

char _r,_g,_b;

//box mozgatas es atmeretezes


virtual void kijelol();


virtual bool benne();

virtual void megfog();

virtual void kijelolvege();

virtual void elenged();



//box mozgatas es atmeretezes


public:

Box(int _x, int _y, int _sx, int _sy , char _r, char _g , char _b);

virtual void rajz();
virtual void eventloop(event ev);
virtual void getXY(int xX,int yY);
virtual void getMousePos(int mousex,int mousey);
virtual void mozog();


};





#endif // BOX_HPP
