#include "polygon_api.hpp"
# define M_PI 3.14159265358979323846
#include <iostream>

Polygon::Polygon() : m_IndexBuffer(nullptr), m_VertexBuffer(nullptr){
    m_VertexArray = new VertexArray;
    m_VertexAttribute = new VertexAttribute;
    m_Shader = new Shader("../../Resources/shaders/vertex.shader", "../../Resources/shaders/fragment.shader");
    m_Shader->bind();
    m_Shader->setUniform4f("colors", 0.4f, 0.2f, 0.7f, 1.0f);
}


void Polygon::definePolygon(unsigned int edgeNum) {
    float* buffer = new float[(edgeNum + 1) * 2];
    unsigned int* indexBufferData = new unsigned int[edgeNum * 3];

    buffer[0] = 0.0;
    buffer[1] = 0.0;
    for(unsigned int edge = 0; edge < edgeNum; ++edge){
        buffer[2 * (edge + 1)] =  cos((float)(2 * M_PI/ edgeNum) * edge);
        buffer[2 * (edge + 1) + 1] = sin((float)(2 * M_PI/ edgeNum) * edge);
    }

    for(unsigned int edge = 0; edge < edgeNum - 1; ++edge){
        indexBufferData[3 * edge] = 0;
        indexBufferData[3 * edge + 1] = edge + 1;
        indexBufferData[3 * edge + 2] = edge + 2;
    }
    indexBufferData[3 * (edgeNum - 1)] = 0;
    indexBufferData[3 * (edgeNum - 1) + 1] = 1;
    indexBufferData[3 * (edgeNum - 1) + 2] = edgeNum;


    m_VertexBuffer = new VertexBuffer(buffer, (edgeNum + 1) * 2 * sizeof(float));
    m_VertexBuffer->bind();

    m_VertexAttribute->addLayout<float>(2);

    m_VertexArray->addBufferAndAttribute(*m_VertexBuffer, *m_VertexAttribute);

    m_IndexBuffer = new IndexBuffer(indexBufferData, edgeNum * 3 * sizeof(unsigned int));
    m_IndexBuffer->bind();

    delete buffer;
    delete indexBufferData;
}

Polygon::~Polygon(){
    delete m_VertexBuffer;
    delete m_VertexAttribute;
    delete m_VertexArray;
    delete m_IndexBuffer;
    delete m_Shader; 
}