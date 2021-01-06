## Données :
Base de connaissance : liste de règle.

## Algorithmes :
```pseudocode
Fonction créerBaseVide
Données : pas de données
Résultat : BC new_basis
Debut 
    new_basis <- new(BC)
    retourner new_basis
Fin
```

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

```pseudocode
Fonction headValueBasis
Données : BC konwledge_basis
Résultat : variable de type Regle 
Debut
    return valeur_tete(knowledge_basis)
Fin
```
