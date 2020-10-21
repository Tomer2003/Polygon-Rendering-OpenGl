#pragma once
#include "../src/VertexArray.hpp"
#include "../src/VertexBuffer.hpp"
#include "../src/VertexAttribute.hpp"
#include "../src/shader.hpp"
#include "../src/IndexBuffer.hpp"
#include <math.h>

class Polygon{
private:
    VertexBuffer* m_VertexBuffer;
    VertexAttribute* m_VertexAttribute;
    VertexArray* m_VertexArray;
    IndexBuffer* m_IndexBuffer;
    Shader* m_Shader;

public:
    /**
     * @brief Construct a new Polygon object
     * 
     */
    Polygon();
    /**
     * @brief Destroy the Polygon object
     * 
     */
    ~Polygon();
    
    /**
     * @brief The function define and bind polygon for drawing with glDrawElements
     * 
     * @param edges - number of edges of polygon
     * @param v1 - R
     * @param v2 - G
     * @param v3 - B
     * @param v4 - A
     */
    void bindPolygon(unsigned int edges, float v1, float v2, float v3, float v4);
};