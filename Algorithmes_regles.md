## Données:
Règle : liste dont le dernier élément est la conclusion de ladite règle.

## Algorithmes:
```pseudocode
créerRegle(Regle nouvelleRegle) : Règle
Debut
	nouvelleRegle <- new(regle)
	retourner nouvelleRegle
Fin
```

```pseudocode
nouvelleProposition(String proposition) : Regle
Debut
	nouvelleProposition <- new(proposition)
	retourner nouvelleProposition
Fin
```

```pseudocode
nouvelleConclusion(String conclusion) : Regle
Debut
	nouvelleConclusion <- new(conclusion)
	retourner nouvelleConclusion
Fin
```

```pseudocode
est_vide(Regle r) : Booléen
Debut
	si r est NULL
		retourner VRAI
	sinon
		retourner FAUX
Fin
```

```pseudocode
comptage_val(Regle r) : integer
Debut
	c = 0
	Regle l = r
	si r est NULL
		retourner 0
	sinon
		tant que est_vide(l) est FAUX faire
			c = c + 1
			l <- reste(l)
		fin tant que
	retourner c
Fin 
```

```pseudocode
premisse(Regle r) : string
Debut
	si est_vide(r) est VRAI alors
		reourner NULL
	sinon
		retourner premisse(r)
Fin
```

```pseudocode
conclusion(Regle r) : string
Debut
Regle l = r
	si est_vide(r) est VRAI alors
		retourner NULL
	sinon
		tant que est_vide(l) est FAUX faire
			l <- reste(l)
		fin tant que
		conclusion(l) <- l
		retourner conclusion(l)
Fin
```

```pseudocode
ajouter_proposition(Regle r, string proposition) : Regle
Debut
Regle l = r
	si est_vide(l) est VRAI alors
		nouvelleProposition(proposition)
		premisse(l) <- proposition
		suiv(l) <- NULL
	sinon
		tant que est_vide(l) est FAUX faire
			l <- suiv(l)
		fin tant que
		nouvelleProposition(proposition)
		conclusion(l) <- l
		l <- proposition
		suiv(l) <- conclusion 
	fin sinon
	retourner l
Fin
```

```pseudocode
creer_conclusion(Regle r, string conclusion) : Regle
Debut
Regle l = r
	si est_vide(l) est VRAI alors
		conclusion est NULL
	sinon
		tant que est_vide(suiv(l)) est FAUX faire
			l <- suiv(l)
		fin tant que
		nouvelleConclusion(conclusion)
		suiv(l) <- conclusion
Fin
```

```pseudocode
est_proposition(Regle r, string proposition) : Booléen
	*/ Algorithme récursif */
Debut
	si est_vide(r) est VRAI alors
		retourner FAUX
	sinon
	si element_tete(r) = proposition
		retourner VRAI
	fin si
	retourner est_proposition(element_queue(r), proposition)
fin 
```

```pseudocode
retirer_proposition(Regle r, string proposition) : Regle
Debut
c = 0
Regle l =r
	si est_vide(l) est VRAI alors
		retourner l 
	sinon
		si est_proposition(l) est FAUX alors
			retourner l 
		sinon
			tant que est_vide(suiv(l)) est FAUX et l != proposition faire
				l <- suiv(l)
				c = c + 1
			fin tant que
			tant que est_vide(l) est FAUX faire 
				pour i allant de c a comptage_val(l) faire
					l = suiv(l)
				fin pour
			fin tant que
		fin si 
	fin si 
	retourner l 
Fin 
```

```pseudocode
est_vide_premisse(Regle r) : Booléen
Debut
	si est_vide(r) est VRAI alors
		retourner VRAI
	sinon 
		si est_vide(suiv(r)) est VRAI alors
			retourner VRAI
		sinon
		retourner FAUX
		fin si
	fin si
Fin 
```

```pseudocode
acces_tete_premisse(Regle r) : string
Debut
	si est_vide(r) est VRAI alors
		retourner NULL
	sinon
		si est_vide(suiv(r)) est VRAI alors
			retourner NULL
		sinon
			retourner r
		fin si
	fin si
fin
```

```pseudocode
acces_conclusion(Regle r) : string
Debut
	si est_vide(r) est VRAI alors
		retourner NULL
	sinon
		tant que est_vide(suiv(r)) est FAUX faire
			r <- suiv(r)
		fin tant que
		retourner r
	fin si
fin 
```