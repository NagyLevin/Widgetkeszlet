#ifndef LISTA_HPP
#define LISTA_HPP
#include "box.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;


class Lista : public Box{
protected:

vector<string> _elemek;



public:

Lista(int x, int y, int sx, int sy , char r, char g , char b, vector<string> elemek);


};





#endif // LISTA_HPP
