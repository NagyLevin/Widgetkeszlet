#include "textedit.hpp"
#include "graphics.hpp"
using namespace genv;

using std::string;



Textedit::Textedit(int x, int y, int sx, int sy ,char r, char g , char b, string szoveg) : TextBox(x,y,sx,sy,r,g,b,szoveg)
{
_irhato = false;
}


string Textedit::giveText(){
return _szoveg;
}


void Textedit::rajz()
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_sx, _sy);

    if(kijelolve){
        gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(255,255,255) <<box(_sx+ablakszele,_sy+ablakszele);

    }
    if(!kijelolve){
        gout << move_to(_x-ablakszele/2,_y-ablakszele/2) << color(127,127,172) <<box(_sx+ablakszele,_sy+ablakszele);
    }

    if(_irhato && _szoveg.size()*10 <= _sx){

     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(_szoveg+"|");
    }
    if(_irhato && _szoveg.size()*10 > _sx){
        string save = _szoveg.substr(_szoveg.size() - _sx/10 , _szoveg.size());

     gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
     gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(save + "|");
    }





    if(!_irhato && _szoveg.size()*10 <= _sx){

            gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
            gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(_szoveg);


        }
    if(!_irhato && _szoveg.size()*10 > _sx){
        string save = _szoveg.substr(_szoveg.size() - _sx/10 , _szoveg.size());


        gout << move_to(_x,_y) << color(_r,_g,_b) <<box(_sx,_sy);
        gout << move_to(_x,_y +_sy/2) << color(_r-100,_g-100,_b-100) << text(save);
        }













}
void Textedit::eventloop(event ev)
{





    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _irhato = !_irhato;
    }
    if (ev.type == ev_mouse && kivalasztva() && ev.button==btn_left) {
        _irhato = !_irhato;
        //cout << "help" <<endl;
    }







    if(_irhato){


        if(ev.type == ev_key){



        string text = ev.keyutf8;
        //cout << text <<endl;
        _szoveg = _szoveg + text;




        if(ev.keycode ==key_delete){
            _szoveg = "";
        }
        if(ev.keycode ==key_backspace){
            _szoveg =  _szoveg.substr(0, _szoveg.size()-1);
        }






        }





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


