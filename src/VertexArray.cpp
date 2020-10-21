#include "VertexArray.hpp"

VertexArray::VertexArray(){
    glGenVertexArrays(1, &m_RenderID);
}

VertexArray::~VertexArray(){
    glDeleteVertexArrays(1, &m_RenderID);
}

void VertexArray::bind() const{
    glBindVertexArray(m_RenderID);
}

void VertexArray::unBind() const{
    glBindVertexArray(m_RenderID);
}

void VertexArray::addBufferAndAttribute(const VertexBuffer& vertexBuffer, const VertexAttribute& vertexAttribute) const{
    std::vector<VertexLayout> layouts = vertexAttribute.getLayouts();
    glBindVertexArray(m_RenderID);
    vertexBuffer.bind();
    unsigned int layoutNum = 0;
    unsigned int offset = 0;
    for(VertexLayout vertexLayout : layouts){
        vertexAttribute.bindLayout(layoutNum);
        glVertexAttribPointer(layoutNum, vertexLayout.size, vertexLayout.type, vertexLayout.normalized, vertexAttribute.getStride(), reinterpret_cast<const void*>(offset));
        layoutNum++;
        offset += getSizeOfType(vertexLayout.type) * vertexLayout.size;
    }
}