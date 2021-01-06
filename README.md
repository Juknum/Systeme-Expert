# Projet LO21
> A faire seul ou par groupe de deux étudiants (pas plus)

Un système expert est composé d'une base de connaissances, une base de faits et un moteur d'inférence.
Dans ce projet, nous proposons de réaliser un système expert, dans lequel, les connaissances sont des propositions logiques pouvant avoir la valeur "vrai" ou "faux".

## 1. Définition des composantes d'un système expert 
- Une **base de connaissance est une liste** de règles.
- Une **règle** est composée de deux parties :
    - Une partie **prémisse** contenant des **propositions reliées par l'opérateur logique "et"**.
    - Une partie **conclusion** contenant **une seule proposition**.

### Exemple d'une règle: A et B et C => D

Dans cette règle, la prémisse est : **A et B et C**, la conclusion est **D**.   

Une règle se lit de la manière suivante : si la prémisse est vrai alors on déduit que la conclusion est vraie.  
On considère une règle comme une liste de proposition, dont le dernier élément est la conclusion de la règle.  

- Une **base de faits** est une liste de propositions considérées comme vraies.

## 2. Questions
1. Définir un type abstrait de données appelé **Regle** permettant de définir les règles d'une base de connaissances. Ecrire l'algorithme et le sous-programme C correspondant aux opérations suivantes :

- [x] Créer une règle vide,
- [x] Ajouter une proposition à la prémisse d'une règle, l'ajout se fait en queue
- [x] Créer la conclusion d'une règle
- [x] Tester si une proposition appartient à la prémisse d'une règle, **de manière recursive**
- [x] Supprimer une proposition de la prémisse d'une règle
- [x] Tester si la prémisse d'une règle est vide
- [x] Accéder à la proposition se trouvant en tête d'une prémisse
- [x] Accéder à la conclusion d'une règle

2. Définir un type abstrait **BC** permettant de définir des bases de connaissances comme liste de règles. Ecrire l'algorithme et le sous-programme C correspondant aux opérations suivantes :

- [x] Créer une base vide
- [x] Ajouter une règle à une base, l'ajout peut se faire en queue
- [x] Accéder à la règle se trouvant en tête de la base

3. Ecrire l'algorithme et le programme C réalisant le moteur d'inférence (comme expliqué en cours). Un moteur d'inférence permet de déduire des faits certains (vrais) en partant de la base de faits et en appliquant les règles de la base de connaissance. L'algorithme et le programme doivent utiliser les opérations des 2 questions précédentes et éventuellement, les autres opérations prédéfinies sur le type abstrait liste étudié en cours.

## 3. Rapport

Le rapport devra contenir les éléments suivants :
- [x] Description des choix de conception et d'implémentation relatifs aux structures de données utilisées et à la démarche adoptée.
- [x] Algorithmes des sous programmes (en utilisant des opérations abstraites) et leurs explications.
- [x] Jeux d'essais.
- [x] Commentaires sur les résultats.

**Le rapport ne devra pas contenir de listing du programme C.**

## 4. Remarques
- Un programme C et du pseudocode ne sont pas des algorithmes.
- Un algorithme nécessite de donner son profil (données, résultat, lexique).
- Un programme doit être commenté (de façon utile).
- La qualité d'implémentation est prise en compte.

**Rapport à rendre et démonstration à réaliser sur ordinateur devant l'enseignant.**