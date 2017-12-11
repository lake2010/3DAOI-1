#include "rectangle.hpp"

using namespace SDK;

Rectangle::Rectangle()
{
    // 所有成员变量初始化为0
    this->m_posX = 0;
    this->m_posY = 0;
    this->m_width = 0;
    this->m_height = 0;
    this->m_angle = 0;
}

Rectangle::Rectangle( double posX, double posY, double width, double height )
{
    this->m_posX = posX;
    this->m_posY = posY;
    this->m_width = width;
    this->m_height = height;
}

Rectangle::~Rectangle()
{

}
