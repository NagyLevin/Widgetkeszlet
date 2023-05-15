#include "textbox.hpp"
#include "box.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;

TextBox :: TextBox(int x, int y, int sx, int sy ,char r, char g , char b, string szoveg) : Box(x,y, sx, sy ,r,g , b), _szoveg(szoveg) { //csak egyszer fut le ertekadasok




}



void TextBox :: rajz(){



if(kijelolve == true){

      if(_szoveg.size()*10 <= _sx){
       gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);
     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(_szoveg);
    }
    if(_szoveg.size()*10 > _sx){
        string save = _szoveg.substr(_szoveg.size() - _sx/10 , _szoveg.size());

       gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);
     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(save);
    }


}
if(kijelolve == false){

        if(_szoveg.size()*10 <= _sx){
            gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
            gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
            gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(_szoveg);


        }
        if(_szoveg.size()*10 > _sx){
        string save = _szoveg.substr(_szoveg.size() - _sx/10 , _szoveg.size());

        gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
        gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
        gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(save);
        }



    }



}

void TextBox::setText(string text){

_szoveg = text;


}

