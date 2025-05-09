# Fract-ol

## Introduction

**Fract-ol** est un projet d'algorithmique et de programmation graphique réalisé dans le cadre de la formation **42**. Il permet de générer et de visualiser des fractales classiques telles que l'ensemble de **Mandelbrot** et l'ensemble de **Julia**, en utilisant des itérations sur des fonctions complexes. Le projet permet de mieux comprendre les concepts mathématiques derrière les fractales tout en développant des compétences en programmation C, en particulier en utilisant **minilibx**, une bibliothèque graphique.

## Concept

Une **fractale** est un objet mathématique qui présente des motifs auto-similaires à différentes échelles. Cela signifie que la structure d'une fractale est répétée à des niveaux de zoom différents. Deux des fractales les plus célèbres sont l'ensemble de Mandelbrot et l'ensemble de Julia.

### L'ensemble de Mandelbrot
L'ensemble de Mandelbrot est un ensemble de points dans le plan complexe qui sont générés par une suite d'itérations. Un point appartient à l'ensemble de Mandelbrot si la suite qui lui est associée reste bornée, c'est-à-dire qu'elle ne diverge pas vers l'infini.

### L'ensemble de Julia
L'ensemble de Julia est similaire à l'ensemble de Mandelbrot, mais la principale différence est que le paramètre dans la fonction complexe est fixé, et on examine le comportement de la suite pour chaque point du plan complexe.

Le but du projet est de représenter graphiquement ces fractales et d’offrir une interface interactive pour explorer et zoomer sur différentes régions.

## Fonctionnalités

- **Affichage de l'ensemble de Mandelbrot** : Permet de visualiser l'ensemble de Mandelbrot en temps réel.
- **Affichage de l'ensemble de Julia** : Permet de visualiser l'ensemble de Julia avec différents paramètres.
- **Zoom interactif** : Permet de zoomer et dézoomer sur les fractales pour explorer différentes régions.
- **Navigation** : Déplacer la fenêtre d'affichage pour explorer l'ensemble.
- **Personnalisation** : Modifier les paramètres des fractales (pour Julia, les utilisateurs peuvent ajuster les paramètres complexes pour explorer différentes formes).

## Installation

### Prérequis
- Ce projet utilise **minilibx** pour l'affichage graphique, donc assurez-vous d'avoir cette bibliothèque installée sur votre machine. Si vous travaillez sur macOS, vous pouvez installer minilibx avec la commande suivante :


