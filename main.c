#include <stdio.h>
#include <string.h>
#include <math.h>

// Structure de la date
struct Date {
    int Jour, Mois, Annee;
};

// Structure des informations
struct Infos {
    char Nom[50], Prenom[50], Telephone[50], Reference[10];
    int Age;
    int Statut;
    struct Date date_rdv;
};
const char statut_s[4][10] = {"Valide", "Reporte", "Annule", "Traite"};


// Données initialisées par défaut
void Reservations_Initialisees(struct Infos r[]) {
    for (int i = 0; i < 10; i++) {
        sprintf(r[i].Reference, "%d", i + 1);
        sprintf(r[i].Nom, "Nom: %d", i + 1);
        sprintf(r[i].Prenom, "Prenom %d", i + 1);
        sprintf(r[i].Telephone, "0674386%03d", i + 1);
        r[i].Age = 10 + i * 4;
        r[i].Statut = (i % 4) + 1;
        r[i].date_rdv.Jour = (i % 31) + 1;
        r[i].date_rdv.Mois = (i % 12) + 1;
        r[i].date_rdv.Annee = 2021 + (i % 4);
    }
}

// Ajouter une réservation
void Ajouter_Reservation(struct Infos r[], int Total_resa) {
    int i = Total_resa;
    sprintf(r[i].Reference, "%d", i + 1);
    printf("Reference de la reservation: %s\n", r[i].Reference);
    printf("Veuillez inserer le nom du patient: ");
    scanf("%49s", r[i].Nom);
    printf("Veuillez inserer le prenom du patient: ");
    scanf("%49s", r[i].Prenom);
    printf("Veuillez inserer le telephone du patient: ");
    scanf("%49s", r[i].Telephone);
    printf("Veuillez inserer l'age du patient: ");
    scanf("%d", &r[i].Age);
    printf("Veuillez inserer le statut de la reservation:\n");
    printf("1/. Valide.\n");
    printf("2/. Reporte.\n");
    printf("3/. Annule.\n");
    printf("4/. Traite.\n");
    printf("Veuillez saisir votre choix : ");
    scanf("%d", &r[i].Statut);
    printf("Veuillez inserer la date de reservation (jj/mm/aaaa): ");
    scanf("%d/%d/%d", &r[i].date_rdv.Jour, &r[i].date_rdv.Mois, &r[i].date_rdv.Annee);
    printf("\n");
}

// Modifier une réservation
void Modifier_Reservation(struct Infos r[], int Total_resa) {
    char Reference[10];
    int Trouve = 0;
    printf("Veuillez inserer la reference de la reservation a modifier: ");
    scanf("%9s", Reference);
    for (int i = 0; i < Total_resa; i++) {
        if (strcmp(r[i].Reference, Reference) == 0) {
            //Proposé par un tiers
            printf("Nom actuel: %s\n", r[i].Nom);
            printf("Entrez le nouveau nom: ");
            scanf("%49s", r[i].Nom);

            printf("Prenom actuel: %s\n", r[i].Prenom);
            printf("Entrez le nouveau prenom: ");
            scanf("%49s", r[i].Prenom);

            printf("Telephone actuel: %s\n", r[i].Telephone);
            printf("Entrez le nouveau telephone: ");
            scanf("%49s", r[i].Telephone);

            printf("Age actuel: %d\n", r[i].Age);
            printf("Entrez le nouvel age: ");
            scanf("%d", &r[i].Age);

            printf("Statut actuel: %s\n", statut_s[r[i].Statut - 1]);
            printf("Entrez le nouveau statut (1: Valide, 2: Reporte, 3: Annule, 4: Traite): ");
            scanf("%d", &r[i].Statut);

            printf("Date actuelle: %02d/%02d/%04d\n", r[i].date_rdv.Jour, r[i].date_rdv.Mois, r[i].date_rdv.Annee);
            printf("Entrez la nouvelle date (jj/mm/aaaa): ");
            scanf("%d/%d/%d", &r[i].date_rdv.Jour, &r[i].date_rdv.Mois, &r[i].date_rdv.Annee);

            printf("Reservation modifiee.\n");
            Trouve = 1;
            break;
        }
    }
    if (Trouve == 0) {
        printf("Reservation non trouvee.\n");
    }
}

