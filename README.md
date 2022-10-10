# cub3d

Etapes:
- Parsing du fichier, vérification que le fichier se termine bien par cub, que le fichier existe, que le .cub n'est pas un directory
- Recuperation de l'integralité du contenu dans un tableau à 2D.
- Parsing de ce tableau à 2D, check si les éléments sont dans l'ordre et sont soit des maps, soit des params (textures, couleurs), vérif qu'il y a bien un element de chaque, vérif que la map n'est pas séparée par des espaces.
- Vérif des textures et des couleurs (Un seul param? Les fichiers existent? Couleur dans le bon format?)
- Vérif de la map. Pour rester consistant, je remplace les tabulations par des espaces. Je vérifie que la map est bien fermée en "remplissant" l'extérieur de la map avec des 'O'. Pour chacun de ces 'O', je vérifie ensuite qu'aucun n'est en contact avec des '0' ou des caractères correspondant aux joueurs. Si c'est le cas, la map est considerée comme fermée. Les 'O' seront remplaces par des '1' (Mur), les espaces a l'intérieur de la map par des '0' (Sol).
- Partie raycasting est la partie la plus simple. Check https://lodev.org/cgtutor/raycasting.html 
- Déplacement ok 25/09
- Texture ok 29/09
- Sol/Plafond ok 30/09
- Orientation ok 30/09
- Flags done 3/10

Premier rendu foiré: oubli du mouvement droite/gauche (my bad!) et prenait en compte inutilement l'ordre des textures (je pensais qu'il fallait que l'ordre soit NO/SO/WE/EA/F/C de façon strict mais la seule chose importante est que le map ne soit pas avant les textures/couleurs).
Corrigé le 06/10

Rendu le 10/10: Note finale 105%
