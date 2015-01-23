/**
 *  @file lib_ini.h
 *  @brief fichier ent�te du source lib_ini.c
 *  @author Beaulande Laurent
 *  @date   Juin 2006
 *
 */

#ifndef __LIB_INI_H__
#define __LIB_INI_H__

#define INI_BUFFER_LENGTH	1024  ///< Nombre de caract�res pour un buffer representant le nombre de caractere possible d'une ligne du fichier
#define CARAC_COMMENTAIRE		'#' ///< Caract�re correspondant au commentaire d'une ligne
#define CARAC_DEBUT_SECTION		'[' ///< Caract�re de debut d'une section
#define CARAC_FIN_SECTION		']' ///< Caract�re de fin d'une section
#define CARAC_PARAM_VALUE		'=' ///< Caract�re s�parant un param�tre de sa valeur
/**
 *  Chaine de caract�re qui s�pare le param�tre de sa valeur\n
 *  La difference avec 'CARAC_PARAM_VALUE', STRING_PARAM_VALUE est utilis� pour strtok;\n
 *  alors que 'CARAC_PARAM_VALUE' est utilis� pour strchr
 */
#define STRING_PARAM_VALUE		"="

/*
 * definition des valeurs de retour possible
 */
#define INI_SUCCESS												 0 ///< Succes du process
#define INI_OPEN_FAILED										-1 ///< impossible d'ouvrir le fichier de parametres
#define INI_PROBLEM_MEMORY									-2 ///< erreur lors d'une allocation memoire
#define INI_IS_EMPTY											-3 ///< la liste des sections/parametres en memoire est vide
#define INI_SECTION_NOT_FOUND							-4 ///< la section demandee n'a pas ete trouvee


/**
 * Liste des noms des param�tres se trouvant dans une section
 */
typedef struct{
	short iNbParametre; ///< Nombre de param�tre
	char **pTabParam; ///< Tableau de poiteur sur le nom du param�tre
}stTabParam;

/**
 * Pre declaration de la structure des param�tres pour la d�claration d'un pointeur sur la structure suivante
 */
typedef struct stParamsValues * pstParamsValues;

/**
 * Pre declaration de la structure d'une section pour la d�claration d'un pointeur sur la structure suivante
 */
typedef struct UneSection * pstSection;

/**
 * Donn�es d'un fichier de configuration
 */
typedef struct{
	short iNbSection; ///< nombre de section
	pstSection pstSections; ///< Liste des sections, pointe sur la premi�re section
	pstSection pstSectionsDerniere; ///< Liste des sections, pointe sur la derniere section
}stIni;

///< charge en memoirer le fichier ini	
short ChargerFichierIni(char *szNomFichier);
/* recherche la valeur d'un parametre dans une section
 * la section peut valoir NULL si le parametre n'appartient a aucune section
 */
char *rechercherValeur(char *szSection,char *szParam);
///< nombre de section du fichier ini, y compris la section NULL (parametres sans section)
int nbrSection();
///< nombre de parametres d'une section, y compris la section NULL (parametres sans section)
int nbrParametres(char *szSection);
///< donne la liste des parametres se trouvant dans une section
stTabParam* TrouverParametres(char *szSection);
///< affiche a l'ecran les parametres et leur section
void Dump();
void ReleaseIni();

#endif
