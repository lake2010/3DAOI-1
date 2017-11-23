#include "measuredobj.hpp"

using namespace Job;

MeasuredObj::MeasuredObj()
{
    // 成员变量初始化
    this->m_name = "";
    this->m_pNextMeasuredObj = nullptr;
    this->m_pPreMeasuredObj = nullptr;
}

MeasuredObj::~MeasuredObj()
{

}
