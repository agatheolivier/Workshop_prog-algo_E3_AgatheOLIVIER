#include <sil/sil.hpp>

/* ************************************ Exercice n°1 : Ne garder que le vert **********************************************/
/* void UniquementVert(sil::Image& image) {
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
} */

void EchangerLesCanaux(sil::Image& image) {
    for (glm::vec3& color : image.pixels())
    {   
        std::swap(color.r, color.b);
    }
}

int main()
{
    sil::Image image{"images/logo.png"};
    EchangerLesCanaux(image);
    image.save("output/EchangerLesCanaux.png");
}