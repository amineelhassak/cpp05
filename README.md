# cpp_module2
cpp 
# Gestion des Exceptions en C++

Une **exception** en programmation est un mécanisme qui permet de gérer des erreurs ou des situations exceptionnelles qui peuvent survenir pendant l'exécution d'un programme. Quand une erreur se produit, une "exception" est "lancée" (ou "déclenchée") pour indiquer qu'un problème s'est produit.

## Pourquoi utiliser des exceptions ?

Les exceptions permettent de séparer le code qui traite les erreurs du code principal, rendant ainsi le programme plus clair et plus facile à maintenir. Elles évitent aussi de devoir vérifier manuellement les erreurs après chaque opération, ce qui simplifie la logique du code.

## Types d'exceptions

Il existe plusieurs types d'exceptions, par exemple :

- **Exceptions standards** : comme `std::out_of_range`, `std::invalid_argument`, ou `std::runtime_error` en C++, qui couvrent des erreurs courantes comme l'accès à un index hors limites d'un tableau ou la transmission d'un argument invalide à une fonction.
- **Exceptions définies par l'utilisateur** : vous pouvez créer vos propres types d'exceptions pour gérer des situations spécifiques à votre application.

## Mécanisme de gestion des exceptions

En C++, le mécanisme des exceptions repose sur trois mots-clés principaux :

- **`try`** : le bloc `try` contient le code susceptible de générer une exception.
- **`throw`** : une exception est "lancée" avec l'instruction `throw` lorsqu'une situation d'erreur est détectée.
- **`catch`** : le bloc `catch` permet de "rattraper" et de traiter l'exception lancée.

## Exemple en C++

Voici un exemple simple en C++ pour illustrer l'utilisation des exceptions :

```cpp
#include <iostream>
#include <stdexcept> // pour les exceptions standard

int division(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Erreur : division par zéro !"); // Lance une exception
    }
    return a / b;
}

int main() {
    try {
        int resultat = division(10, 0); // Ceci va lancer une exception
        std::cout << "Résultat : " << resultat << std::endl;
    } catch (const std::invalid_argument& e) { // Rattrape l'exception
        std::cerr << "Exception capturée : " << e.what() << std::endl;
    }

    return 0;
}
```
