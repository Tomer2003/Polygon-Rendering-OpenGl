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
    VertexAttribute();

    void bindLayout(unsigned int layoutNum) const;
    void unBindLayout(unsigned int layoutNum) const;

    template <class Type>
    void addLayout(int size) {
    }

    template <>
    void addLayout<float>(int size){
        m_layouts.push_back({m_layoutNumCounter, size, GL_FLOAT, GL_FALSE});
        m_layoutNumCounter++;
        m_stride += sizeof(float) * size;
    }

    template <>
    void addLayout<int>(int size){
        m_layouts.push_back({m_layoutNumCounter, size, GL_INT, GL_FALSE});
        m_layoutNumCounter++;
        m_stride += sizeof(int) * size;
    }

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