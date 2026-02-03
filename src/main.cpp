#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>

// /* ************************************ Exercice n°1 : Ne garder que le vert ********************************************* */
/* void UniquementVert(sil::Image& image) {
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
}  */

//  */************************************ Exercice n°2 : Échanger les canaux **********************************************
/* void EchangerLesCanaux(sil::Image& image) {
    for (glm::vec3& color : image.pixels())
    {   
        std::swap(color.r, color.b);
    }
}  */

//  */************************************ Exercice n°3 : Noir et blanc **********************************************
/*  void NoirEtBlanc(sil::Image& image) {
    for (glm::vec3& color : image.pixels())
    {   
        float nb = color.r*0.3 + color.g*0.59 + color.b*0.11;
        //Jamais le même gris comme on est dans une boucle
        color.r = nb;
        color.g = nb;
        color.b = nb;
    }
}  */

//  */************************************ Exercice n°4 : Négatif **********************************************
/* void Negatif(sil::Image& image) {
    for (glm::vec3& color : image.pixels())
    {   
        color.r = 1-color.r;
        color.g = 1-color.g;
        color.b = 1-color.b;
    }
}  */ 

//  */************************************ Exercice n°5 : dégradé **********************************************
/* void degrade(sil::Image& image) {
for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        float gris = x / float(image.width() - 1);
        image.pixel(x, y) = glm::vec3{gris, gris, gris};
    }
}
}  */

//  */************************************ Exercice n°6 : inverse **********************************************
/* void inverse(sil::Image& image) {
sil::Image imageReference = image;
for (int x{0}; x < image.width()-1; x++)
{
    for (int y{0}; y < image.height(); y++)
    {
        image.pixel(x, y) = imageReference.pixel(imageReference.width()-(x+1), y);
    }
}
}   */

//  */************************************ Exercice n°7 : image bruité **********************************************
/* void bruit(sil::Image& image) {
    for (glm::vec3& color : image.pixels()) {
        if (true_with_probability(0.3)) {
            float rand = random_float(0, 1);
            color.r = rand;
            rand = random_float(0, 1);
            color.g = rand;
            rand = random_float(0, 1);
            color.b = rand;
        }
    }
}   */

//  */************************************ Exercice n°8 : 90° **********************************************
/* sil::Image AngleDroit(sil::Image& image) {
    sil::Image rotation{image.height(), image.width()}; //On inverse la proportion longueur et largeur
    for (int x = 0; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            rotation.pixel(rotation.width() - 1 - y, x) = image.pixel(x, y); //Voir schéma read me
        }
    }
    return rotation;
}  */

//  */************************************ Exercice n°9 : RGB Split **********************************************
/* void RGBsplit(sil::Image& image) {
    sil::Image imageReference = image;
    for (int x{0}; x < image.width()-1; x++)
    {
        for (int y{0}; y < image.height(); y++){
            glm::vec3 color;
            if (x < 31) {
                //On remarque sur l'image de référence qu'il n'y a pas de rouge
                color.g = imageReference.pixel(x, y).g;
                color.b = imageReference.pixel(x+30, y).b;
            }
            else if (x >= image.width()-31) {
                //On remarque sur l'image de référence qu'il n'y a pas de bleu
                color.r = imageReference.pixel(x-30, y).r;
                color.g = imageReference.pixel(x, y).g;
            }
            else {
                color.r = imageReference.pixel(x-30, y).r;
                color.g = imageReference.pixel(x, y).g;
                color.b = imageReference.pixel(x+30, y).b;
            }
            image.pixel(x, y) = color;
        }
    }
}    */

