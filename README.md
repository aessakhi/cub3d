# cub3d

Etapes:
- Parsing du fichier, verification que le fichier se termine bien par cub, que le fichier existe (Besoin d'ajouter verif que le fichier n'est pas un directory)
- Recuperation de l'integralite du contenu dans un tableau 2D.
- Parsing de ce tableau a 2D, check si les elements sont dans l'ordre et sont soit des maps, soit des params (textures, couleurs), verif qu'il y a bien un element de chaque, verif que la map n'est pas separee par des espaces.
- Verif des textures et des couleurs (Un seul param? Les fichiers existent? Couleur dans le bon format?)
- Verif de la map. Pour rester consistant, je remplace les tabulations par des espaces. Je verifie que la map est terminee en "remplissant" l'exterieur de la map avec des 'O'. Pour chacun de ces 'O', je verifie ensuite qu'aucun n'est en contact avec des espaces. Si c'est le cas, la map est consideree comme fermee. Les 'O' seront remplaces par des '1' (Mur), les espaces a l'interieur de la map par des '0' (Sol).
- Partie raycasting est la partie la plus simple. Check https://lodev.org/cgtutor/raycasting.html 
- Deplacement ok 25/09
- Texture ok 29/09
- Sol/Plafond ok 30/09
- Orientation ok 30/09
- Flags done 3/10
- Manque norme et dernieres verifs
