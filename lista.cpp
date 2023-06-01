#include "lista.hpp"

#include "graphics.hpp"
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace genv;
using namespace std;

Lista:: Lista(int x, int y, int sx, int sy ,char r, char g , char b,vector<string> elemek) : Box(x,y, sx, sy ,r,g , b) ,_elemek(elemek) { //csak egyszer fut le ertekadasok

lenyitva = false;
kijeloltelem = 0;

if(kirajzoltelemek > _elemek.size()){
elemszam = _elemek.size()-1;

}
else{
elemszam = _elemek.size()-1;

}


}

void Lista::elemcsere(string elem){
_elemek[kijeloltelem] = elem;
}



int Lista::melyikelem(){
return kijeloltelem;
}

void Lista::listacsere(vector<string> lista){
_elemek = lista;
elemszam = lista.size()-1;
kijeloltelem = 0;
}
vector<string> Lista::adjlistat(){
return _elemek;
}



string Lista::adjelemet(){
return _elemek[kijeloltelem];
}

void Lista::torolelem(){

/*
if(_elemek.size() > 0 && elemszam > -1){
_elemek.pop_back();
elemszam = elemszam -1;
//cout << "ez" <<endl;
}
if(_elemek.size() == 0){
    _elemek[0] = "";
   // cout << "az" <<endl;
}
*/


if(_elemek.size()-1 == 0 && elemszam == 0){
    _elemek[kijeloltelem] = "";
    //cout << "az" <<endl;
}
//cout << _elemek.size()-1 << " es " <<elemszam <<endl;

if(_elemek.size()-1 > 0){
_elemek.erase(_elemek.begin()+kijeloltelem);
elemszam = elemszam -1;
kijeloltelem = 0;
//cout << "ez" <<endl;
}



//cout << _elemek.size() <<endl;








}

void Lista::hozzaadelem(string elem){


_elemek.push_back(elem);

elemszam = elemszam+1;

for(size_t i = 0; _elemek.size() > i;i++ )
if(_elemek[i] == ""){

    _elemek.erase(_elemek.begin()+i);
    elemszam = elemszam-1;
}


}



int Lista::listaelem(){
if(lenyitva){

    for(int i = 0; i < elemszam+1; i++){
    //gout << move_to(_x,_y) << color(200,0,0) << box(_x+_sx,_y+_sy +_sy*i);

    //cout << "Y " << _y+_sy*i <<endl;
    //cout << "ey " << ey <<endl;
    if(ex>_x && ex<_x+_sx && ey >_y+_sy*i && ey < _y+_sy +_sy*i){
        //cout << "siker " << i<<endl;
        if(i == kijeloltelem){ // cserebere, hogy ujra ki lehessen valasztani a 0. elemet
            return 0;
        }
        else{
               // cout << i <<endl;
            return i;
        }


    }

    }





    return -1;
}


}


void Lista::eventloop(event ev){


if (ev.type == ev_mouse && kivalasztva() && ev.button==btn_left) {
        lenyitva = !lenyitva;



}
/*
if (ev.type == ev_mouse && !kivalasztva() && ev.button==btn_left) {
        lenyitva = false;

}
*/
if (ev.type == ev_mouse &&  ev.button==btn_left && !kivalasztva() && lenyitva) {


if(listaelem() != -1){

kijeloltelem = listaelem();
//cout << kijeloltelem <<endl;


}

 lenyitva = false;
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



    if(_elemek[kijeloltelem].size()*10 <= _sx){

     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(_elemek[kijeloltelem]);
    }
    if(_elemek[kijeloltelem].size()*10 > _sx){
        string save = _elemek[kijeloltelem].substr(_elemek[kijeloltelem].size() - _sx/10 , _elemek[kijeloltelem].size());

     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(save);
    }
}

if(kijeloltelem == 0){


if(lenyitva == true){


    for(int i = 0; i < elemszam+1; i++){
        gout << move_to(_x,_y+i*_sy) << color(_r,_g,_b) <<box(_sx,_sy);
        gout << move_to(_x,_y+i*_sy) << color(_r-100,_g-100,_b-100) <<box(_sx,1);

    if(i > 0 && _y+(i+2)*_sy > _YY){ //ne logjon ki a lista az ablakbol //work in progress
        if(i > 0){
                gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text("...");

        }
        break;
    }
    else{




    if(_elemek[i].size()*10 <= _sx){


    gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text(_elemek[i]);



    }
    if(_elemek[i].size()*10 > _sx){
        string save = _elemek[i].substr(_elemek[i].size() - _sx/10 , _elemek[i].size());

        gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text(save);

    }


    }


    }
//


}
}



if(kijeloltelem != 0){ //cserebere azert hogy jol mutassa a kijeloltelemet


if(lenyitva == true){

    gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);



    if(_elemek[kijeloltelem].size()*10 <= _sx){

     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(_elemek[kijeloltelem]);
    }
    if(_elemek[kijeloltelem].size()*10 > _sx){
        string save = _elemek[kijeloltelem].substr(_elemek[kijeloltelem].size() - _sx/10 , _elemek[kijeloltelem].size());

     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(save);
    }



    for(int i = 1; i < elemszam+1; i++){
        gout << move_to(_x,_y+i*_sy) << color(_r,_g,_b) <<box(_sx,_sy);
        gout << move_to(_x,_y+i*_sy) << color(_r-100,_g-100,_b-100) <<box(_sx,1);

    if(i > 0 && _y+(i+2)*_sy > _YY){ //ne logjon ki a lista az ablakbol //work in progress
        if(i > 0){
                gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text("...");

        }
        break;
    }
    else{




    if(_elemek[i].size()*10 <= _sx){

    if(kijeloltelem == i){
        gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text(_elemek[0]);


    }
    else{
        gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text(_elemek[i]);

    }

    }
    if(_elemek[i].size()*10 > _sx){

        if(kijeloltelem == i){
        string save = _elemek[i].substr(_elemek[0].size() - _sx/10 , _elemek[0].size());

        gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text(save);
        }
        else{
        string save = _elemek[i].substr(_elemek[i].size() - _sx/10 , _elemek[i].size());

        gout << move_to(_x,_y +_sy/2 +i*_sy) << color(_r-100,_g-100,_b-100) << text(save);
        }

    }


    }


    }
//


}
}





























}