// Supprimer une réservation
int Supprimer_Reservation(struct Infos r[], int Total_resa) {
    char Reference[10];
    int Trouve = 0;
    printf("Veuillez inserer la reference de la reservation a supprimer: ");
    scanf("%9s", Reference);
    for (int i = 0; i < Total_resa; i++) {
        if (strcmp(r[i].Reference, Reference) == 0) {
            for (int j = i; j < Total_resa - 1; j++) {
                r[j] = r[j + 1];
            }
            Total_resa--;
            printf("Reservation supprimee.\n");
            Trouve = 1;
            break;
        }
    }
    if (Trouve == 0) {
        printf("Reservation non trouvee.\n");
    }
    return Total_resa;
}

// Afficher les détails d'une réservation
void Afficher_Reservation(struct Infos r[], int Total_resa) {
    for (int i = 0; i < Total_resa; i++) {
        printf("Reference:%s\n", r[i].Reference);
        printf("%s\n", r[i].Nom);
        printf("%s\n", r[i].Prenom);
        printf("Telephone: %s\n", r[i].Telephone);
        printf("Age: %d\n", r[i].Age);
        printf("Statut: %s\n", statut_s[r[i].Statut - 1]);
        printf("Date de reservation: %d/%d/%d\n", r[i].date_rdv.Jour, r[i].date_rdv.Mois, r[i].date_rdv.Annee);
        printf("\n");
    }
}

// Tri des réservations par nom
void Tri_Resa_Nom(struct Infos r[], int Total_resa) {
    struct Infos cpt;
    for (int i = 0; i < Total_resa - 1; i++) {
        for (int j = i + 1; j < Total_resa; j++) {
            if (strcmp(r[i].Nom, r[j].Nom) > 0) {
                cpt = r[i];
                r[i] = r[j];
                r[j] = cpt;
            }
        }
    }
    printf("Reservations triees par nom.\n");
}

// Tri des réservations par statut
void Tri_Resa_Statut(struct Infos r[], int Total_resa) {
    struct Infos cpt;
    for (int i = 0; i < Total_resa - 1; i++) {
        for (int j = i + 1; j < Total_resa; j++) {
            if (r[i].Statut > r[j].Statut) {
                cpt = r[i];
                r[i] = r[j];
                r[j] = cpt;
            }
        }
    }
    printf("Reservations triees par statut.\n");
}

// Rechercher une réservation par référence unique
void Recherche_Resa_Ref(struct Infos r[], int Total_resa) {
    char Reference[10];
    int Trouve = 0;
    printf("Veuillez inserer la reference de la reservation que vous cherchez: ");
    scanf("%9s", Reference);
    for (int i = 0; i < Total_resa; i++) {
        if (strcmp(r[i].Reference, Reference) == 0) {
            printf("Reference: %s\n", r[i].Reference);
            printf("Nom: %s\n", r[i].Nom);
            printf("Prenom: %s\n", r[i].Prenom);
            printf("Telephone: %s\n", r[i].Telephone);
            printf("Age: %d\n", r[i].Age);
            printf("Statut: %s\n", statut_s[r[i].Statut - 1]);
            printf("Date: %d/%d/%d\n", r[i].date_rdv.Jour, r[i].date_rdv.Mois, r[i].date_rdv.Annee);
            Trouve = 1;
            break;
        }
    }
    if (Trouve == 0) {
        printf("Reservation non trouvee.\n");
    }
}

// Rechercher une réservation par nom
void Recherche_Resa_Nom(struct Infos r[], int Total_resa) {
    char Nom[50];
    int Trouve = 0;
    printf("Veuillez inserer le nom de la reservation que vous cherchez: ");
    scanf("%49s", Nom);
    for (int i = 0; i < Total_resa; i++) {
        if (strcmp(r[i].Nom, Nom) == 0) {
            printf("Reference: %s\n", r[i].Reference);
            printf("Nom: %s\n", r[i].Nom);
            printf("Prenom: %s\n", r[i].Prenom);
            printf("Telephone: %s\n", r[i].Telephone);
            printf("Age: %d\n", r[i].Age);
            printf("Statut: %s\n", statut_s[r[i].Statut - 1]);
            printf("Date: %d/%d/%d\n", r[i].date_rdv.Jour, r[i].date_rdv.Mois, r[i].date_rdv.Annee);
            Trouve = 1;
        }
    }
    if (Trouve == 0) {
        printf("Reservation non trouvee.\n");
    }
}

// Statistiques
// Calculer la moyenne d'âge des patients ayant réservé
float Calcule_Moyenne_Age(struct Infos r[], int Total_resa) {
    int total_age = 0;
    for (int i = 0; i < Total_resa; i++) {
        total_age += r[i].Age;
    }
    float moyenne = (float)total_age / Total_resa;
    return (int)ceil(moyenne);
}

