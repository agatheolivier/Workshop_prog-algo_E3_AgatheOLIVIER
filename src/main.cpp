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
void assombrissement(sil::Image& image) {
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
}   

int main()
{
    sil::Image image{"images/photo.jpg"};
    //sil::Image image{300/*width*/, 200/*height*/};
    eclaircissement(image);
    image.save("output/eclaircissement.png");
}