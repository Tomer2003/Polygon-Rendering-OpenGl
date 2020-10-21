#include "VertexAttribute.hpp"

VertexAttribute::VertexAttribute() : m_stride(0), m_layoutNumCounter(0) {}

void VertexAttribute::bindLayout(unsigned int layoutNum) const{
    glEnableVertexAttribArray(layoutNum);
}

void VertexAttribute::unBindLayout(unsigned int layoutNum) const{
    glDisableVertexAttribArray(layoutNum);
}

std::vector<VertexLayout> VertexAttribute::getLayouts() const{
    return m_layouts;
}

unsigned int VertexAttribute::getLayoutConter() const{
    return m_layoutNumCounter;
}

unsigned int VertexAttribute::getStride() const{
    return m_stride;
}