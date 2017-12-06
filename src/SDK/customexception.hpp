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
     *                  继承标准异常类exception,用于捕获异常，输出异常信息
     *  @author   plato
     *  @version  1.00 2017-11-22 plato
     *                 note:create it
     */
    class CustomException: public std::exception
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   CustomException: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        CustomException();

        /*
        *  @brief   CustomException: 构造函数
        *  @param   message: 捕获到的信息
        *  @return  N/A
        */
        CustomException( std::string& message );

        /*
        *  @brief   ~CustomException: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        virtual ~CustomException();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        /*
        *  @brief   originalMsg: 原始的信息
        *  @param   N/A
        *  @return  原始的信息
        */
        const std::string originalMsg() const
        {
            return this->m_originalMsg;
        }

        /*
        *  @brief   what: 重写的what()函数，自定义异常信息
        *  @param   N/A
        *  @return  自定义的异常信息
        */
        virtual const char* what() const _GLIBCXX_USE_NOEXCEPT override
        {
            return m_originalMsg.data();
        }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        std::string m_originalMsg;  // 原始的信息
    };
}//End of namespace SDK

#endif // CUSTOMEXCEPTION_HPP
