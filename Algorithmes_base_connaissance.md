## Données :
Base de connaissance : liste de règle.

## Algorithmes :
```pseudocode
créerBaseVide(BC new_basis)
Debut 
    new_basis <- new(BC)
    retourner new_basis
Fin
```

```pseudocode
ajouterRegleBase(BC knowledge_basis, Regle r)
Debut
    si knowledge_basis est NULL alors
        knowledge_basis = r
    sinon
        tant que knowledge_basis != NULL
            knowledge_basis <- suiv(knowledge_basis)
        fin tant que
        suiv(knowledge_basis) = r
    fin  si 
Fin
```

```pseudocode
headValueBasis(BC konwledge_basis)
Debut
    return valeur_tete(knowledge_basis)
Fin
```
