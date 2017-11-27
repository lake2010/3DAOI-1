#ifndef CUSTOMEXCEPTION_HPP
#define CUSTOMEXCEPTION_HPP

#include <sstream>

// 定义一个宏函数，用于传递异常信息
#define THROW_EXCEPTION(exMsg)\
{\
    std::ostringstream message;\
    message<<"File:"<<__FILE__<<"\n"\
           <<"Line:"<<__LINE__<<"\n"\
           <<"Func:"<<__FUNCTION__<<"\n"\
           <<"Detail:"<<exMsg<<"\n";\
    std::string msg = message.str();\
    throw SDK::CustomException(msg);\
}

namespace SDK
{
    /**
     *  @brief    CustomException
     *            继承标准异常类exception
     *  @author   plato
     *  @version  1.00 2017-11-22 plato
     *                 note:create it
     */
    class CustomException: public std::exception
    {
    public:

    //    CustomException();
        CustomException(std::string& message);
    //    virtual ~CustomException();

        const std::string originalMsg() const{return this->m_originalMsg;}

        virtual const char* what() const _GLIBCXX_USE_NOEXCEPT override
        {
            return m_originalMsg.data();
        }

    private:
        std::string m_originalMsg;
    };
}//End of namespace SDK

#endif // CUSTOMEXCEPTION_HPP