// Afficher le nombre de patients par tranche d'âge
void Compte_Patients_Age(struct Infos r[], int Total_resa) {
    int age_0_18 = 0, age_19_35 = 0, age_36_plus = 0;
    for (int i = 0; i < Total_resa; i++) {
        int age = r[i].Age;
        if (age >= 0 && age <= 18) {
            age_0_18++;
        } else if (age >= 19 && age <= 35) {
            age_19_35++;
        } else if (age >= 36) {
            age_36_plus++;
        }
    }
    printf("Nombre de patients 0-18 ans: %d\n", age_0_18);
    printf("Nombre de patients 19-35 ans: %d\n", age_19_35);
    printf("Nombre de patients 36+ ans: %d\n", age_36_plus);
}

// Générer des statistiques pour connaître le nombre total de réservations par statut
void Compte_Resa_Statut(struct Infos r[], int Total_resa) {
    int valide = 0, reporte = 0, annule = 0, traite = 0;
    for (int i = 0; i < Total_resa; i++) {
        switch (r[i].Statut) {
            case 1:
                valide++;
                break;
            case 2:
                reporte++;
                break;
            case 3:
                annule++;
                break;
            case 4:
                traite++;
                break;
            default:
                break;
        }
    }
    printf("Nombre de reservations validees: %d\n", valide);
    printf("Nombre de reservations reportees: %d\n", reporte);
    printf("Nombre de reservations annulees: %d\n", annule);
    printf("Nombre de reservations traitees: %d\n", traite);
}

int main() {
    struct Infos r[100];
    int Total_resa = 10;
    int Choix;
/*Proposé par un tiers*/
    int Sous_choix;
    Reservations_Initialisees(r);

    do {
        printf("\tRendez_vous Dentiste\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier une reservation\n");
        printf("3. Supprimer une reservation\n");
        printf("4. Afficher les details une reservation\n");
        printf("5. Tri des reservations\n");
        printf("6. Recherche des reservations\n");
        printf("7. Statistiques\n");
        printf("0. Quitter\n\n");

        printf("Choisissez votre option: ");
        scanf("%d", &Choix);
        printf("\n\n");

        switch (Choix) {
            case 1:
                Ajouter_Reservation(r, Total_resa);
                Total_resa++;
                break;
            case 2:
                Modifier_Reservation(r, Total_resa);
                break;
            case 3:
                Total_resa = Supprimer_Reservation(r, Total_resa);
                break;
            case 4:
                Afficher_Reservation(r, Total_resa);
                break;
            case 5:
                printf("1. Tri par nom\n");
                printf("2. Tri par statut\n");
                printf("Veuillez saisir votre choix: ");
                scanf("%d", &Sous_choix);
                if (Sous_choix == 1) {
                    Tri_Resa_Nom(r, Total_resa);
                } else if (Sous_choix == 2) {
                    Tri_Resa_Statut(r, Total_resa);
                }
                break;
            case 6:
                printf("1. Recherche par reference\n");
                printf("2. Recherche par nom\n");
                printf("Veuillez saisir votre choix: ");
                scanf("%d", &Sous_choix);
                if (Sous_choix == 1) {
                    Recherche_Resa_Ref(r, Total_resa);
                } else if (Sous_choix == 2) {
                    Recherche_Resa_Nom(r, Total_resa);
                }
                break;
            case 7:
                do {
                    printf("\tStatistiques\n");
                    printf("1. Moyenne d'age des patients\n");
                    printf("2. Compte des patients par tranche d'age\n");
                    printf("3. Compte des reservations par statut\n");
                    printf("4. Retour au menu principal\n\n");

                    printf("Veuillez choisir une option de statistiques: ");
                    scanf("%d", &Sous_choix);
                    printf("\n");

                    switch (Sous_choix) {
                        case 1:
                            printf("Moyenne d'age des patients: %d\n\n", Calcule_Moyenne_Age(r, Total_resa));
                        break;
                        case 2:
                            Compte_Patients_Age(r, Total_resa);
                        printf("\n");
                        break;
                        case 3:
                            Compte_Resa_Statut(r, Total_resa);
                        printf("\n");
                        break;
                        case 4:
                                break;
                        default:
                            printf("Choix invalide. Veuillez sélectionner une option valide.\n\n");
                        break;
                    }
                } while (Sous_choix != 4);
            break;
            case 0:
                printf("Au revoir !\n");
            break;
            default:
                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
            break;
        }
    } while (Choix != 0);

    return 0;
}