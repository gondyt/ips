# Instructions second projet

## Nuclear local density

On va nous donner une matrice contenant les rho de a,b, ils représentent une sorte de dentsité nucléaire (un peu comme un poids).

a et b représentent une liste de triplets contenant les m, n et n_z, donc on connaîtra a après avoir calculé la troncature.

## Fonctions de base

Les fonctions psy, appelées fonctions de base, sont compposées de trois termes :
- une fonction en fonction de Z, c'est l'axe z, déjà calculé dans le projet précédent.
- une fonction en fonction de r, la partie radiale, qui utilise les polynômes de Laguerre généralisés

La fonction psy n'apparaît jamais seule, leur calcul étant toujours considéré par paire, on se trouvera toujours dans des situations où la partie imaginaire va disparaître. Donc zéro besoin de nombres complexes de tout le projet.

Les paramètres b_z et b_perp : ce sont des paramètres de déformation de l'oscillateur, soit une sorte d'équivalent à omega la fréquence de l'oscillateur.

## Troncature de base

Dans le premier projet on n'avait qu'un seul nombre quantique, qui était n. Là, on en a trois : m, n et n_z.

On va donc utiliser une fonction de troncation :
- on définit d'abord m, car il ne dépend de personne
- puis on définit n, car il dépend de m_max
- et enfin on définit n_z, car il dépend de m et de n

Il faudra d'abord calculer le m_max, qui dépend de n_z_max(i) qu'il faut calculer aussi.

## Début du projet 

Il faut d'abord soit fork notre projet dans un nouveau git soit créer un nouveau git et y ajouter tous nos fichiers.

Tous les tests unitaires obligatoires doivent passer. D'autres doivent être rajoutés par nous-même évidemment.

Les résultats sont :
- les performances du code (combien il prend de mémoire, combien de temps met-il pour s'exécuter)
- le plot
- les solutions R calculées

## First mandatory test

On calcule les polynômes de Laguerre de la même façon que les polynômes de Hermite.

Le premier test unitaire obligatoire est sur le calcul des polynômes. Il faut s'adapter à sa structure, c'est-à-dire le faire fonctionner sans en changer un seul caractère.

Il faudra créer une classe Poly, la remplir en conséquence et etc...

## Second mandatory test on basis functions

Quand ce test il passe, ça veut dire qu'on a bien implémenté la troncature de base.

## Third mandatory test

Dans ce test la fonction rPart(r_perp, m, n) calcule en fait le terme R(r_perp, m, n) dans les fonctions de base.

> Conseil : rPart devrait être un attribut, comme ça son appel (qui risque d'être fréquent) évitera son re-calcul et optimisera le projet.

## Fourth mandatory test 

Idem que le test précédent, mais concerne le terme Z.

## Direct algorithm

Il est à coder et à regarder, mais pas à garder car sa complexité est affreuse.

Il faudra lui trouver une meilleure version, et ça on apprendra à le faire en cours, donc attendre avant de se lancer à corps perdu dedans est une bonne idée.

> penser à relever le speed-up, c'est-à-dire de combien on raccourcis le temms de calcul sur ce seul algorithme.

## Symmetries of the rho-matrix

- rho is symmetric : rho_ab = rho_ba
- rho is m-diagonal : p_ab = delta_ma,mb*rho_ab

La deuxième propriété permet d'affirmer que si ma != mb, tous les rho_ab sont nuls, il faut bidouiller mais c'est grâce à cela qu'on peut dire que forcément ma = mb et donc que le terme imaginaire du début peut être ignoré sans problème.