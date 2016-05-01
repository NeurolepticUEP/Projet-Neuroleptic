#include "data_class/graphic/mesh.h"

/*
 *	Chargement d'un fichier .obj
 *	Et récupération des couleurs diffuse dans un .mtl associé
 *	Entrée:
 *	Nom du fichier exemple : "PIK.obj"
 *	Sortie:
 *	Mesh créé avec les données
 */
Mesh* loadObjFile(const char* file_name);
