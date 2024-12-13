//
//  vertex.cpp
//  weightedgraph13.cpp
//
//  Created by Jovhems Jean-Baptiste on 12/12/24.
//

#include "vertex.h"

Vertex::Vertex(string name)
{
    m_title = name;
}

string Vertex::getTitle()
{
    return m_title;
}

void Vertex::setTitle(string name)
{
    m_title = name;
}
