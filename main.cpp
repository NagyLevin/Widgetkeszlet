#include "graphics.hpp"
#include "math.h"
#include "fstream"
#include <iostream>

#include "box.hpp"



using namespace genv;
using namespace std;


const int XX = 900;
const int YY = 600;


int main()
{


    vector<Box *> w;

    Box *pb = new Box(100,100,20,20,255,0,0);
    Box *pb2 = new Box(150,150,20,20,0,255,0);



    w.push_back(pb);
    w.push_back(pb2);


    event ev;


    gout.open(XX,YY);

    gin.timer(30);

    while(gin >> ev && ev.keycode != key_escape){


    for(Box * pb : w){ //Playa, azza also resz kirajzol
        if(pb){
        pb->rajz();
        }

    }



    gout << refresh;
    }
    return 0;
}
