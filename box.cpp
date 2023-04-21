#include "box.hpp"

#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

Box :: Box(int x, int y, int sx, int sy ,char r, char g , char b) : _x(x), _y(y), _sx(sx), _sy(sy) ,_r(r),_g(g),_b(b) { //csak egyszer fut le ertekadasok



 kijelolve = false;
 fogva = false;



}

void Box::eventloop(event ev){






if(ev.button == 1 && benne()) {

kijelol();
megfog();
//cout <<"talalt"<<endl;
}

if(ev.button == -1 || !benne()) {
    elenged();
    kijelolvege();
}


}


void Box :: rajz(){



if(kijelolve == false){
    //gout << move_to(_x,_y) << color(127+127*kijelolve,127+127*kijelolve,127+127*kijelolve) << box(_sx,_sy) << color(0,0,128) << move_to(_x+ablakszele,_y+ablakszele) << box(_sx+ablakszele/2,_sy+ablakszele/2);

    gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
    gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
}
if(kijelolve == true){
     gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);
     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
    }

    //gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);
    //gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);



}

void Box::getXY(int xX, int yY) {
_XX = xX;
_YY = yY;


//me menjen ki az ablakbol
 if(_x-ablakszele/2 <0) _x = 0 +ablakszele/2;

 if(_x + _sx +ablakszele >= _XX) _x= _XX-1-_sx -ablakszele/2;

if(_y-ablakszele/2<0) _y=0+ablakszele/2;

if(_y+_sy+ablakszele>=_YY) _y=_YY-1-_sy-ablakszele/2;
//ne menjen ki az ablakbo

}

void Box::getMousePos(int mousex, int mousey){
ex = mousex;
ey = mousey;
//cout << ex << "     " <<ey <<endl;
}



bool Box :: benne(){
    if(!(ex  >= _x && ey >= _y && ex<=(_x+_sx) && ey <= (_y + _sy)) && (ex  >= _x-ablakszele/2 && ey >= _y-ablakszele/2 && ex<=(_x+_sx+ablakszele/2) && ey <= (_y + _sy+ablakszele/2))){
        //cout << "rajta" <<endl;
        return true;
       }


    else{

        return false;
    }
}




void Box:: megfog(){

if(fogva){
        fx = ex-_x; //ablak közepet fogom
        fy= ey-_y;
        if(_y<0) _y=0;
        if(_x<0) _x= 0;

}


}

void Box:: kijelol(){
kijelolve = true;
fogva = true;
}

void Box:: kijelolvege(){
kijelolve = false;
}
void Box:: elenged(){
fogva = false;



}

void Box:: mozog(){
if(fogva){


        _x=ex-fx; //ablak közepet fogom
        _y=ey-fy;
        //if(_y<0) _y=0;
        //if(_x<0) _x= 0;
        //if(_x+_sx >= _XX) _x=_XX-1-_sx;
        //if(_y+_sy >= _YY) _y=_YY-1-_sy;
}
}

