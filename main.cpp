#include "graphics.hpp"
#include "math.h"
#include "fstream"
#include <iostream>
#include "textbox.hpp"
#include "box.hpp"
#include "textedit.hpp"


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
    Textedit *pte = new Textedit(250,250,120,120,0,0,255,"tesztszoveg 0202");


    w.push_back(pb);
    w.push_back(pb2);
    w.push_back(ptb);
    w.push_back(pte);


    event ev;


    gout.open(XX,YY);

    gin.timer(30);
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape){
    if(ev.type == ev_timer || ev.type == ev_mouse){



        for(Box * pb : w){
        if(pb){
        pb->getXY(XX,YY);
        pb->rajz();
        pb->mozog();

        //pte->

        }

    }
    if( ev.type == ev_mouse) {
        for(Box * pb : w){
        if(pb){


        //pb->eventloop(ev);
        pb->getMousePos(ev.pos_x,ev.pos_y);
        }
        }

         for (int i=0;i<w.size();i++) {


                if( ev.type == ev_mouse && ev.button==btn_left) {
                if(w[i]->kivalasztva() || w[i]->benne()) {
                        focus = i;
                }
                }

            }


    }
    //cout << focus <<endl;
    if (focus!=-1) {
           w[focus]->eventloop(ev);
    }




     gout << refresh;
     gout << move_to(0,0) << color(0,0,0) << box(XX,YY) << color(255,255,255);
    }







    }
    return 0;
}
