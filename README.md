# Workshop prog algo - Agathe OLIVIER

## Exercice n°1 : Ne garder que le vert

Mettre le bleu et le rouge à 0.

![](./output/UniquementVert.png)

## Exercice n°2 : Échanger les canaux

Avec swap.

![](./output/EchangerLesCanaux.png)

## Exercice n°3 : Noir et blanc 

Grace à la formule de luminance (rouge*0.3 + vert*0.59 + bleu*0.11)

![](./output/NoirEtBlanc.png)

## Exercice n°4 : Négatif

1-couleur pour avoir l'inverse.

![](./output/Negatif.png)

## Exercice n°5 : Dégradé

Equivalent de map en Processing puis (gris, gris, gris) pour les couleurs.

![](./output/degrade.png)

## Exercice n°6 : Inverse

Au départ je n'avais pas stocker l'image de référence, et j'obtenais une symétrie.

![](./output/inverse.png)

## Exercice n°7 : Bruits

30% de chance que le pixel soit remplacé par une couleur aléatoire.

![](./output/bruit.png)

## Exercice n°8 : Rotation 90°

J'ai eu un peu de mal à comprendre la formule pour la rotation à 90, j'ai donc fait un schéma sur papier pour mieux comprendre ce qui se passait :

![](./images/LogiqueRotationEx8.jpg)

J'ai donc obtenu le bon résultat : 

![](./output/rotation90.png)

## Exercice n°9 : RGB Split

J'ai eu du mal à trouver les conditions dans les if, au départ je gardais les pixels de base mais ça faisait un bord à l'effet.

J'ai compris grace à mes camarades qu'il fallait retirer le rouge ou le bleu en fonction du bord.

![](./output/RGBsplit.png)

## Exercice n°10 : Luminosité

Puissance 1,5 pour assombrir et puissance 0,5 pour éclairer.

![](./output/assombrissement.png)
![](./output/eclaircissement.png)

## Exercice n°11 : Disque

On a un cercle qui a pour centre le point [cx, cy] et pour rayon R. 
L'équation de la droite est :

>(x−cx)² + (y−cy)² ≤ R²

Si (x−cx)² + (y−cy)² < R² alors le point est à l’intérieur du disque.
Si (x−cx)² + (y−cy)² = R² alors le point est sur le contour
Si (x−cx)² + (y−cy)² > R² alors le point est à l’extérieur

![](./output/disque.png)

### Partie 2 : cercle

Le plus gros problème a été les maths (aled 🥲), heurement les camarades m'ont expliqué la formule : 
>(R−e)² ≤ (x−cx)² + (y−cy)² ≤ R²

La deuxième difficulté a été de comprendre qu'il fallait séparer la condition en 2, sinon on obtient une image toute blanche.

![](./output/cercle.png)

### Partie 2 : Animation

25 images pour le GIF.

![](/output/Animation/CercleAnime.gif)

### Partie 3 : Rosace

Le plus gros problème : les maths 🥲
Les formules : 
>Point de départ X = Centre de l'image + rayon * cos(z * π / 3)

>Point de départ Y = Centre de l'image + rayon * sin(z * π / 3)

![](./output/rosace.png)

## Exercice n°12 : Mosaïque

J'ai fait un premier test où le décalage était mal pensé, mais le résultat intéressant donc je l'ai sauvegardé dans "joliFail" :

![](./output/joliFail.png)

J'ai réajusté le problème de décalage pour obtenir le bon résultat : 

![](./output/mosaique.png)

### Partie 2 : Mosaïque inversée

J'ai commencé par définir 4 les formes possibles de l'image et à quel moment elle était affiché : 

![](./images/LogiqueMosaiqueInverseeEx12.jpg)

Il m'a suffit ensuite de le retranscrire en code pour obtenir le résultat :

![](./output/mosaiqueInverse.png)