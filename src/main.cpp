#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>
#include <algorithm>
#include <complex>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <array>

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
/* void glitch(sil::Image& image) {
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
} */

//  */************************************ Exercice n°14 : glitch **********************************************
 /* void triPixel(sil::Image& image) {
    sil::Image imageReference = image;
    for (int b{0}; b < imageReference.height(); b++) {
        //Déterminer la position et la longueur du trie sur la ligne
        int longeurGlitch = random_int(30, 100);
        int positionXGlitch = random_int(0, imageReference.width());

        while (longeurGlitch+positionXGlitch > imageReference.width()){
            positionXGlitch = random_int(0, imageReference.width());
        }

        //Récupérer la portion et la mettre dans un nouveau tableau
        int indexDebut = positionXGlitch + b * image.width();
        int indexFin = indexDebut + longeurGlitch;
        std::vector<glm::vec3> portion(
            image.pixels().begin() + indexDebut,
            image.pixels().begin() + indexFin
        );     

        //Trier ce nouveau tableau
        std::sort(portion.begin(), portion.end(), [](glm::vec3 const& c1, glm::vec3 const& c2) {
            float b1 = (c1.r + c1.g + c1.b) / 3.f;
            float b2 = (c2.r + c2.g + c2.b) / 3.f;
            return b1 < b2;
        });

        //Remplacer dans le tableau d'origine
        for (int i = 0; i < longeurGlitch; i++) {
            image.pixels()[indexDebut + i] = portion[i];
        }

    }
}  */

//  */************************************ Exercice n°15 : Fractale de Mandelbrot **********************************************
/* void Fractale(sil::Image& image) {
    for (int x = 0; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::complex<float> nombreComplexePixel = {(x * (4.0f/500.0f)- 2.0f), (y * (4.0f/500.0f)- 2.0f)};
            std::complex<float> testFractale = {0, 0};
            bool boolFractale = true;
            float nbIteration = 0;
            float nbIterationMax = 50;
            for (int z = 0; z < nbIterationMax; z++) {
                testFractale = testFractale * testFractale + nombreComplexePixel;
                nbIteration++;
                if (std::abs(testFractale) > 2){
                    boolFractale = false;
                    break;
                }
            }
            if (boolFractale){
                image.pixel(x, y) = glm::vec3{1.0f, 1.0f, 1.0f};
            }
            else {
                image.pixel(x, y) = glm::vec3{nbIteration/nbIterationMax, nbIteration/nbIterationMax, nbIteration/nbIterationMax};
                //image.pixel(x, y) = glm::vec3{1.0f/nbIteration, 1.0f/nbIteration, 1.0f/nbIteration};
            }
        }
    }
} */

//  */************************************ Exercice n°16 : dégradé couleur **********************************************
/* void degradeCouleurMoche(sil::Image& image) {
    for (int x{0}; x < image.width(); x++){
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 1.0f - (x / float(image.width() - 1));
            image.pixel(x, y).g = x / float(image.width() - 1);
            image.pixel(x, y).b = 0.0f;
        }
    }
} 

//Conversion sRGB vers Linéar
float srgb_to_linear(float c)
{
    if (c <= 0.04045f)
        return c / 12.92f;
    else
        return pow((c + 0.055f) / 1.055f, 2.4f);
}

//Retour Linéar vers sRGB
float linear_to_srgb(float c)
{
    if (c <= 0.0031308f)
        return 12.92f * c;
    else
        return 1.055f * pow(c, 1.0f / 2.4f) - 0.055f;
}

//Linear vers OK LAB
glm::vec3 linear_srgb_to_oklab(glm::vec3 c) {
    float l = 0.4122214708f * c.r + 0.5363325363f * c.g + 0.0514459929f * c.b;
	float m = 0.2119034982f * c.r + 0.6806995451f * c.g + 0.1073969566f * c.b;
	float s = 0.0883024619f * c.r + 0.2817188376f * c.g + 0.6299787005f * c.b;

    float l_ = cbrtf(l);
    float m_ = cbrtf(m);
    float s_ = cbrtf(s);

    return {
        0.2104542553f*l_ + 0.7936177850f*m_ - 0.0040720468f*s_,
        1.9779984951f*l_ - 2.4285922050f*m_ + 0.4505937099f*s_,
        0.0259040371f*l_ + 0.7827717662f*m_ - 0.8086757660f*s_,
    };
}

//OK LAB vers Linéar
glm::vec3 oklab_to_linear_srgb(glm::vec3 c) 
{
    float l_ = c.r + 0.3963377774f * c.g + 0.2158037573f * c.b;
    float m_ = c.r - 0.1055613458f * c.g - 0.0638541728f * c.b;
    float s_ = c.r - 0.0894841775f * c.g - 1.2914855480f * c.b;

    float l = l_*l_*l_;
    float m = m_*m_*m_;
    float s = s_*s_*s_;

    return {
		+4.0767416621f * l - 3.3077115913f * m + 0.2309699292f * s,
		-1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s,
		-0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s,
    };
} */

