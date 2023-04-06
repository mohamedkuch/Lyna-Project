#include <stdio.h>
#include <dirent.h>
#include <string.h>

char liste_de_recette[100][100];
int num_recettes = 0;

void lire_fichier_type(char nom[])
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

void Afficher_recette_list_par_type(int type)
{
    memset(liste_de_recette, 0, sizeof(liste_de_recette));
    char *token, *saveptr;
    int recette_type;
    char name[100];
    char recette_string[100];

    DIR *dir;
    struct dirent *ent;
    char path[100] = "recettes/";

    printf("Quel nom de recette cherchez-vous ? \n");
    
    if ((dir = opendir(path)) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_type == DT_REG && strstr(ent->d_name, ".txt"))
            {
                // extract the name
                token = strtok_r(ent->d_name, "_", &saveptr);
                token = strtok_r(NULL, "_", &saveptr);
                strcpy(name, token);

                // extract the type
                token = strtok_r(NULL, "_", &saveptr);
                sscanf(token, "%d", &recette_type);

                // combine recette_type and name into a single string example : 1_buratta
                sprintf(recette_string, "%d_%s", recette_type, name);

                if (type == recette_type)
                {
                    strcpy(liste_de_recette[num_recettes], recette_string);
                    num_recettes++;

                    printf("%d.%s\n", num_recettes, name);
                }
            }
        }
        closedir(dir);
    }
}

void Afficher_recette_par_type(int type, int num)
{

    // print out the array
    for (int i = 0; i < num_recettes; i++)
    {
        printf("%s\n", liste_de_recette[i]);
    }

    if (type == 1)
    {
        if (num == 1)
        {
            /*Afficher le fichier recette de buratta*/
            // lire_fichier_type("recettes/recette_buratta.txt");
        }
        if (num == 2)
        {
            /*Afficher le fichier recette de risotto*/
        }
        if (num == 3)
        {
            /*Afficher le fichier recette de linguine*/
        }
    }

    if (type == 2)
    {
        if (num == 1)
        {
            /*Afficher le fichier recette 1*/
        }
        if (num == 2)
        {
            /*Afficher le fichier recette 2*/
        }
        if (num == 3)
        {
            /*Afficher le fichier recette 3*/
        }
    }

    if (type == 3)
    {
        if (num == 1)
        {
            /*Afficher le fichier recette 1*/
        }
        if (num == 2)
        {
            /*Afficher le fichier recette 2*/
        }
        if (num == 3)
        {
            /*Afficher le fichier recette 3*/
        }
    }
}
