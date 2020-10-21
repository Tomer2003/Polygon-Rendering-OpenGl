#include "IndexBuffer.hpp"

IndexBuffer::IndexBuffer(const void* buffer, unsigned int bufferSize) : m_size(bufferSize) {
    glGenBuffers(1, &m_RenderID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, buffer, GL_STREAM_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::~IndexBuffer(){
    glDeleteBuffers(1, &m_RenderID);
}

void IndexBuffer::bind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID);
}

void IndexBuffer::unBind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::getBufferSize() const{
    return m_size;
}