/* void degradeCouleur(sil::Image& image) {
    glm::vec3 couleurRougeSRGB = {1.0f, 0.0f, 0.0f};
    glm::vec3 couleurVerteSRGB = {0.0f, 1.0f, 0.0f};

    //On commence par convertir SRGB vers Linéar
    //Attention pas tout d'un coup mais rouge, vert et bleu séparé
    glm::vec3 couleurRougeLin{
        srgb_to_linear(couleurRougeSRGB.r),
        srgb_to_linear(couleurRougeSRGB.g),
        srgb_to_linear(couleurRougeSRGB.b)
    };

    glm::vec3 couleurVerteLin{
        srgb_to_linear(couleurVerteSRGB.r),
        srgb_to_linear(couleurVerteSRGB.g),
        srgb_to_linear(couleurVerteSRGB.b)
    };

    //Ensuite Linéar vers OK Lab
    glm::vec3 couleurRougeLab = linear_srgb_to_oklab(couleurRougeLin);
    glm::vec3 couleurVerteLab = linear_srgb_to_oklab(couleurVerteLin);

    for (int x{0}; x < image.width(); x++){
        float degrade = x / float(image.width() - 1);
        glm::vec3 couleurActuelleLab = glm::mix(couleurRougeLab, couleurVerteLab, degrade);

        //On fait le chemin inverse : OK Lab vers Linéar
        glm::vec3 couleurActuelleLin = oklab_to_linear_srgb(couleurActuelleLab);

        //Puis Linéar vers SRGB
        glm::vec3 couleurActuellesSRGB{
            linear_to_srgb(couleurActuelleLin.r),
            linear_to_srgb(couleurActuelleLin.g),
            linear_to_srgb(couleurActuelleLin.b)
        };

        for (int y = 0; y < image.height(); y++){
            image.pixel(x, y) = couleurActuellesSRGB;
        }
    }
}  */