//  */************************************ Exercice n°9 : RGB Split **********************************************
/* void assombrissement(sil::Image& image) {
    for (int x{0}; x < image.width()-1; x++)
    {
        for (int y{0}; y < image.height(); y++){
            glm::vec3 color;
            color.r = std::pow(image.pixel(x, y).r, 1.5f);
            color.g = std::pow(image.pixel(x, y).g, 1.5f);
            color.b = std::pow(image.pixel(x, y).b, 1.5f);
            image.pixel(x, y) = color;
        }
    }
}

void eclaircissement(sil::Image& image) {
    for (int x{0}; x < image.width()-1; x++)
    {
        for (int y{0}; y < image.height(); y++){
            glm::vec3 color;
            color.r = std::pow(image.pixel(x, y).r, 0.5f);
            color.g = std::pow(image.pixel(x, y).g, 0.5f);
            color.b = std::pow(image.pixel(x, y).b, 0.5f);
            image.pixel(x, y) = color;
        }
    }
}  */  

//  */************************************ Exercice n°11 : disque **********************************************
/* void disque(sil::Image& image) {
    int rayon = 150;
    for (int z{0}; z < 25; z++) {
        for (int x{0}; x < image.width()-1; x++){
            for (int y{0}; y < image.height(); y++){
                float longueur = x - ((image.width() / 25)*z);
                float hauteur = y - (image.height() / 2.0f);
                if (longueur*longueur + hauteur*hauteur <= rayon*rayon) { //le point est dans le cercle
                    image.pixel(x, y) = glm::vec3{1.0f, 1.0f, 1.0f};
                }
                else { //le point est dans le cercle
                    image.pixel(x, y) = glm::vec3{0.0f, 0.0f, 0.0f};
                }
            }
        }
    image.save("output/Animation/disque"+ std::to_string(z) +".png");
    }
} */

/* void cercle(sil::Image& image) {
    int rayon = 150;
    int epaisseur = 10;
    for (int x{0}; x < image.width()-1; x++)
    {
        for (int y{0}; y < image.height(); y++){
            float longueur = x - (image.width() / 2);
            float hauteur = y - (image.height() / 2);
            if ( (rayon-epaisseur)*(rayon-epaisseur) <= longueur*longueur + hauteur*hauteur && longueur*longueur + hauteur*hauteur <= rayon*rayon) { 
                image.pixel(x, y) = glm::vec3{1.0f, 1.0f, 1.0f};
            }
        }
    }
}  */

/* void rosace(sil::Image& image) {
    int rayon = 100;
    int epaisseur = 5;

    //Cercle de base
    float centrex = image.width() / 2;
    float centrey = image.height() / 2;
    for (int x{0}; x < image.width()-1; x++)
    {
        for (int y{0}; y < image.height(); y++){
            float longueur = x - (centrex);
            float hauteur = y - (centrey);
            if ( (rayon-epaisseur)*(rayon-epaisseur) <= longueur*longueur + hauteur*hauteur && longueur*longueur + hauteur*hauteur <= rayon*rayon) { 
                image.pixel(x, y) = glm::vec3{1.0f, 1.0f, 1.0f};
            }
        }
    }

    //Rosace
    for (int z{0}; z < 6; z++) {
        float pointDépartx = (image.width() / 2)+ rayon*cos(z * M_PI / 3);
        float pointDéparty = (image.height() / 2) + rayon*sin(z * M_PI / 3);
        
        for (int x{0}; x < image.width()-1; x++) {
            for (int y{0}; y < image.height(); y++){
                float longueur = x - (pointDépartx);
                float hauteur = y - (pointDéparty);
                if ( (rayon-epaisseur)*(rayon-epaisseur) <= longueur*longueur + hauteur*hauteur && longueur*longueur + hauteur*hauteur <= rayon*rayon) { 
                    image.pixel(x, y) = glm::vec3{1.0f, 1.0f, 1.0f};
                }
            }
    }
    }
}  */

