<div style = "text-align:center;">
	<p style = "font-size:30px;">
Rapport de projet LO21 : Système expert
	</p>
</div>

<div style = "font-size:10px;">
Membres du binôme : Constant Julien et Echard Noé
</div>

## Table des matières :
1. [Nos choix de conception d'implémentation et la démarche adoptée](#Paragraphe1)
2. [Algorithmes des sous-programmes](#Paragraphe2)
    1. [Algorithmes des règles](#SousParagraphe1)
    2. [Algorithmes de la base de connaissance](#SousParagraphe2)
3. [Jeu d'essai](#Paragraphe3)
4. [Commentaires](#Paragraphe4)


## 1. Nos choix de conception d'implémentation et la démarche adoptée

> partie à faire

## 2. Algorithmes des sous-programmes

   ### 1. Liste des sous-programmes des règles

**Créer une règle vide**
```pseudocode
Fonction créer_règle
Données : pas de données
Résultat : Regle nouvelleRegle
Debut
	nouvelleRegle <- new(regle)
	retourner nouvelleRegle
Fin
```
> On alloue la mémoire nécessaire pour une variable de type règle que l’on retourne ensuite


**Tester si la règle/prémisse/conclusion est vide**
```pseudocode
Fonction est_vide_regle
Données : Regle r
Résultat : VRAI si r est vide
Debut
	si r est indéfini
	    retourner VRAI
	sinon
		retourner FAUX
	fin si
Fin
```
```pseudocode
Fonction est_vide_premisse
Données : Premisse p
Résultat : VRAI si p est vide
Debut
	si p est indéfini alors
		retourner VRAI
	sinon 
		retourner FAUX
	fin si
Fin 
```
```pseudocode
Fonction est_vide_conclusion
Données : Regle r
Résultat : VRAI si conclusion(r) est vide
Debut
	si conclusion(r) est indéfini alors
		retourner VRAI
	sinon 
		retourner FAUX
	fin si
Fin 
```
> Les trois algorithmes fonctionnent de manière similaire : si la règle/conclusion/prémisse ne contient rien, retourner **VRAI**, sinon retourner **FAUX**


**Ajout d'une proposition à la prémisse (ajout en queue)**
```pseudocode
Fonction ajouter_proposition
Données : Regle r
		  string proposition)
Résultat : Regle r 
Debut
	si est_vide_regle(r) est VRAI alors
		nouvelleProposition(proposition)
		premisse(r) <- proposition
		suiv(premisse(r)) <- indéfini
	sinon si est_proposition(premisse(r), proposition) est FAUX alors
		Regle l = r
			tant que est_vide_premisse(suiv(l)) est FAUX faire
				l <- suiv(l)
			fin tant que
			nouvelleProposition(nouvProposition)
			contenu(nouvProposition) <- proposition
			suiv(nouvProposition) = indéfini
			suiv(l) <- nouvProposition
	sinon
		retourner ERREUR
	fin si
	retourner l
Fin
```
> On teste si la règle est vide. Si c’est le cas, la prémisse prend la valeur de la proposition. Sinon, on teste si la proposition est déjà dans la prémisse (au cas où). Si ce n’est pas le cas, on ajoute la proposition en queue de prémisse.


**Créer la conclusion d'une règle**
```pseudocode
Fonction creer_conclusion
Données : Regle r
		  string proposition
Résultat : Regle r
Debut
Regle l = r
	si est_vide(l) est VRAI alors
		conclusion est indéfini
	sinon
		conclusion(l) <- proposition
Fin
```
> On teste si la règle est vide. Si c’est le cas, on ne peut rien conclure. Sinon, la conclusion prend la valeur de la proposition.


**Tester si une proposition appartient à une prémisse (récursivement)**
```pseudocode
Fonction est_proposition
Données : Premisse p
		  string proposition
Résultat : VRAI si la proposition appartient à la prémisse
Debut
	si est_vide_premisse(p) est VRAI alors
		retourner FAUX
	sinon
		si contenu(p) = proposition
			retourner VRAI
		sinon
			retourner est_proposition(suiv(p), proposition)
		fin si
	fin si
fin 
```
> On teste si la prémisse est vide. Si c’est le cas alors on retourne FAUX. Sinon si la proposition de la prémisse est la même proposition que celle que l’on veut tester, alors on retourne VRAI. Si ce n’est pas le cas, on retourne la fonction pointant sur l’élément suivant de la prémisse.


**Retirer une proposition d'une prémisse**
```pseudocode
Fonction retirer_proposition
Données : Premisse p
		  string proposition
Résultat : Premisse p
Debut
	si est_vide_premisse(p) est VRAI alors
		retourner p
	sinon si contenu(p) = proposition alors
		si est_vide_premisse(suiv(p)) est VRAI alors
			retourner indéfini
		sinon
			Premisse tampon = suiv(p)
			liberer(p)
			p = tampon
			retouner p
	sinon si est_vide_premisse(suiv(p)) est VRAI alors
		retourner p
	sinon si contenu(suiv(p)) = proposition alors
		Premisse taampon = suiv(suiv(p))
		liberer(suiv(p))
		suiv(p) = tampon
		return p
	sinon
		retouner retirer_proposition(suiv(p), proposition)
Fin 
```
> On teste si la prémisse est vide. Si c'est le cas, on retourne la prémisse inchangé (on ne peut rien supprimer). Sinon, on étudie le cas où la proposition est en tête de prémisse. Si c'est le cas et que la prémisse ne contient pas d'autre élément, on retourne indéfini. Si elle en contient d'autres, on se sert d'une prémisse tampon pour supprimer l'élément de tête.
> Dans le cas où la proposition n'est pas en tête de prémisse, on vérifie si la prémisse contient plus d'une proposition, si ce n'est pas le cas, on retourne p inchangée (on ne peut rien supprimer). Sinon, (à finir structure de l'algo discutable)


**Accès à l'élément de tête d'une prémisse**
```pseudocode
Fonction acces_tete_premisse
Données : Regle r
Résultat : proposition en tête de prémisse (string) de la regle
Debut
	si est_vide_premisse(premisse(r)) est VRAI alors
		retourner indéfini
	sinon
		retourner contenu(premisse(r))
	fin si
fin
```
> On teste si la prémisse de la règle est vide. Si c'est le cas, on retourne indéfini. Sinon, on retourne le contenu du premier élément de la prémisse de r.


**Accès à la conclusion d'une règle**
```pseudocode
Fonction acces_conclusion
Données : Regle r
Résultat : conclusion de la règle (string)
Debut
	 si est_vide_conlcusion(r) est VRAI alors
		retourner indéfini
	sinon
		retourner conclusion(r)
	fin si
fin 
```
> On teste si la conclusion de la règle est vide. Si c'est le cas, on retourne indéfini. Sinon on retourne le contenu de la conclusion de r.


   ### 2. Liste des sous-programmes de la base de connaissance

**Créer une base vide**
```pseudocode
Fonction créerBaseVide
Données : pas de données
Résultat : BC new_basis
Debut 
    new_basis <- new(BC)
    retourner new_basis
Fin
```
> On alloue de la mémoire pour une variable de type BC que l'on retourne ensuite

**Ajouter une règle à la base de connaissance**
```pseudocode
Fonction ajouterRegleBase
Données : BC knowledge_basis
         Regle r
Résultat : BC knowledge_basis
Debut
    si knowledge_basis est indéfini alors
        knowledge_basis = r
    sinon
        BC tampon = knowledge_basis
        tant que tampon != indéfini
            tampon <- suiv(tampon)
        fin tant que
        créerBaseVide(tampon2)
        element_tete(tampon2) = r
        suiv(tampon) = tampon2
    fin  si 
Fin
```
> On teste si la base est vide. Si c'est le cas, on copie simplement la règle de la base de connaissance. Sinon, on parcourt la base à l'aide d'une base tampon, puis à l'aide d'un autre tampon on met la règle en queue de la première base tampon. 

**Acceder à la valeur de tête de la base de connaissance**
```pseudocode
Fonction headValueBasis
Données : BC konwledge_basis
Résultat : variable de type Regle 
Debut
    return valeur_tete(knowledge_basis)
Fin
```
> On retourne la regle en tête de la base de connaissance.


## 3. Jeu d'essai

Pour le jeu d'essai, nous avons choisi de faire un guide des UV. L'idée est de pouvoir rechercher une UV à partir de plusieurs propositions (comme sa catégorie (CS, TM, etc), son type (Maths, physique, électricité), un thème particulier ou encore les semestres où l'on peut l'étudier (automne, printemps, oul les deux)). Le système peut aussi faire une recherche dans l'autre sens : on lui donne une UV, et il nous renvoie ses caractéristiques. 

:bulb: Images à insérer pour illustrer le travail

> partie à revoir pour plus de contenu

## 4. Commentaires

> partie à faire