#include <stdio.h>

void lire_fichier_mot_cle(char nom[])
{
    FILE *file;
    char line[200];

    file = fopen(nom, "r");

    if (file == NULL)
    {
        printf("Error: Unable to open file!");
    }

    while (fgets(line, 200, file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}

void Affiche_recette_par_mot_cle(char Mot_clé[])
{
}