//  */************************************ Exercice n°12 : mosaïque **********************************************
/* void joliFail(sil::Image& image) {
    int longueurToile = image.width()*5;
    int largeurToile = image.height()*5;
    sil::Image toile{longueurToile, largeurToile};
    sil::Image motif = image;
    for (int a{0}; a < 5; a++){
        for (int b{0}; b < 5; b++){
            for (int x{0}; x < motif.width()-1; x++){
                for (int y{0}; y < motif.height(); y++)
                {
                    toile.pixel(x*a, y*b) = motif.pixel(x, y);
                }
            }
        }
    }
    toile.save("output/joliFail.png");
}   

void mosaique(sil::Image& image) {
    int longueurToile = image.width()*5;
    int largeurToile = image.height()*5;
    sil::Image toile{longueurToile, largeurToile};
    sil::Image motif = image;
    for (int a{0}; a < 5; a++){
        for (int b{0}; b < 5; b++){
            for (int x{0}; x < motif.width()-1; x++){
                for (int y{0}; y < motif.height(); y++)
                {
                    toile.pixel(x + a*motif.width(), y + b*motif.height()) = motif.pixel(x, y);
                }
            }
        }
    }
    toile.save("output/mosaique.png");
}    */

/* void mosaiqueInverse(sil::Image& image) {
    int longueurToile = image.width()*5;
    int largeurToile = image.height()*5;
    sil::Image toile{longueurToile, largeurToile};
    sil::Image motif = image;
    for (int a{0}; a < 5; a++){
        for (int b{0}; b < 5; b++){
            for (int x{0}; x < motif.width()-1; x++){
                for (int y{0}; y < motif.height(); y++)
                {
                    if (a%2 == 0 && b%2 ==0) {
                        toile.pixel(x + a*motif.width(), y + b*motif.height()) = motif.pixel(x, y);
                    }
                    else if (a%2 == 1 && b%2 == 0) {
                        toile.pixel(x + a*motif.width(), y + b*motif.height()) = motif.pixel(motif.width()-1-x, y);
                    }
                    else if (a%2 == 1 && b%2 == 1) {
                        toile.pixel(x + a*motif.width(), y + b*motif.height()) = motif.pixel(motif.width()-1-x, motif.height()-1-y);
                    }
                    else if (a%2 == 0 && b%2 == 1) {
                        toile.pixel(x + a*motif.width(), y + b*motif.height()) = motif.pixel(x, motif.height()-1-y);
                    }
                }
            }
        }
    }
    toile.save("output/mosaiqueInverse.png");
} */ 

//  */************************************ Exercice n°13 : glitch **********************************************
void glitch(sil::Image& image) {
    sil::Image imageReference = image;
    for (int x{0}; x < image.width()-1; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) = imageReference.pixel(x, y);
        }
    }

    for (int a{0}; a < 250; a++) {
        int longeurGlitch = random_int(0, 20);
        int largeurGlitch = random_int(0, 10);
        int positionXGlitch1 = random_int(0, imageReference.width());
        int positionYGlitch1 = random_int(0, imageReference.height());
        int positionXGlitch2 = random_int(0, imageReference.width());
        int positionYGlitch2 = random_int(0, imageReference.height());

        while (longeurGlitch+positionXGlitch1 > imageReference.width() || longeurGlitch+positionXGlitch2 > imageReference.width()){
            longeurGlitch = random_int(0, 20);
        }
        while (largeurGlitch+positionYGlitch1 > imageReference.height() || largeurGlitch+positionYGlitch2 > imageReference.height()){
            largeurGlitch = random_int(0, 10);
        }

        for (int x{0}; x < image.width()-1; x++) {
            for (int y{0}; y < image.height(); y++){
                if (x >= positionXGlitch1 && x < positionXGlitch1 + longeurGlitch && y >= positionYGlitch1 && y < positionYGlitch1 + largeurGlitch) {
                    image.pixel(x, y) = imageReference.pixel(positionXGlitch2, positionYGlitch2);
                }
                else if (x >= positionXGlitch2 && x < positionXGlitch2 + longeurGlitch && y >= positionYGlitch2 && y < positionYGlitch2 + largeurGlitch) {
                    image.pixel(x, y) = imageReference.pixel(positionXGlitch1, positionYGlitch1);
                }
            }
        }
    }
}

int main()
{
    sil::Image image{"images/logo.png"};
    //sil::Image image{500/*width*/, 500/*height*/};
    glitch(image);
    image.save("output/glitch.png");
}