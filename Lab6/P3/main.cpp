#include <iostream>
#include <chrono>
#include "functii.h"
#include "CImg.h"

using namespace std;
using namespace cimg_library;
using namespace std::chrono;


Pozitie directii[4] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

CImg<unsigned char> ColoreazaDomeniu(CImg<unsigned char>& in, Pozitie init, unsigned char color, CImgDisplay& dispOut) {
    CImg<unsigned char> imgOut = in; // imgOut este o copie a lui in

    //dimensiunile imaginii
    int width = in.width();
    int height = in.height();

    unsigned char culoareDomeniu = in(init.x, init.y); // obtinem valoarea pixelului de la pozitia initiala
    cout << "Color: " << (unsigned int)culoareDomeniu << "( " << init.x << ", " << init.y << ")" << endl;

    //... adaugati logica aplicatiei aici
    //pun intr o matrice codul pixelilor
    unsigned char a[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            a[i][j]=in(j,i);
        }
    }
    //algoritmul lui lee
    queue q=initq();
    put(q,init);
    imgOut(init.x,init.y)=color;
    while(!isEmpty(q))
    {
        int i=front(q).x;//linie
        int j=front(q).y;//coloana
        for(int k=0;k<4;k++)
        {
            int iv=i+directii[k].x;//linie vecin
            int jv=j+directii[k].y;//coloana vecin
            if(iv>=0 && iv< width && jv>=0 && jv<height)
            {
                if(a[jv][iv]==culoareDomeniu && imgOut(iv,jv)!=color)
                {
                    imgOut(iv,jv)=color;
                    put(q,{jv,iv});
                    dispOut.display(imgOut);
                    sleep(0.1);
                }
            }
            
        }
        get(q);
    }

    
    cout << "DONE!" << endl;
    return imgOut;
}

int main() {
    CImg<unsigned char> imgIn(200,200,1,1,255);

    unsigned char alb[]={0};
    unsigned char negru[]={255};
    imgIn.draw_rectangle(50,50,150,150,alb);

    imgIn.draw_rectangle(80,80,120,120,negru);

    // Creati o fereastra pentru a vizualiza imaginile
    CImgDisplay dispIn(imgIn, "Input");
    CImgDisplay dispOut;

    Pozitie posInit;
    posInit.x = imgIn.width() / 2;
    posInit.y = imgIn.height() / 2;

    // imgIn este o imagine grayscale (fiecare pixel este reprezentat de o valoare pe 8 biti, in [0,255])
    CImg<unsigned char> imgOut = ColoreazaDomeniu(imgIn, posInit, (unsigned char)148, dispOut);

    // Afisarea imaginilor
    dispOut = CImgDisplay(imgOut, "Output");

    // Asteptam ca utilizatorul sa inchida fereastra
    while (!dispIn.is_closed() && !dispOut.is_closed()) {
        dispIn.wait();
        dispOut.wait();
    }

    return 0;
}
