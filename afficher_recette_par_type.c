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
    num_recettes = 0;

    char *token, *saveptr;
    int recette_type;
    char name[100];

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

                if (type == recette_type)
                {
                    strcpy(liste_de_recette[num_recettes], name);
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
    char recette[100];
    for (int i = 0; i < num_recettes; i++)
    {
        if (i == num)
        {
            strcpy(recette, liste_de_recette[i]);
            break;
        }
    }

    DIR *dir;
    struct dirent *ent;
    char path[100] = "recettes/";

    if ((dir = opendir(path)) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_type == DT_REG && strstr(ent->d_name, ".txt"))
            {
                char *result = strstr(ent->d_name, recette);

                if (result != NULL)
                {
                    char recette_path[100];
                    // combiner recettes/ avec nom de fichier de recette
                    sprintf(recette_path, "%s/%s", "recettes", ent->d_name);
                    lire_fichier_type(recette_path);
                }
            }
        }
        closedir(dir);
    }
}
