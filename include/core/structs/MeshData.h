//
// Created by montgomery anderson on 8/12/16.
//

#ifndef NINE_MESHDATA_H
#define NINE_MESHDATA_H


class MeshData {
public:
    std::vector <glm::vec3> vertices;

    std::vector <GLushort> elements;

    std::vector <glm::vec3> normals;

    MeshData();

    ~MeshData();

    void addQuad(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);

    void addTriangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2);

    void clear();

protected:
private:
};


#endif //NINE_MESHDATA_H
