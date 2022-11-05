# minishell
*a 42 project*


Il s'agit de bash avec beaucoup moins de fonctionalite !

Il fonctionne avec les pipe (|), les redirections ( '<' '<<' '>' '>>' ) ainsi que les variable d'environement !

*nb : il se peut que selon votre version de readline le shell agissent de facon bizzare*

**Built-in** :

cd : change directory -> changer de repertoir courant

echo : ecrit dans le terminal les arguments (prend en charge l'option -n pour enlever le retour a la ligne)

pwd : affiche le repertoire courant

exit : sortir du shell

export : ajoute une variable a l'environement

unset : enleve une variable d'environement

env : ecrit l'ensemble des variable d'environement ayant une valeur dans le terminal
