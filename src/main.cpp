#include <sil/sil.hpp>

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
void Negatif(sil::Image& image) {
    for (glm::vec3& color : image.pixels())
    {   
        color.r = 1-color.r;
        color.g = 1-color.g;
        color.b = 1-color.b;
    }
}  

int main()
{
    sil::Image image{"images/logo.png"};
    Negatif(image);
    image.save("output/Negatif.png");
}