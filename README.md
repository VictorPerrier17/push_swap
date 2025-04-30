# push_swap

## Description

`push_swap` est un projet de l'école 42 dont l'objectif est de trier une pile d'entiers en un nombre minimal d'opérations. Le programme repose sur la manipulation de deux piles, A et B, à l’aide d’un ensemble limité d’instructions. L’enjeu est d’implémenter un algorithme de tri efficace, respectant les contraintes de performance imposées par le projet.

## Objectifs

- Développer un algorithme de tri optimisé utilisant uniquement les opérations autorisées.
- Générer une suite d'instructions qui permettent de trier une pile donnée.
- Minimiser le nombre d'opérations utilisées pour atteindre le tri complet.

## Fonctionnement

Le programme prend en entrée une liste d'entiers passée en ligne de commande. Il affiche sur la sortie standard une suite d'instructions parmi les suivantes, à appliquer pour trier la pile :

- **Swap** :
  - `sa` : échange les deux premiers éléments de la pile A.
  - `sb` : échange les deux premiers éléments de la pile B.
  - `ss` : `sa` et `sb` en simultané.

- **Push** :
  - `pa` : pousse le premier élément de la pile B vers la pile A.
  - `pb` : pousse le premier élément de la pile A vers la pile B.

- **Rotate** :
  - `ra` : fait monter tous les éléments de la pile A d’un cran.
  - `rb` : même chose pour la pile B.
  - `rr` : `ra` et `rb` en simultané.

- **Reverse Rotate** :
  - `rra` : fait descendre tous les éléments de la pile A d’un cran. Le dernier élément devient le premier.
  - `rrb` : même chose pour la pile B.
  - `rrr` : `rra` et `rrb` en simultané.

Le tri est considéré comme réussi si la pile A est en ordre croissant et que la pile B est vide après exécution de toutes les instructions.

## Performances

Voici une estimation des performances atteintes par l’algorithme implémenté :

- **50 nombres** : ~260 instructions
- **100 nombres** : ~610 instructions
- **500 nombres** : ~7200 instructions

Ces résultats peuvent légèrement varier en fonction des cas spécifiques, mais ils respectent largement les limites recommandées du projet.

## Compilation

```bash
make
```

## Utilisation

```bash
./push_swap [liste d'entiers]
```

## Notes et liens utiles

[Visualiseur par Emmanuel Ruaud](https://github.com/o-reo/push_swap_visualizer)
