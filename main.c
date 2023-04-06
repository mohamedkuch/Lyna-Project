#include <stdio.h>
#include <stdbool.h>

/*Fonction retour au menu*/ /* Gros problème sur la fonction retour au menu à régler*/
bool Retour_menu()
{
    char r = 'X';
    while ((r != 'O') & (r != 'N'))
    {
        printf("\nVoulez-vous continuer? 0/N\n");
        scanf(" %c", &r);
    };
    return r == 'N';
}

/*Fonction 1 */
void Afficher_recette_par_type(int type, int num);
void Afficher_recette_list_par_type(int type);

/*Fontion 2 */
void Affiche_recette_par_mot_cle(char Mot_clé[]);

/*Fonction 3*/
void Affiche_recette_par_budget(int budget)
{
    if (budget <= 10)
    {
        /*Afficher recette 1*/
    }
    if ((budget <= 20) && (budget >= 10))
    {
        /*Afficher recette 1 et 2*/
    }
    if ((budget >= 20) && (budget <= 40))
    {
        /*Afficher la recette 1,2 et 3*/
    }
    if (budget >= 50)
    {
        printf("Vous pouvez effectuer toutes les recettes disponibles\n");
        /*Afficher les recettes*/
    }
    if (budget < 10)
    {
        printf("Nous sommes désolé, il n'y a aucune recette possible selon votre budget\n");
    }
}

/*Fonction 4*/
void Ajt_fav(int numfav)
{

    if (numfav == 1)
    {
        /*Ajouter la recette 1 en favoris*/
    }
    if (numfav == 2)
    {
        /*Ajouter la recette 2 en favoris*/
    }
    if (numfav == 3)
    {
        /*Ajouter la recette 3 en favoris*/
    }
    if (numfav == 4)
    {
        /*Ajouter la recette 4 en favoris*/
    }
    if (numfav == 5)
    {
        /*Ajouter la recette 5 en favoris*/
    }
}

/*Fonction 5*/
void Affiche_fav()
{
    /*Afficher les recettes mises en favoris */
}

int main()
{
    char Mot_cle[20];
    int choix = -1, taille, num, type, budget, numfav;

    do
    {
        /* Présentation du menu principale*/
        printf("\n************ Livre de Cuisine Numérique ***********\n");
        printf("\t1.Liste des noms de recettes \n");
        printf("\t2.Liste tré par mots clés  \n");
        printf("\t3.Liste tré par budget\n");
        printf("\t4.Ajouter la recette en favoris\n");
        printf("\t5.Afficher les recettes en favoris\n");
        printf("\t6.Sauvegarder le noms de la recette \n");
        printf("\t7.Importer\n");
        printf("\t0.Quitter");
        printf("\n***************************************************\n");
        printf("\nEntrer votre choix : \n");
        scanf("%d", &choix);

        if (choix == 1)
        {
            bool is_retour_menu;
            do
            {
                printf("Quelle type de recette recherchez-vous ? \n"
                       "1.Recette gatronomique\n"
                       "2.Recette bon marché\n"
                       "3.Rectte de grand-mère\n");

                scanf("%d", &type);
            } while (type > 3);

            // if (type == 1)
            // {
            //     // printf("Quel nom de recette cherchez-vous ? \n"
            //     //        "1.Buratta aux agrumes\n"
            //     //        "2.Risotto à la truffe\n"
            //     //        "3.Linguine aux fruits de mer\n");

            //     Afficher_recette_list_par_type(1);
            //     is_retour_menu = Retour_menu();
            // }
            // if (type == 2)
            // {
            //     printf("Quel nom de recette cherchez-vous ? \n"
            //            "1.Spaghetti alla carbonara\n"
            //            "2.Pizza\n"
            //            "3.Polenta aux tomates\n");
            //     is_retour_menu = Retour_menu();
            // }
            // if (type == 3)
            // {
            //     printf("Quel nom de recette cherchez-vous ? \n"
            //            "1.Lasagne\n"
            //            "2.focaccia\n"
            //            "3.Gnocchis au pain vert\n");
            //     is_retour_menu = Retour_menu();
            // }

            Afficher_recette_list_par_type(type);
            is_retour_menu = Retour_menu();

            if (!is_retour_menu)
            {
                do
                {
                    printf("\nEntrer le numéro de la recette\n");
                    scanf("%d", &num);
                } while ((num < 1) & (num > 3));

                Afficher_recette_par_type(type, num);
            }
        }

        if (choix == 2)
        {
            printf("*******Entrer l'ingrédient principale de votre recette parmis cette liste: \n- tomate\n- crème\n- farine\n");
            scanf("%s", Mot_cle);
            Affiche_recette_par_mot_cle(Mot_cle);
            // Retour_menu();
        }
        if (choix == 3)
        {
            printf("Quel est votre budget ?\n");
            scanf("%d", &budget);
            Affiche_recette_par_budget(budget);
            // Retour_menu();
        }
        if (choix == 4)
        {
            printf("Voici la liste de toutes les recettes disponible\n");
            printf("1-..............\n2-............\n3........\n3-..........\n4-.............\n5-.............");
            do
            {
                printf("\nEnter le numéro de la recette que vous souhaiter inclure dans vos favoris.\n");
                scanf("%d", &numfav);
            } while ((numfav < 1) & (numfav > 5));
        }
        if (choix == 5)
        {
            Affiche_fav();
            //  Retour_menu();
        }
    } while (choix != 0);

    return 0;
}