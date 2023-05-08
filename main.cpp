#include "graphics.hpp"
#include "math.h"
#include "fstream"
#include <iostream>
#include "textbox.hpp"
#include "box.hpp"
#include "textedit.hpp"
#include "checkbox.hpp"
#include "lista.hpp"
#include "number.hpp"
#include "button.hpp"

using namespace genv;
using namespace std;


const int XX = 900;
const int YY = 600;


int main()
{


    vector<Box *> w;

    Box *pb = new Box(100,10,120,120,255,0,0);
    Box *pb2 = new Box(250,10,120,120,0,255,0);
    TextBox *ptb = new TextBox(400,10,120,120,0,0,255,"tesz12");
    Textedit *pte = new Textedit(550,10,120,120,0,0,255,"tesztszoveg");
    Textedit *pte2 = new Textedit(700,10,120,120,30,30,115,"tesztszoveg2");
    CheckBox *pcb = new CheckBox(100,200,50,50,100,100,100);
    CheckBox *pcb2 = new CheckBox(200,200,50,50,100,200,100);


    vector<string> gyumolcsok = {"alma","banan","korte", "narancs", "dinnye", "mangó", "repa", "citrom","ananasz"};
    Lista *pl = new Lista(400,200,150,50,100,200,100,gyumolcsok);

    vector<string> allatok = {"medve","roka"};
    Lista *pl2 = new Lista(600,200,150,50,50,200,100,allatok);


    Number *pn = new Number(100,300,120,120,0,0,255,97,0,100);
    Number *pn2 = new Number(300,300,120,120,20,40,80,5,-10,10);

    Button *pbu = new Button(500,300,75,75,0,100,100);
    Button *pbu2 = new Button(600,300,75,75,100,0,100);
    Button *pbu3 = new Button(700,300,75,75,100,50,10);


    w.push_back(pb);
    w.push_back(pb2);
    w.push_back(ptb);
    w.push_back(pte);
    w.push_back(pte2);
    w.push_back(pcb);
    w.push_back(pcb2);
    w.push_back(pl);
    w.push_back(pl2);
    w.push_back(pn);
    w.push_back(pn2);
    w.push_back(pbu);
    w.push_back(pbu2);
    w.push_back(pbu3);



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
        //egy ilyet csinalj majd tabbos korbejarashoz
         for (int i=0;i<w.size();i++) {


                if( ev.type == ev_mouse && ev.button==btn_left) {
                if(w[i]->kivalasztva() || w[i]->benne()) {
                        focus = i;
                }
                }

            }


    }
    //cout << focus <<endl;

    if (focus !=- 1) {
           w[focus]->eventloop(ev);


            /*
            //ha meg van nyomva a gomb, allitsuk at az elso szovegdoboz erteket, az elso textedit ertekere
           if(pbu->pressed()){
            //cout << "siker" <<endl;
            ptb->setText(pte->giveText());


           }
            //ha meg van nyomva a gomb, lista elso elemet beirom a textboxba
            if(pbu2->pressed()){
            //cout << "siker" <<endl;
            ptb->setText(pl->adjelemet());


           }

            if(pbu3->pressed()){
            //cout << "siker" <<endl;
            pl2->hozzaadelem(pte2->giveText());


           }
        */

    }








     gout << refresh;
     gout << move_to(0,0) << color(0,0,0) << box(XX,YY) << color(255,255,255);
    }







    }
    return 0;
}
