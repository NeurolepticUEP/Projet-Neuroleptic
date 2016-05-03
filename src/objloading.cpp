#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "objloading.h"

struct vec3
{
    float x;
    float y;
    float z;
};

struct Mtl
{
    std::string name;
    vec3 diffuse;
};

Mesh *loadObjFile(const char* file_name)
{
    std::string obj_name(file_name),
            mtl_name,
            line,
            word,
            face1,
            face2,
            face3;

    float X, Y, Z;

    unsigned int    material_num,
            index_num = 0,      //  Nombre d'indices
            vertices_num = 0,   //  Nombre de vertices
            normals_num = 0;    //  Nombre de normales

    bool    library_exists = false;

    Mtl *materials;


    /*
     *  Fichier .obj
     */
    std::ifstream obj_file(obj_name.c_str());

    if(!(obj_file))
    {
        std::cerr << "Problème lors de la lecture du fichier .obj" << std::endl;
        exit(1);
    }

    //  On ne tient pas compte des éventuels commentaires en début de fichier
    do
    {
        std::getline(obj_file, line);
    }
    while(line[0] == '#');

    //  Récupération du nom du fichier .mtl
    std::istringstream iss(line);
    if(iss >> word >> mtl_name)
    {
        //  .mtl présent
        if(!std::strcmp(word.c_str(), "mtllib"))
            library_exists = true;
    }

    //  Comptage des vertices, normales et faces
    while(std::getline(obj_file, line))
    {
        if(line[0] == 'v')  //  Vertex
        {
            if(line[1] == ' ')
                ++vertices_num;
            else if(line[1] == 'n') //  Normale
                ++normals_num;
        }
        else if(line[0] == 'f') //  Face
            index_num += 3;
    }
    obj_file.close();
    if(!library_exists) //  Si pas de .mtl
    {
        //  Allocation tableau de matériaux
        materials = new Mtl[1];
        //  Matériau par défaut
        Mtl m;
        m.diffuse.x = 1;
        m.diffuse.y = 1;
        m.diffuse.z = 1;
        materials[0] = m;

        material_num = 1;
    }
    else
    {
        /*
         *  Lecture du .mtl
         */
        std::ifstream mtl_file(mtl_name.c_str());

        if(!(mtl_file))
        {
            std::cerr << "Problème lors de la lecture du fichier .mtl" << std::endl;
            exit(1);
        }

        for(int index_mat = -1; mtl_file;)
        {
            mtl_file >> word;

            //  Nouveau matériau
            if(!std::strcmp(word.c_str(), "newmtl"))
            {
                std::string mat_name;
                mtl_file >> mat_name;

                Mtl m;
                m.name = mat_name;
                materials[++index_mat] = m;
            }

            //  Récupération de la couleur diffuse
            else if(!std::strcmp(word.c_str(), "Kd"))
            {
                float component;
                mtl_file >> component;
                materials[index_mat].diffuse.x = component;
                mtl_file >> component;
                materials[index_mat].diffuse.y = component;
                mtl_file >> component;
                materials[index_mat].diffuse.z = component;
            }
            else if(!std::strcmp(word.c_str(), "#"))
            {
                mtl_file >> word;
                if(!std::strcmp(word.c_str(), "Material"))
                {
                    mtl_file >> word;           // Count:
                    mtl_file >> material_num;   // Nombre de materiaux
                    materials = new Mtl[material_num];
                }
            }
        }
        mtl_file.close();
    }

    /*
     *  Allocation des tableau de données
     * */
    vec3    *vertices = new vec3[vertices_num],
            *normals = new vec3[normals_num],
            *tab_normals = new vec3[vertices_num],
            *colors = new vec3[vertices_num];
    unsigned int  *indices = new unsigned int[index_num];

    /*
     *  Indices associés
     * */
    unsigned int    index_vertices = 0,
                    index_normals = 0,
                    index_indices = 0;

    /*
     *  On relance la lecture du .obj pour récupérer les données
     */
    obj_file.open(obj_name.c_str());

    if(!(obj_file))
    {
        std::cerr << "Problème lors de la lecture du fichier .obj" << std::endl;
        exit(1);
    }

    for(unsigned int current_mat = 0; std::getline(obj_file, line);)
    {
        std::istringstream iss(line);

        if(iss >> word >> X >> Y >> Z)
        {
            //  Vertex
            if(!strcmp(word.c_str(), "v"))
            {
                vec3 vertex;
                vertex.x = X;
                vertex.y = Y;
                vertex.z = Z;
                vertices[index_vertices++] = vertex;
            }
            //  Normale
            else if(!strcmp(word.c_str(), "vn"))
            {
                vec3 normal;
                normal.x = X;
                normal.y = Y;
                normal.z = Z;
                normals[index_normals++] = normal;
            }
        }
        else
        {
            //  On recommence sur les faces
            iss.clear();
            iss.str(line);
            if(iss >> word >> face1 >> face2 >> face3)
            {
                //  Si ce n'est pas un commentaire
                if(strcmp(word.c_str(), "#"))
                {
                    //  Indices + Normales
                    unsigned int index = atoi(face1.substr(0, face1.find("/")).c_str()) - 1;//Coordonnées de vertex
                    indices[index_indices++] = index;
                    colors[index] = materials[current_mat].diffuse;
                    face1 = face1.substr(face1.find("/") + 1);//Coordonnées de texture
                    face1 = face1.substr(face1.find("/") + 1);//Normale
                    unsigned int index_normal = atoi(face1.c_str()) - 1;
                    tab_normals[index] = normals[index_normal];

                    index = atoi(face2.substr(0, face2.find("/")).c_str()) - 1;//Coordonnées de vertex
                    indices[index_indices++] = index;
                    colors[index] = materials[current_mat].diffuse;
                    face2 = face2.substr(face2.find("/") + 1);//Coordonnées de texture
                    face2 = face2.substr(face2.find("/") + 1);//Normale
                    index_normal = atoi(face2.c_str()) - 1;
                    tab_normals[index] = normals[index_normal];

                    index = atoi(face3.substr(0, face3.find("/")).c_str()) - 1;//Coordonnées de vertex
                    indices[index_indices++] = index;
                    colors[index] = materials[current_mat].diffuse;
                    face3 = face3.substr(face3.find("/") + 1);//Coordonnées de texture
                    face3 = face3.substr(face3.find("/") + 1);//Normale
                    index_normal = atoi(face3.c_str()) - 1;
                    tab_normals[index] = normals[index_normal];
                }
            }
            else
            {
                iss.clear();
                iss.str(line);
                if(iss >> word >> mtl_name)
                {
                    //  Utilisation d'un matériau
                    if(!strcmp(word.c_str(), "usemtl"))
                    {
                        for(current_mat = 0; current_mat < material_num; ++current_mat)
                            if(!strcmp(mtl_name.c_str(), materials[current_mat].name.c_str()))
                                break;
                        if(current_mat >= material_num)
                            --current_mat;
                    }
                }
            }
        }
    }
    obj_file.close();

    //  Tableaux de sortie
    float out_vertices[vertices_num * 9];

    //  Remplissage du tableau des données
    for(unsigned int i = 0, j = 0; i < vertices_num * 9; i += 9, ++j)
    {
        //  Vertex
        out_vertices[i] = vertices[j].x;
        out_vertices[i + 1] = vertices[j].y;
        out_vertices[i + 2] = vertices[j].z;

        //  Normale
        out_vertices[i + 3] = tab_normals[j].x;
        out_vertices[i + 4] = tab_normals[j].y;
        out_vertices[i + 5] = tab_normals[j].z;

        //  Couleur diffuse
        out_vertices[i + 6] = colors[j].x;
        out_vertices[i + 7] = colors[j].y;
        out_vertices[i + 8] = colors[j].z;
    }

    std::string out_name = obj_name.substr(0, obj_name.size() - 4);

    /*delete []materials;
    delete []vertices;
    delete []normals;
    delete []tab_normals;
    delete []colors;*/

    return new Mesh(out_name, out_vertices, indices, vertices_num * 9, index_num);
}
