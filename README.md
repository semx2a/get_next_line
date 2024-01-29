# Get Next Line

## Résumé
Ce projet a pour objectif de développer la fonction `get_next_line`, capable de lire des lignes avec une taille de buffer limite depuis un descripteur de fichier. Ce projet est écrit en C.

## Contenu du Répertoire Git

- `get_next_line.h`: Fichier d'en-tête contenant le prototype de la fonction `get_next_line`.
- `get_next_line.c`: Implémentation de la fonction principale.
- `get_next_line_utils.c`: Fichier utilitaire contenant des fonctions supplémentaires nécessaires à la réalisation de `get_next_line`.

## Compétences Acquises

### Programmation en C

- Développement d'une fonction complexe en langage C.
- Respect de la norme C de `l'école 42 `pour assurer la qualité et la lisibilité du code.
- Gestion robuste des comportements indéfinis et des cas d'erreurs.

### Compilation et Makefile

- Création d'un Makefile pour automatiser la compilation du projet.
- Utilisation des flags `-Wall`, `-Wextra`, et `-Werror`.
- Utilisation des flags -g3, -fsanitize=address pour le débogage

### Gestion fine de la Mémoire

- Allocation dynamique de mémoire avec `malloc`.  
- Libération de mémoire une fois les opérations terminées, ou en cas d'erreur pour éviter les fuites.
- Utilisation de `valgrind` pour vérifier les fuites de mémoire résiduelles.

### Gestion des chaînes de caractères

- Lecture et enregistrement de chaînes de caractères.
- Parsing de la chaîne de caractères pour vérifier la fin d'une ligne définit par un retour à la ligne `\n` ou une fin de fichier `EOF`.
- Réutilisation du fd pour lire le fichier ligne par ligne une fois que la fonction est rappelée et retourne le reste de la ligne précédente si un retour à la ligne est trouvé.

### Variables Statiques

- Définition d'un BUFFER_SIZE en amont de la compilation pour définir une taille de buffer constante
- Utilisation d'une variable statique pour stocker le reste de la ligne précédente si un retour à la ligne est trouvé.

### Gestion de Fichiers

- Lecture de lignes depuis un descripteur de fichier.
- Gestion des différentes situations, telles que la fin de fichier ou les erreurs de lecture.
- Gestion de plusieurs descripteurs de fichiers avec un tableau de strings constantes.