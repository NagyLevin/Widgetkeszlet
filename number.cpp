#include "number.hpp"
#include "box.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

Number :: Number(int x, int y, int sx, int sy ,char r, char g , char b, int szam) : Box(x,y, sx, sy ,r,g , b), _szam(szam) { //csak egyszer fut le ertekadasok




}


void Number::eventloop(event ev){



if (ev.type == ev_mouse &&  ev.button==btn_left && kivalasztva()) {
    plusz();
    minusz();


}






















if(ev.button == 1 && benne()) {

kijelol();
megfog();
}

if(ev.button == -1 || !benne()) {
    elenged();
    kijelolvege();
}


}


void Number::plusz(){
if(ex>_x && ex<_x+_sx && ey>_y && ey<_y+_sy/5){
    _szam = _szam +1;

}


}

void Number::minusz(){

if(ex>_x && ex<_x+_sx && ey>_y+_sy -_sy/5 && ey<_y+_sy){
     _szam = _szam -1;

}


}



void Number :: rajz(){

if(kijelolve){
        gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);

    }
    if(!kijelolve){
        gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
    }


    gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
    gout << move_to(_x,_y) << color(_r-100,_g-100,_b-100) <<box(_sx,_sy/5);
    gout << move_to(_x+_sx/2,_y+(_sy/5)/2) << color(_r+50,_g+50,_b+50) <<text("+");

    gout << move_to(_x,_y+_sy) << color(_r-100,_g-100,_b-100) <<box(_sx,-_sy/5);
    gout << move_to(_x+_sx/2,_y+_sy -(_sy/5)/2 ) << color(_r+50,_g+50,_b+50) <<text("-");


    gout << move_to(_x +_sx/2,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(to_string(_szam));



}



