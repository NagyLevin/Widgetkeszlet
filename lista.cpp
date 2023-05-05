#include "lista.hpp"

#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

Lista:: Lista(int x, int y, int sx, int sy ,char r, char g , char b,vector<string> elemek) : Box(x,y, sx, sy ,r,g , b) ,_elemek(elemek) { //csak egyszer fut le ertekadasok

lenyitva = true;
kijeloltelem = -1;

if( 3 > _elemek.size()){
elemszam = _elemek.size()-1;

}
else{
elemszam = 3;

}


}


int Lista::listaelem(){
if(lenyitva){

    for(int i = 0; i < elemszam+1; i++){
    ex>_x && ex<_x+_sx && ey>_y+_sy*i && ey<_y+_sy+_sy*i;
    cout << "siker" <<endl;
    return i;
    }
    return -1;
}


}


void Lista::eventloop(event ev){


if (ev.type == ev_mouse && kivalasztva() && ev.button==btn_left) {
        lenyitva = !lenyitva;

}
if (ev.type == ev_mouse && !kivalasztva() && ev.button==btn_left) {
        lenyitva = false;

}

if (ev.type == ev_mouse && listaelem() != -1 && ev.button==btn_left) {



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

void Lista ::rajz(){

if(kijelolve){
        gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);

    }
    if(!kijelolve){
        gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
    }
if(lenyitva == false){
    gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);



    if(_elemek[0].size()*10 <= _sx){

     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(_elemek[0]);
    }
    if(_elemek[0].size()*10 > _sx){
        string save = _elemek[0].substr(_elemek[0].size() - _sx/10 , _elemek[0].size());

     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(save);
    }
}
if(lenyitva == true){


    for(int i = 0; i < elemszam+1; i++){
        gout << move_to(_x,_y+i*_sy) << color(_r,_g,_b) <<box(_sx,_sy);
        gout << move_to(_x,_y+i*_sy) << color(_r-100,_g-100,_b-100) <<box(_sx,1);


        gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text(_elemek[i]);

    }





}



}
