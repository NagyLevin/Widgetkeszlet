#ifndef BOXX_HPP
#define BOXX_HPP



struct Box{
private:
int _x;
int _y;
int _sx;
int _sy;

char _r,_g,_b;

public:

Box(int _x, int _y, int _sx, int _sy , char _r, char _g , char _b);

virtual void rajz();



};





#endif // BOX_HPP
