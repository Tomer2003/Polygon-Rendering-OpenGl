#pragma once
#include "Resources/GLEW/include/GL/glew.h"
#include <vector>

typedef struct VertexLayout{
    GLuint layoutNum;
    GLint size;
    GLenum type;
    GLboolean normalized;
} VertexLayout;


class VertexAttribute{
private:
    std::vector<VertexLayout> m_layouts;
    unsigned int m_stride;
    unsigned int m_layoutNumCounter;
public:
    /**
     * @brief Construct a new Vertex Attribute object
     * 
     */
    VertexAttribute();

    /**
     * @brief The function bind spesific layout
     * 
     * @param layoutNum - layout ID
     */
    void bindLayout(unsigned int layoutNum) const;
    /**
     * @brief The function unbind spesific layout
     * 
     * @param layoutNum - layout ID
     */
    void unBindLayout(unsigned int layoutNum) const;

    /**
     * @brief The function add layout to attribute
     * 
     * @tparam Type - specifies the data type of each component in the array
     * @param size - specifies the number of components per generic vertex attribute 
     */
    template <class Type>
    void addLayout(int size) {
    }

    /**
     * @brief The function add layout to attribute
     * 
     * @tparam Type - specifies that float is the data type of each component in the array
     * @param size - specifies the number of components per generic vertex attribute 
     */
    template <>
    void addLayout<float>(int size){
        m_layouts.push_back({m_layoutNumCounter, size, GL_FLOAT, GL_FALSE});
        m_layoutNumCounter++;
        m_stride += sizeof(float) * size;
    }

    /**
     * @brief The function add layout to attribute
     * 
     * @tparam Type - specifies that int is the data type of each component in the array
     * @param size - specifies the number of components per generic vertex attribute 
     */
    template <>
    void addLayout<int>(int size){
        m_layouts.push_back({m_layoutNumCounter, size, GL_INT, GL_FALSE});
        m_layoutNumCounter++;
        m_stride += sizeof(int) * size;
    }

    /**
     * @brief The function add layout to attribute
     * 
     * @tparam Type - specifies that unsigned int is the data type of each component in the array
     * @param size - specifies the number of components per generic vertex attribute 
     */
    template <>
    void addLayout<unsigned int>(int size){
        m_layouts.push_back({m_layoutNumCounter, size, GL_UNSIGNED_INT, GL_FALSE});
        m_layoutNumCounter++;
        m_stride += sizeof(unsigned int) * size;
    }

    std::vector<VertexLayout> getLayouts() const;
    unsigned int getStride() const;
    unsigned int getLayoutConter() const;
};