#include "ObjLoader.h"

Ponto ObjLoader::getVertice(string s) {
    float x, y, z;
    sscanf(s.c_str(), "v %f %f %f", &x, &y, &z);
    Ponto result(x, y, z);
    return result;
}

Ponto ObjLoader::getNormal(string s) {
    float x, y, z;
    sscanf(s.c_str(), "vn %f %f %f", &x, &y, &z);
    Ponto result(x, y, z);
    return result;
}

face ObjLoader::getFace(Poligono tipo, string s) {
    int vt;
    int v1, v2, v3, v4;
    int n1, n2, n3, n4;

    if(tipo == Poligono::TRIANG){
        v4 = -1, n4 = -1;
        sscanf(s.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &v1, &vt, &n1, &v2, &vt, &n2, &v3, &vt, &n3);
    } else if(tipo == Poligono::QUAD){
        sscanf(s.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &v1, &vt, &n1, &v2, &vt, &n2, &v3, &vt, &n3, &v4, &vt, &n4);
    }

    face result(tipo, v1, v2, v3, v4, n1, n2, n3, n4);
    return result;
}

void ObjLoader::loadObj(unsigned& id, const char* file) {
    vector<Ponto> vertices;
    vector<Ponto> normals;
    vector<face> faces;

    fstream arq(file);
    string line = "";

    if(!arq.is_open()) {
        cout << "Erro ao abrir o arquivo: " << file << "\n";
    }

    while (getline(arq, line)) {
        if(line.find("v ") != string::npos) {
            Ponto tmpVertice = getVertice(line);
            vertices.push_back(tmpVertice);
        } else if(line.find("vn ") != string::npos) {
            Ponto tmpNormal = getNormal(line);
            normals.push_back(tmpNormal);
        } else if(line.find("f ") != string::npos) {
            short nSpace = 0;
            for (char c : line)
                if(c == ' ') nSpace++;
            Poligono tipo_ = (Poligono)nSpace;
            face tmpFace = getFace(tipo_, line);
            faces.push_back(tmpFace);
        }
    }

    // id = glGenLists(1);

    // glNewList(id, GL_COMPILE);
    glPolygonMode(GL_FRONT, GL_FILL);
    glColor3f(0.04f, 0.6f, 0.0f);
    for (int i = 0; i < faces.size(); i++) {
        int v1 = faces[i].vertice[0] - 1; int v2 = faces[i].vertice[1] - 1;
        int v3 = faces[i].vertice[2] - 1; int v4 = faces[i].vertice[3] - 1;
        int n1 = faces[i].normal[0] - 1; int n2 = faces[i].normal[1] - 1;
        int n3 = faces[i].normal[2] - 1; int n4 = faces[i].normal[3] - 1;
        if (faces[i].poligono == Poligono::TRIANG) {
            glBegin(GL_TRIANGLES);
                glNormal3fv(normals[n1].getCoord());
                glVertex3fv(vertices[v1].getCoord());
                glNormal3fv(normals[n2].getCoord());
                glVertex3fv(vertices[v2].getCoord());
                glNormal3fv(normals[n3].getCoord());
                glVertex3fv(vertices[v3].getCoord());
            glEnd();
        } else if(faces[i].poligono == Poligono::QUAD) {
            glBegin(GL_QUADS);
                glNormal3fv(normals[n1].getCoord());glVertex3fv(vertices[v1].getCoord());
                glNormal3fv(normals[n2].getCoord());glVertex3fv(vertices[v2].getCoord());
                glNormal3fv(normals[n3].getCoord());glVertex3fv(vertices[v3].getCoord());
                glNormal3fv(normals[n4].getCoord());glVertex3fv(vertices[v4].getCoord());
            glEnd();
        }
    }
    

}