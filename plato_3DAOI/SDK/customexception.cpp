#include "customexception.hpp"

using namespace SDK;

//CustomException::CustomException()
//{

//}

CustomException::CustomException(std::string &message)
{
    this->m_originalMsg = message;
}

//CustomException::~CustomException()
//{

//}
