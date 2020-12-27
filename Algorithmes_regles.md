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
est_vide_regle(Regle r) : Booléen
Debut
	si r est NULL
		retourner VRAI
	sinon
		retourner FAUX
	fin si
Fin
```

```pseudocode
est_vide_premisse(Premisse p) : Booléen
Debut
	si p est NULL alors
		retourner VRAI
	sinon 
		retourner FAUX
	fin si
Fin 
```

```pseudocode
est_vide_conclusion(Regle r) : Booléen
Debut
	si conclusion(r) est NULL alors
		retourner VRAI
	sinon 
		retourner FAUX
	fin si
Fin 
```

```pseudocode
ajouter_proposition(Regle r, string proposition) : Regle
Debut
	si est_vide_regle(r) est VRAI alors
		nouvelleProposition(proposition)
		premisse(r) <- proposition
		suiv(premisse(r)) <- NULL
	sinon si est_proposition(premisse(r), proposition) est FAUX alors
		Regle l = r
			tant que est_vide_premisse(suiv(l)) est FAUX faire
				l <- suiv(l)
			fin tant que
			nouvelleProposition(proposition)
			contenu(nouvProposition) <- proposition
			suiv(nouvProposition) = NULL
			suiv(l) <- nouvProposition
	sinon
		retourner ERREUR
	fin si
	retourner l
Fin
```

```pseudocode
creer_conclusion(Regle r, string proposition) : Regle
Debut
Regle l = r
	si est_vide(l) est VRAI alors
		conclusion est NULL
	sinon
		conclusion(l) <- proposition
Fin
```

```pseudocode
est_proposition(Premisse p, string proposition) : Booléen
	*/ Algorithme récursif */
Debut
	si est_vide_premisse(p) est VRAI alors
		retourner FAUX
	sinon
		si contenu(p) = proposition
			retourner VRAI
		fin si
	fin si
	retourner est_proposition(suiv(p), proposition)
fin 
```

```pseudocode
retirer_proposition(Premisse p, string proposition) : Regle
Debut
	si est_vide_premisse(p) est VRAI alors
		retourner NULL
	sinon si contenu(p) = proposition alors
		si est_vide_premisse(suiv(p)) est VRAI alors
			retourner NULL
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

```pseudocode
acces_tete_premisse(Premisse p) : string
Debut
	si est_vide(p) est VRAI alors
		retourner NULL
	sinon
		retourner contenu(p)
	fin si
fin
```

```pseudocode
acces_conclusion(Regle r) : string
Debut
	si est_vide(r) est VRAI alors
		retourner NULL
	sinon si est_vide_conlcusion(r) est VRAI alors
		retourner NULL
	sinon
		retourner conclusion(r)
	fin si
fin 
```
