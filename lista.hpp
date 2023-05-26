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
int kijeloltelem;
int kirajzoltelemek =3;


public:

Lista(int x, int y, int sx, int sy , char r, char g , char b, vector<string> elemek);

virtual void rajz() override;
virtual void eventloop(event ev) override;

virtual int listaelem();

virtual string adjelemet();
virtual void hozzaadelem(string elem);

virtual vector<string> adjlistat();
virtual void listacsere(vector<string> lista);

virtual void elemcsere(string elem);

virtual int melyikelem();

virtual void torolelem();


};





#endif // LISTA_HPP
