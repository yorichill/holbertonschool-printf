# C - _printf

Master
By: Julien Barbier, co-founder & CEO
Projet: Écrire votre propre fonction _printf en C. Travaux en binôme.
Table des matières
1.
2.
3.
4.
5.
6.
7.
8.
9.
10.
11.
12.
13.
14.
Description
Objectifs pédagogiques
Prérequis & contraintes
Spécifications fonctionnelles
Installation & compilation
Utilisation
Exemples
Tests recommandés
Conventions de code
Workflow Git (suggestion pour 2 personnes)
Répartition des tâches (suggestion)
Checklist QA / livraison
Ressources utiles
Auteurs
1. Description
Ce projet a pour but d'implémenter une version simplifiée de la fonction printf :
•
•
•
Prototype attendu : int _printf(const char *format, ...);
Écrire une fonction qui écrit sur la sortie standard ( stdout ) et qui retourne le nombre de
caractères imprimés (sans le \0 final).
La fonction doit supporter un sous-ensemble de conversions (voir section 4).
Ce dépôt représente le travail du binôme. Respectez les règles de style, les limitations
d'outils et gardez le dépôt propre (pas de main.c à la racine).
2. Objectifs pédagogiques
•
•
•
•
Comprendre les varargs ( stdarg.h ) et l'API va_start, va_arg, va_end.
Gérer la mise en forme de sorties (conversion d'entiers, chaînes, caractères).
Travailler en binôme et organiser le travail via Git.
Respecter des contraintes de compilation strictes et des conventions de style (Betty).
3. Prérequis & contraintes
•
•
Environnement de compilation : Ubuntu 20.04 LTS, Options de compilation (utilisées par la correction) :
gcc.
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
•
•
•
•
•
•
•
Éditeurs autorisés : vi , vim , emacs .
Ne pas utiliser de variables globales.
Maximum 5 fonctions par fichier.
Tous les fichiers doivent se terminer par une nouvelle ligne.
Respecter la Betty style (utilisez betty-style.pl et betty-doc.pl ).
Un fichier main.h doit contenir toutes les prototypes et les protections d'inclusion (include
guards).
Ne pas mettre de main.c dans la racine (créez un dossier tests/ pour vos fichiers de test).
4. Spécifications fonctionnelles (obligatoires pour la version 0)
Vous devez implémenter _printf qui reconnaît au minimum les conversions suivantes : - %c —
caractère - %s — chaîne - %% — caractère pourcentage littéral
Simplifications autorisées : - Pas besoin de reproduire la gestion avancée du buffering de la libc. - Pas
besoin d'implémenter les flags (-
+
,
, , # , 0 ). - Pas besoin d'implémenter le champ de largeur
(field width). - Pas besoin d'implémenter la précision. - Pas besoin d'implémenter les modificateurs de
longueur (l, h, etc.).
Si vous choisissez d'implémenter des conversions additionnelles (ex. %d , %i , %u ,
%o , %x , %p ), documentez-les dans le README et fournissez des tests.
5. Installation & compilation
1.
Cloner le repo :
git clone <url_du_repo>
cd holbertonschool-printf
2.
Compiler (exemple) :
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c
3.
Exécuter votre binaire depuis tests/ si vous en avez un :
./tests/my_printf_test
6. Utilisation
•
•
•
Inclure : #include "main.h"
Appeler : _printf("Hello %s!\n", name);
La fonction doit écrire sur stdout et renvoyer le nombre de caractères écrits.
7. Exemples
Un fichier tests/main.c (exemple) peut contenir le test fourni par la correction
(affiche diverses conversions). N'oubliez pas de ne pas mettre votre main.c d'essai à la
racine du projet.
Extrait d'exemple d'utilisation (non poussé à la racine) :
_printf("Character:[%c]\n"
_printf("String:[%s]\n"
_printf("Percent:[%%]\n");
, 'H');
, "I am a string !");
8. Tests recommandés
•
•
•
•
•
Comparer le comportement de _printf et de printf sur les cas supportés.
Cas d'erreur : NULL pour %s (décidez d'un comportement — par exemple afficher (null)
comme la libc ou rien — documentez-le).
Chaînes vides, caractères nuls, très longues chaînes.
Mélanges de conversions dans une même chaîne.
Tests de comptage : vérifiez que la valeur de retour correspond au nombre de caractères
affichés.
9. Conventions de code
•
•
•
•
•
Respecter la Betty style.
Prototypes dans main.h.
Include guards dans tous les headers.
Pas plus de 5 fonctions par fichier.
Pas de variables globales.
10. Workflow Git (suggestion) — Les 4 branches
Pour organiser le travail en binôme, voici une stratégie simple et efficace utilisant 4 branches :
1.
2.
3.
4.
5.
6.
main
Branche protégée. Contient le code validé prêt à être livré.
develop
Branche d’intégration où toutes les fonctionnalités complètes sont mergées avant d’être
promues sur main .
feature/<initiales>-<nom>
Chaque développeur crée sa branche de fonctionnalité depuis develop . Exemple : feature/
TD-printf-basic ou feature/TH-string-fmt.
7.
8.
9.
Travailler localement, commits clairs, puis push et pull request vers develop.
tests
Branche dédiée aux tests automatisés et à la suite de tests. Permet d’isoler les modifications de
tests et d’éviter de polluer develop.
Flux recommandé : - Créer develop depuis main (si elle n'existe pas). - Chaque dev crée feature/
<initiales>-... depuis develop . - Ouvrir une PR (pull request) vers develop quand la feature
est prête. - Revue de code par l'autre membre — corriger, puis merger dans develop . - Quand
develop est stable et validé par QA, créer une PR vers main et tagger une release. - Utiliser tests
pour ajouter/mettre à jour la suite de tests ; merger tests dans develop quand les tests passent.
Commandes utiles :
# créer et basculer sur une feature branch
git checkout -b feature/TD-myfeature develop
# push de la feature vers remote
git push -u origin feature/TD-myfeature
# mettre à jour votre branche avec develop
git fetch origin
git checkout feature/TD-myfeature
git merge origin/develop
# ouvrir PR depuis l'interface GitHub vers develop
11. Répartition des tâches (suggestion pour un binôme)
But : clarté et responsabilité, éviter les conflits.
•
•
•
•
Dév A (ex: Thelyaan Dufrenoy)
Implémentation des conversions de base : %c , %s , %% .
Gestion des cas NULL pour %s .
Tests unitaires simples.
•
Dév B (ex: Thomas Haenel)
•
•
•
Mise en place de l'infrastructure _printf (parsing, appel de handlers).
Documentation, main.h , prototypes, make/test scripts.
Tests d'intégration et comparaison avec printf.
Travail commun : - Relecture de code (PRs), QA manuelle, validation finale sur develop puis main .
12. Checklist QA / livraison
•
•
•
[ ] Tous les fichiers compilent avec les flags exigés.
[ ] Pas de main.c dans la racine.
[ ] Respect de la Betty style (aucune erreur avec betty-style.pl ).
•
•
•
•
•
[ ] main.h présent avec include guards et prototypes.
[ ] Pas de variables globales.
[ ] Tests pour tous les cas requis et edge-cases.
[ ] Revue de code effectuée par le binôme.
[ ] QA manuelle demandée (conformément aux instructions du projet).
13. Ressources utiles
•
•
•
man printf ( man 3 printf ) — pour comprendre le comportement attendu.
man va_start, man va_arg, man va_end.
Flowcharts et bonnes pratiques de pair programming (liens fournis dans l'énoncé du projet).
14. Auteurs
•
•
•
Julien Barbier — co-founder & CEO (métadonnées)
Thelyaan Dufrenoy — Développeur
Thomas Haenel — Développeur
Rappel technique rapide : "%" et "\\" suivis d'un caractère
•
% suivi d'un caractère dans une chaîne de format (ex: "%s" , "%d" ) indique un spécificateur
de conversion pour _printf / printf . Exemple : %s → afficher une chaîne, %c → afficher
un caractère, %% → afficher un % littéral.
•
\ (antislash) suivi d'un caractère dans un littéral de chaîne en C est une séquence
d'échappement :
•
•
•
•
\n → saut de ligne (newline)
\t → tabulation
\\ → caractère \
\" → guillemet double dans une chaîne, etc.
Note : l'énoncé parlait de / mais, en C, le caractère d'échappement est \\ (backslash).
Le caractère / est simplement un slash et n'indique pas d'échappement.
Si tu veux, je peux : - Ajouter une liste de tests complète (fichier tests/test_suite.sh ), - Préparer
un template main.h , - Créer un exemple de feature branch et des instructions pas-à-pas pour la
PR.
Dis-moi ce que tu veux que j'ajoute/modifie et je le fais dans le README directement.
