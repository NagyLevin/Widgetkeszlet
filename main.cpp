#include "graphics.hpp"
#include "math.h"
#include "fstream"
#include <iostream>
#include "textbox.hpp"
#include "box.hpp"



using namespace genv;
using namespace std;


const int XX = 900;
const int YY = 600;


int main()
{


    vector<Box *> w;

    Box *pb = new Box(100,100,120,120,255,0,0);
    Box *pb2 = new Box(150,150,120,120,0,255,0);
    TextBox *ptb = new TextBox(200,200,120,120,0,0,255,"tesztszoveg 0101");


    w.push_back(pb);
    w.push_back(pb2);
    w.push_back(ptb);


    event ev;


    gout.open(XX,YY);

    gin.timer(30);

    while(gin >> ev && ev.keycode != key_escape){
    if(ev.type == ev_timer || ev.type == ev_mouse){



        for(Box * pb : w){ //Playa, azza also resz kirajzol
        if(pb){
        pb->getXY(XX,YY);
        pb->rajz();
        pb->mozog();


        }

    }
    if( ev.type == ev_mouse) {
        for(Box * pb : w){ //Playa, azza also resz kirajzol
        if(pb){


        pb->eventloop(ev);
        pb->getMousePos(ev.pos_x,ev.pos_y);
        }
        }
    }



     gout << refresh;
     gout << move_to(0,0) << color(0,0,0) << box(XX,YY) << color(255,255,255);
    }







    }
    return 0;
}
