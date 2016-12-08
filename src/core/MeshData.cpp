//
// Created by montgomery anderson on 8/12/16.
//

#include "core/MeshData.h"


void MeshData::addQuad(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3) {
    vertices.push_back(v0);
    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);

    int n = vertices.size(0);
    elements.push_back(n - 4);
    elements.push_back(n - 3);
    elements.push_back(n - 2);
    elements.push_back(n - 1);
}


void MeshData::addTriangle(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2) {

}


void MeshData::clear() {

}