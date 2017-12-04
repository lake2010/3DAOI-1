#include "measuredobj.hpp"

using namespace Job;

MeasuredObj::MeasuredObj()
{
    // 成员变量初始化
    this->m_name = "";
    this->m_pNextObj = nullptr;
    this->m_pPreObj = nullptr;
}

MeasuredObj::~MeasuredObj()
{

}
