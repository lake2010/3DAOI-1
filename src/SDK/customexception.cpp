#include "customexception.hpp"

using namespace SDK;

CustomException::CustomException()
{
    // 成员变量初始化
    this->m_originalMsg = "";
}

CustomException::CustomException( std::string& message )
{
    this->m_originalMsg = message;
}

CustomException::~CustomException()
{

}
