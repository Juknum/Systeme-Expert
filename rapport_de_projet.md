<div style="text-align:center;">
    <p style = "font-size:30px;">
	Rapport de projet LO21 : Système expert
	</p>
</div>

<p style="font-size:10px;">
	Membres du binôme : Constant Julien et Echard Noé
</p>

---

## Table des matières :
1. [Nos choix de conception, d'implémentation et la démarche adoptée](#Paragraphe1)
2. [Algorithmes des sous-programmes](#Paragraphe2)
	1. [Algorithmes des règles](#SousParagraphe1)
	2. [Algorithmes de la base de connaissance](#SousParagraphe2)
  3. [Algorithmes du moteur d'inférence](#SousParagraphe3)
3. [Jeu d'essai](#Paragraphe3)
4. [Commentaires](#Paragraphe4)


## 1. Nos choix de conception, d'implémentation et la démarche adoptée

Le sujet de notre projet de LO21 porte sur un "système expert". Un système expert est composé de trois partie : 
- Une base de connaissance : elle est composée d'une liste de règle.
- Une base de fait : une liste de proposition considérée comme vraie 
- Un moteur d'inférence qui permet de déduire une conclusion vraie en comparant la base de fait avec les règles de la base de connaissance.
 
Pour faire cela, nous avons défini trois types "principaux" de variables. Le type "Regle" est composé de deux types de variables "annexes" : le type conclusion qui est une chaine de caractère et le type prémisse qui est une liste chainée. Le type "BF" (base de fait) est une liste chainée. Enfin, le type "BC" (base de connaissance) est une liste de Regle.

#### Déclaration du type proposition et du type règle en détail :
```C
typedef struct proposition {
	char* content;
	struct proposition* next;
} Proposition;

typedef Proposition* Premisse;
typedef char* Conclusion;

typedef struct regle {
	Premisse premisse;
	Conclusion conclusion;
} Regle;
```
 

#### Déclaration du type BC (base de connaissance) en détail : 
```C 
typedef struct BC{
    Regle head;
    struct BC* next;
}ElemBC;

typedef ElemBC* BC;
```
![](https://imgur.com/88mnAI2.png)
>On peut représenter le type base de connaissance comme ceci avec une classification en groupes emboités.


#### Déclaration du type BF (base de fait) en détail : 
```C 
typedef Proposition* BF;
```
![](https://imgur.com/U7Uho44.png)
>On peut représenter le type base de connaissance comme ceci avec une classification en groupes emboités.
 
---


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
	si p est inédini alors
		retourner indéfini
	si suiv(p) est indéfini alors
		si contenu(p) = proposition alors
			libérer(contenu(p))
			libérer(p)
			retourner indéfini
		sinon
			retourner p
	si contenu(p) = proposition alors
		Premisse résultat = retirer_proposition(suiv(p), proposition)
		libérer(p)
		retourner résultat
	sinon
		suiv(p) = retirer_proposition(suiv(p), proposition)
		retourner p
Fin 
```
> Si p est vide, on retourne indéfini. Si suiv(p) est indéfini et si le seul élément de p est le même que la proposition alorslibérer p et retourner indéfini, sinon retourner p.
> (Si p et suiv(p) sont définis) Si contenu(p) = proposition alors on retourne une prémisse "résultat" qui vaut suiv(p). Sinon on retourne retirer_proposition pour l'élément suivant de p.


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
Fonction valeurTeteBase
Données : BC konwledge_basis
Résultat : variable de type Regle 
Debut
	return valeur_tete(knowledge_basis)
Fin
```
> On retourne la regle en tête de la base de connaissance.

### 3. Liste des sous-programmes du moteur d'inférence

**Rechercher une UV**
```pseudocode
Fonction rechercherUV
Données : BC knowledge_basis
          BF fact_basis
Résultat : BC known_fact
Début
  BC knowldge_buffer = créerBaseVide()
  BC know_fact = créerBaseVide()
  BF fact_buffer = créerListe()

  knowledge_buffer = knowledge_basis
  fact_buffer = fact_basis

  tant que est_vide(fact_buffer) est FAUX faire
    tant que est_vide(knowldge_buffer) est FAUX faire
      Premisse premisse_buffer = premisse(tete(suiv(knowledge_buffer)))
      tant que premisse_buffer != indéfini
        si contenu(premisse_buffer) = contenu(fact_buffer) alors
          known_fact = ajouterRegleBase(know_fact, tete(suiv(knowledge_buffer))
        fin si
        premisse_buffer = suiv(premisse_buffer)
      fin tant que
    knowldge_buffer = suiv(knowldge_buffer)
    fin tant que
    fact_buffer = suiv(fact_buffer)
  fin tant que
  retourner known_fact

Fin
```

> On crée des variables tampons. Tant que la base de fait tampon n'est pas vide et tant que la base de connaissance tampon n'est pas vide, on crée une variable tampon de type prémisse qui prend la valeur de la prémisse de la règle suivant la règle de tête de la base de connaissance.
> Tant que cette variable n'est pas indéfinie, si son contenu est le même que celui de la base de fait tampon, on ajoute la règle correspondant à cette prémisse à la base de connaissance know_fact. Une fois la boucle si terminée, la prémisse tampon pointe sur son élément suivant et on recommence.
> Une fois la boucle "tant que la prémisse tampon n'est pas indéfinie" est terminée, la base de connaissance tampon pointe sur son élément suivant, et on recommence.
>  Une fois la boucle "tant que la base de connaissance tampon n'est pas indéfinie" est terminée, la base de fait tampon pointe sur son élément suivant, et on recommence.
> Enfin, une fois la boucle "tant que la base de fait tampon n'est pas indéfinie" est terminée, on retourne la base de connaissance know_fact.

**Moteur d'inférence**
```pseudocode
Fonction moteurInference
Données : BC knowledge_basis
          BF fact_basis
Résultat : pas de résultat renvoyé
Début
	Si est_vide(knowledge_basis) est VRAI alors
		afficher("Base de connaissance vide, on ne peut rien déduire")
	sinon
		BC knowledge_buffer = créerBaseVide()
		BF fact_buffer = créerListe()

		knowledge_buffer = knowledge_basis
		fact_buffer = fact_basis
		
		tant que fact_buffer != indéfini faire 
			knowledge_buffer = rechercherUV(knowledge_buffer, fact_buffer)
			fact_buffer = suiv(fact_buffer)
		fin tant que

		Si est_vide(knowledge_buffer) est VRAI alors
			afficher("Aucune UV ne correspond")
		sinon
			afficher(conclusion(tete(suiv(knowledge_buffer))))
		fin si
	Fin si
Fin
```
>Si la base de connaissance est vide, alors on indique que l'on ne peut rien faire. Sinon, avec l'aide de variables tampons, tant que la base de fait tampon est définie, on applique rechercherUV à la base de connaissance tampon, puis on pointe ***suiv(fact_buffer)*** sur ***fact_buffer***. Une fois la boucle finie, si la base de connaissance tampon est vide, on indique que l'on a rien trouvé, sinon on indique ce que l'on a trouvé.


## 3. Jeu d'essai

Pour le jeu d'essai, nous avons choisi de faire un guide des UV. 
L'idée est de pouvoir rechercher une UV à partir de plusieurs propositions (comme sa catégorie (CS, TM, etc), son type (Maths, physique, électricité), un thème particulier ou encore les semestres où l'on peut l'étudier (automne, printemps, oul les deux)). Le système peut aussi faire une recherche dans l'autre sens : on lui donne une UV, et il nous renvoie ses caractéristiques. 


## 4. Commentaires

> partie à faire
