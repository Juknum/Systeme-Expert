## Données:
Règle : structure composée d'une liste de chaîne de caractères nommée prémisse et d'une autre chaîne de caractère nommée conclusion.

## Algorithmes:

```pseudocode
Fonction créer_règle
Données : pas de données
Résultat : Regle nouvelleRegle
Debut
	nouvelleRegle <- new(regle)
	retourner nouvelleRegle
Fin
```

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

```pseudocode
Fonction retirer_proposition
Données : Premisse p
		  string proposition
Résultat : Premisse p
Debut
	si est_vide_premisse(p) est VRAI alors
		retourner indéfini
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

```pseudocode
Fonction acces_tete_premisse
Données : Premisse p
Résultat : proposition en tête de prémisse (string)
Debut
	si est_vide(p) est VRAI alors
		retourner indéfini
	sinon
		retourner contenu(p)
	fin si
fin
```

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
