#include <sil/sil.hpp>

void UniquementVert(sil::Image& image) {
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
}

int main()
{
    sil::Image image{"images/logo.png"};
    UniquementVert(image);
    image.save("output/UniquementVert.png");
}