#ifndef BOX_HPP
#define BOX_HPP

#include "graphics.hpp"
using namespace genv;


class Box{
protected:
int _x;
int _y;
int _sx;
int _sy;
int ablakszele = 40;
int fx,fy;
int ex,ey;

bool kijelolve;
bool fogva;


int _XX;
int _YY;

char _r,_g,_b;

//box mozgatas es atmeretezes


virtual void kijelol();



virtual void megfog();

virtual void kijelolvege();

virtual void elenged();


//esemenyt csinalhatsz, amit a gomb megnyomasaval erhetsz el pl ping/show

//box mozgatas es atmeretezes


public:

Box(int x, int y, int sx, int sy , char r, char g , char b);

virtual void rajz();
virtual void eventloop(event ev);
virtual void getXY(int xX,int yY) ;
virtual void getMousePos(int mousex,int mousey);
virtual void mozog();
virtual bool kivalasztva();

virtual bool benne();

};





#endif // BOX_HPP
