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
bool lenyitva;
int elemszam;



public:

Lista(int x, int y, int sx, int sy , char r, char g , char b, vector<string> elemek);

virtual void rajz() override;
virtual void eventloop(event ev) override;



};





#endif // LISTA_HPP
