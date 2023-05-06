#include "number.hpp"
#include "box.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

Number :: Number(int x, int y, int sx, int sy ,char r, char g , char b, int szam, int minimum, int maximum) : Box(x,y, sx, sy ,r,g , b), _szam(szam),_minimum(minimum),_maximum(maximum) { //csak egyszer fut le ertekadasok




}


void Number::eventloop(event ev){


if (ev.type == ev_mouse &&  ev.button==btn_left && kivalasztva() && ev.type == ev_key && ev.keycode == key_capsl) { //allitas 10x ertekkel
    plusz(10);
    minusz(10);


}
if (ev.type == ev_mouse &&  ev.button==btn_left && kivalasztva()) { //allitas kattintassal
    plusz(1);
    minusz(1);


}




if (ev.type == ev_mouse && ev.button==btn_wheelup && kivalasztva()) { //allitas gorgovel
    _szam = _szam+1;


}
if (ev.type == ev_mouse && ev.button==btn_wheeldown && kivalasztva()) { //allitas gorgovel
    _szam = _szam-1;


}


if(_szam > _maximum){
    _szam = _maximum;

}

if(_minimum > _szam){
    _szam = _minimum;

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


void Number::plusz(int mennyi){
if(ex>_x && ex<_x+_sx && ey>_y && ey<_y+_sy/5){
    _szam = _szam +mennyi;

}


}

void Number::minusz(int mennyi){

if(ex>_x && ex<_x+_sx && ey>_y+_sy -_sy/5 && ey<_y+_sy){
     _szam = _szam -mennyi;

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



