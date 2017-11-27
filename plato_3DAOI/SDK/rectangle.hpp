#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


namespace SDK
{
    /**
     *  @brief    Rectangle
     *            设置并记录被测目标的坐标、大小、角度
     *  @author   plato
     *  @version  1.00 2017-11-22 plato
     *                 note:create it
     */
    class Rectangle
    {
    public:        
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   Rectangle:  构造函数
        *  @param   N/A
        *  @return  N/A
        */
        Rectangle();

        /*
        *  @brief   ~Rectangle: 析构函数
        *           用于释放内存
        *  @param   N/A
        *  @return  N/A
        */
        ~Rectangle();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //访存函数

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //1 posX
        /*
        *  @brief   posX:    X坐标
        *  @param   N/A
        *  @return  传入的X坐标
        */
        double posX() { return this->m_posX; }

        /*
        *  @brief   setPosX: 设置X坐标
        *  @param   posX:    传入的X坐标
        *  @return  N/A
        */
        void setPosX( double posX ) { this->m_posX = posX; }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //2 posY
        /*
        *  @brief   posY:    Y坐标
        *  @param   N/A
        *  @return  传入的Y坐标
        */
        double posY() { return this->m_posY; }

        /*
        *  @brief   setPosY: 设置Y坐标
        *  @param   posY:    传入的Y坐标
        *  @return  N/A
        */
        void setPosY( double posY ) { this->m_posY = posY; }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //3 width
        /*
        *  @brief   width:    宽度
        *  @param   N/A
        *  @return  传入的宽度
        */
        double width() { return this->m_width; }

        /*
        *  @brief   setWidth: 设置宽度
        *  @param   width:    传入的宽度
        *  @return  N/A
        */
        void setWidth( double width ) { this->m_width = width; }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //4 height
        /*
        *  @brief   height:    高度
        *  @param   N/A
        *  @return  传入的宽度
        */
        double height() { return this->m_height; }

        /*
        *  @brief   setHeight: 设置高度
        *  @param   height:    传入的高度
        *  @return  N/A
        */
        void setHeight( double height ) { this->m_height = height; }

        //>>>-------------------------------------------------------------------------------------------------------------------------------------
        //5 angle
        /*
        *  @brief   angle:    角度
        *  @param   N/A
        *  @return  传入的角度
        */
        double angle() { return this->m_angle; }

        /*
        *  @brief   setAngle: 设置角度
        *  @param   angle:    传入的角度
        *  @return  N/A
        */
        void setAngle( double angle ) { this->m_angle = angle; }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        double m_posX;          // 被测目标的X坐标
        double m_posY;          // 被测目标的Y坐标
        double m_width;         // 被测目标的宽度
        double m_height;        // 被测目标的高度
        double m_angle;         // 被测目标的角度
    };
}//End of namespace SDK

#endif // RECTANGLE_HPP
