#pragma once
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexAttribute.hpp"
#include "shader.hpp"
#include "IndexBuffer.hpp"
#include <math.h>

class Polygon{
private:
    VertexBuffer* m_VertexBuffer;
    VertexAttribute* m_VertexAttribute;
    VertexArray* m_VertexArray;
    IndexBuffer* m_IndexBuffer;
    Shader* m_Shader;

public:
    Polygon();
    ~Polygon();
    
    void definePolygon(unsigned int edges);
};


