#include "graphics.hpp"
#include "math.h"
#include "fstream"
#include <iostream>
#include "textbox.hpp"
#include "box.hpp"
#include "textedit.hpp"
#include "checkbox.hpp"
#include "lista.hpp"

using namespace genv;
using namespace std;


const int XX = 900;
const int YY = 600;


int main()
{


    vector<Box *> w;

    Box *pb = new Box(100,100,120,120,255,0,0);
    Box *pb2 = new Box(250,100,120,120,0,255,0);
    TextBox *ptb = new TextBox(400,100,120,120,0,0,255,"tesz12");
    Textedit *pte = new Textedit(550,100,120,120,0,0,255,"tesztszoveg");
    Textedit *pte2 = new Textedit(700,100,120,120,30,30,115,"tesztszoveg2");
    CheckBox *pcb = new CheckBox(100,300,50,50,100,100,100);
    CheckBox *pcb2 = new CheckBox(200,300,50,50,100,200,100);


    vector<string> gyumolcsok = {"alma","banan","korte", "narancs"};
    Lista *pl = new Lista(400,300,150,50,100,200,100,gyumolcsok);

    vector<string> allatok = {"medve","roka"};
    Lista *pl2 = new Lista(600,300,150,50,50,200,100,allatok);

    w.push_back(pb);
    w.push_back(pb2);
    w.push_back(ptb);
    w.push_back(pte);
    w.push_back(pte2);
    w.push_back(pcb);
    w.push_back(pcb2);
    w.push_back(pl);
    w.push_back(pl2);


    event ev;


    gout.open(XX,YY);

    gin.timer(30);
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape){
    if(ev.type == ev_timer || ev.type == ev_mouse ||ev.type  == ev_key){



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
