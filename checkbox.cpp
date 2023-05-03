#include "checkbox.hpp"
#include "box.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

CheckBox :: CheckBox(int x, int y, int sx, int sy ,char r, char g , char b) : Box(x,y, sx, sy ,r,g , b) { //csak egyszer fut le ertekadasok

beXelve = false;


}



void CheckBox :: rajz(){


if(kijelolve == false){
    //gout << move_to(_x,_y) << color(127+127*kijelolve,127+127*kijelolve,127+127*kijelolve) << box(_sx,_sy) << color(0,0,128) << move_to(_x+ablakszele,_y+ablakszele) << box(_sx+ablakszele/2,_sy+ablakszele/2);

    gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
    gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
    if(beXelve){
            gout << move_to(_x,_y) << color(_r*10,_g*10,_b*10) << line_to(_x+_sx,_y+_sy);
            gout << move_to(_x+_sx,_y) << color(_r*10,_g*10,_b*10) << line_to(_x,_y+_sy);

     }

}
if(kijelolve == true){
     gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);
     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     if(beXelve){
            gout << move_to(_x,_y) << color(_r*10,_g*10,_b*10) << line_to(_x+_sx,_y+_sy);
            gout << move_to(_x+_sx,_y) << color(_r*10,_g*10,_b*10) << line_to(_x,_y+_sy);

     }

    }


}



void CheckBox::eventloop(event ev)
{

if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            beXelve = !beXelve;
    }
if (ev.type == ev_mouse && kivalasztva() && ev.button==btn_left) {
        beXelve = !beXelve;
        //cout << "help" <<endl;
}


//mozgatas
if(ev.button == 1 && benne()) {

kijelol();
megfog();
//cout <<"talalt"<<endl;
}

if(ev.button == -1 || !benne()) {
    elenged();
    kijelolvege();
}
//mozgatas


}
