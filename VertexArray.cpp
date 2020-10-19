#include "VertexArray.hpp"
#include "error_handle.hpp"

VertexArray::VertexArray(){
    GLCALL(glGenVertexArrays(1, &m_RenderID));
}

VertexArray::~VertexArray(){
    GLCALL(glDeleteVertexArrays(1, &m_RenderID));
}

void VertexArray::bind() const{
    GLCALL(glBindVertexArray(m_RenderID));
}

void VertexArray::unBind() const{
    GLCALL(glBindVertexArray(m_RenderID));
}

void VertexArray::addBufferAndAttribute(const VertexBuffer& vertexBuffer, const VertexAttribute& vertexAttribute) const{
    std::vector<VertexLayout> layouts = vertexAttribute.getLayouts();
    glBindVertexArray(m_RenderID);
    vertexBuffer.bind();
    unsigned int layoutNum = 0;
    unsigned int offset = 0;
    for(VertexLayout vertexLayout : layouts){
        vertexAttribute.bindLayout(layoutNum);
        GLCALL(glVertexAttribPointer(layoutNum, vertexLayout.size, vertexLayout.type, vertexLayout.normalized, vertexAttribute.getStride(), reinterpret_cast<const void*>(offset)));
        layoutNum++;
        offset += getSizeOfType(vertexLayout.type) * vertexLayout.size;
    }
}