/* void arcEnCiel(sil::Image& image) {
    std::vector<glm::vec3> couleursArcEnCielSRGB = {
        {1.0f, 0.0f, 0.0f}, // rouge
        {1.0f, 1.0f, 0.0f}, // jaune
        {0.0f, 1.0f, 0.0f}, // vert
        {0.0f, 1.0f, 1.0f}, // cyan
        {0.0f, 0.0f, 1.0f}, // bleu
        {1.0f, 0.0f, 1.0f}  // rose
    };

    // Conversion sRGB → Linear → Oklab
    std::vector<glm::vec3> couleursArcEnCielLab;
    for (const auto& couleur : couleursArcEnCielSRGB)
    {
        //Convertie en linéar
        glm::vec3 couleursArcEnCielLin{
            srgb_to_linear(couleur.r),
            srgb_to_linear(couleur.g),
            srgb_to_linear(couleur.b)
        };

        //Convertie de Linéar à Lab et les met dans le tableau
        couleursArcEnCielLab.push_back(linear_srgb_to_oklab(couleursArcEnCielLin));
    }

    int nbSegmentArcEnCiel = couleursArcEnCielLab.size() -1; //7 couleurs donc 6 segments

    for (int x{0}; x < image.width(); x++){
        float degrade = x / float(image.width() - 1);

        float positionActuel = degrade * nbSegmentArcEnCiel; //On “étire” la position du dégradé pour qu’elle couvre tous les segments, ex si degradé = 0.3 alors la position sera = 0.3 * 5 = 1.5, soit la moitié du deuxième segment
        //Il faut qu'on est l'indice du segment actuelle
        int segment = std::floor(positionActuel); //Récupère l'indice du segment actuelle
        float positionActuelSegment = positionActuel - segment; //Ex : moitié du segment 2

        //On fait le dégradé seulement dans le segment actuel => indice de départ du dégradé
        glm::vec3 couleurActuelleLab = glm::mix(couleursArcEnCielLab[segment], couleursArcEnCielLab[segment+1], positionActuelSegment);

        glm::vec3 couleurActuelleLin = oklab_to_linear_srgb(couleurActuelleLab);

        glm::vec3 couleurActuelleSRGB{
            linear_to_srgb(couleurActuelleLin.r),
            linear_to_srgb(couleurActuelleLin.g),
            linear_to_srgb(couleurActuelleLin.b)
        };


        for (int y = 0; y < image.height(); y++){
            image.pixel(x, y) = couleurActuelleSRGB;
        }
    }
}   */

//  */************************************ Exercice n°17 : Tramage **********************************************
/* void tramage(sil::Image& image) {
    const int bayer_n = 4; 
    float bayer_matrix_4x4[][bayer_n] = { 
        { -0.5, 0, -0.375, 0.125 }, 
        { 0.25, -0.25, 0.375, - 0.125 }, 
        { -0.3125, 0.1875, -0.4375, 0.0625 }, 
        { 0.4375, -0.0625, 0.3125, -0.1875 }, 
    };

    for (int sy = 0; sy < image.height(); sy++) { 
        for (int sx = 0; sx < image.width(); sx++) { 
            float bayer_value = bayer_matrix_4x4[sx % bayer_n][sy % bayer_n]; 
            float imageNoirEtBlanc = image.pixel(sx,sy).r*0.3 + image.pixel(sx,sy).g*0.59 + image.pixel(sx,sy).b*0.11;

            float output_color = imageNoirEtBlanc + (1 * bayer_value);
            // Changer la couleur de l'écran du bleu au blanc 
            if (output_color < (1.0f / 2.0f)) { 
                image.pixel(sx, sy) = {0.0f, 0.0f, 0.0f}; 
            } 
            else {
                image.pixel(sx, sy) = {1.0f, 1.0f, 1.0f}; 
            }
        } 
    }
} */

//  */************************************ Exercice n°18 : Normalisation de l'histogramme **********************************************
/* void NormalisationHistogramme(sil::Image& image) {
    float  minimum =  1;
    float  maximum =  0;

    for (int x{0}; x < image.width()-1; x++) {
        for (int y{0}; y < image.height(); y++){
            float luminositéActuelle = (image.pixel(x,y).r + image.pixel(x,y).g + image.pixel(x,y).b)/3;
            if (luminositéActuelle < minimum) {
                minimum = luminositéActuelle;
            }
            else if (luminositéActuelle > maximum) {
                maximum = luminositéActuelle;
            }
        }
    } 

    for (int x{0}; x < image.width()-1; x++) {
        for (int y{0}; y < image.height(); y++){
            image.pixel(x,y).r = (image.pixel(x,y).r - minimum)/(maximum - minimum);
            image.pixel(x,y).g = (image.pixel(x,y).g - minimum)/(maximum - minimum);
            image.pixel(x,y).b = (image.pixel(x,y).b - minimum)/(maximum - minimum);
            //Ex le pixel le plus sombre est 0.2 et le pixel le plus clair 0.7
            //On translate en premier, on fait -0.2
            //On divise par 0.7
        }
    } 

} */

//  */************************************ Exercice n°19 : Vortex **********************************************

/* glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle){
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

void Vortex(sil::Image& image) {
    glm::vec2 center_of_rotation = {image.width()/2, image.height()/2};
    float angle = M_PI / 24;
    sil::Image imageReference = image;

    for (int x{0}; x < image.width()-1; x++) {
        for (int y{0}; y < image.height(); y++){
            glm::vec2 positionPoint = {x, y};
            float distance = glm::distance(center_of_rotation, positionPoint);
            glm::vec2 rotation = rotated(positionPoint, center_of_rotation, angle*distance);
            if (rotation[0] < image.width() && rotation[0] > 0 && rotation[1] < image.height() && rotation[1] > 0) {
                image.pixel(x,y) = imageReference.pixel(rotation[0],rotation[1]);
            }
            else {
                image.pixel(x,y) = {0.0f, 0.0f, 0.0f};
            }
        }
    }
    image.save("output/Vortex.png");
}  */

//  */************************************ Exercice n°19 : Convolution **********************************************

/* void Flou(sil::Image& image) {
    sil::Image imageReference = image;
    int flou = 3;
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++){
            if (x > flou && x < image.width()-flou && y > flou && y < image.height()-flou) {
                    
                image.pixel(x, y) = ((imageReference.pixel(x-flou, y-flou) + imageReference.pixel(x, y-flou) + imageReference.pixel(x+flou, y-flou) + imageReference.pixel(x-flou, y) + imageReference.pixel(x, y) + imageReference.pixel(x+flou, y) + imageReference.pixel(x-flou, y+flou) + imageReference.pixel(x, y+flou) + imageReference.pixel(x+flou, y+flou))/9.f);
            }

         pix(x-2, y) +    pix(x-1, y) + pix(x,  y)+ pix(x+1,  y)+ pix(x+2,  y)
        sum = glm::vec3(0);
         for(int delta_x = -flou, delta_x <= flou; ++delta_x)
            sum += pix(x+delta_x, y)
            //Haut 
            // else if (y <= flou && x > flou && x < image.width()-flou) {
            //     for (int z{0}; z < 3; z++){
            //         image.pixel(x, y)[z] = ((imageReference.pixel(x-flou, y+flou)[z] + imageReference.pixel(x, y+flou)[z] + imageReference.pixel(x+flou, y+flou)[z] + imageReference.pixel(x-flou, y)[z] + imageReference.pixel(x, y)[z] + imageReference.pixel(x+flou, y)[z] + imageReference.pixel(x-flou, y+flou)[z] + imageReference.pixel(x, y+flou)[z] + imageReference.pixel(x+flou, y+flou)[z])/9);
            //     }
            // }
            // //Bas
            // else if (y >= image.height()-flou && x > flou && x < image.width()-flou) {
            //     for (int z{0}; z < 3; z++){
            //         image.pixel(x, y)[z] = ((imageReference.pixel(x-flou, y-flou)[z] + imageReference.pixel(x, y-flou)[z] + imageReference.pixel(x+flou, y-flou)[z] + imageReference.pixel(x-flou, y)[z] + imageReference.pixel(x, y)[z] + imageReference.pixel(x+flou, y)[z] + imageReference.pixel(x-flou, y-flou)[z] + imageReference.pixel(x, y-flou)[z] + imageReference.pixel(x+flou, y-flou)[z])/9);
            //     }
            // } 
            // //Gauche
            // else if (x <= flou && y > flou && y < image.height()-flou) {
            //     for (int z{0}; z < 3; z++){
            //         image.pixel(x, y)[z] = ((imageReference.pixel(x+flou, y-flou)[z] + imageReference.pixel(x, y-flou)[z] + imageReference.pixel(x+flou, y-flou)[z] + imageReference.pixel(x+flou, y)[z] + imageReference.pixel(x, y)[z] + imageReference.pixel(x+flou, y)[z] + imageReference.pixel(x+flou, y+flou)[z] + imageReference.pixel(x, y+flou)[z] + imageReference.pixel(x+flou, y+flou)[z])/9);
            //     }
            // }
            // //Droite
            // else if (x >= image.width()-flou && y > flou && y < image.height()-flou) {
            //     for (int z{0}; z < 3; z++){
            //         image.pixel(x, y)[z] = ((imageReference.pixel(x-flou, y-flou)[z] + imageReference.pixel(x, y-flou)[z] + imageReference.pixel(x-flou, y-flou)[z] + imageReference.pixel(x-flou, y)[z] + imageReference.pixel(x, y)[z] + imageReference.pixel(x-flou, y)[z] + imageReference.pixel(x-flou, y+flou)[z] + imageReference.pixel(x, y+flou)[z] + imageReference.pixel(x-flou, y+flou)[z])/9);
            //     }
            // }  
            else {
                image.pixel(x, y) = glm::vec3(1, 0, 0); // rouge pétant
            }     
        }
    }
    image.save("output/Flou.png");
}  */

void Flou(sil::Image& image) {
    sil::Image imageReference = image;
    int flou = 5;
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++){
            glm::vec3 somme = glm::vec3(0);
            for (int deltaX = -flou; deltaX <= flou; deltaX++){
                for (int deltaY = -flou; deltaY <= flou; deltaY++){
                    if (x + deltaX > 0 && x + deltaX < image.width() && y + deltaY > 0 && y + deltaY < image.height()) {
                        somme = somme + imageReference.pixel(x+deltaX, y+deltaY);
                    }
                    else {
                        somme = somme + glm::vec3(0.0f, 0.0f, 0.0f);
                    }
                }
            } 
            image.pixel(x,y) = somme/float((flou*2+1)*(flou*2+1));
        }
    } 
    image.save("output/Flou.png");
}

void effet(sil::Image& image) {
    sil::Image imageReference = image;
    int flou = 1;
    float kernel[3][3] = {
        {0.0f, -1.0f,  0.0f},
        {-1.0f,  5.0f,  -1.0f},
        {0.0f,  -1.0f,  0.0f}
    };
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++){
            glm::vec3 somme = glm::vec3(0);
            for (int deltaX = -flou; deltaX <= flou; deltaX++){
                for (int deltaY = -flou; deltaY <= flou; deltaY++){
                    if (x + deltaX > 0 && x + deltaX < image.width() && y + deltaY > 0 && y + deltaY < image.height()) {
                        somme = somme + imageReference.pixel(x+deltaX, y+deltaY)*kernel[deltaX+1][deltaY+1];
                    }
                    else {
                        somme = somme + glm::vec3(0.0f, 0.0f, 0.0f);
                    }
                }
            } 
            image.pixel(x,y) = somme;
        }
    } 
    image.save("output/sharpen.png");
}

void FiltreSeparable(sil::Image& image) {
    sil::Image imageReference = image;
    sil::Image imageFinale = image;
    int flou = 5;
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++){
            glm::vec3 somme = glm::vec3(0);
            for (int deltaX = -flou; deltaX <= flou; deltaX++){
                    if (x + deltaX > 0 && x + deltaX < image.width()) {
                        somme = somme + imageReference.pixel(x+deltaX, y);
                    }
                    else {
                        somme = somme + glm::vec3(0.0f, 0.0f, 0.0f);
                    }
        
            } 
            image.pixel(x,y) = somme/float((flou*2+1));
        }
    } 
    for (int x{0}; x < image.width(); x++) {
        for (int y{0}; y < image.height(); y++){
            glm::vec3 somme = glm::vec3(0);
            for (int deltaY = -flou; deltaY <= flou; deltaY++){
                    if (y + deltaY > 0 && y + deltaY < image.height()) {
                        somme = somme + image.pixel(x, y+deltaY);
                    }
                    else {
                        somme = somme + glm::vec3(0.0f, 0.0f, 0.0f);
                    }
        
            } 
            imageFinale.pixel(x,y) = somme/float((flou*2+1));
        }
    } 
    imageFinale.save("output/FiltreSeparable.png");
}

int main()
{
    sil::Image image{"images/logo.png"};
    //sil::Image image{500/*width*/, 500/*height*/};
    FiltreSeparable(image);
    //image.save("output/Vortex.png");
} 