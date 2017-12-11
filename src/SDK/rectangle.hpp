#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

namespace SDK
{
    /**
     *  @brief    Rectangle
     *                  设置矩形的坐标、大小、角度
     *  @author   plato
     *  @version  2.00 2017-11-22 plato
     *                 note:done it
     */
    class Rectangle
    {
    public:
        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //constructor & destructor

        /*
        *  @brief   Rectangle: 构造函数
        *  @param   N/A
        *  @return  N/A
        */
        Rectangle();

        /*
        *  @brief   Rectangle: 构造函数
        *  @param   posX: 矩形的X坐标
        *           posY: 矩形的Y坐标
        *           width: 矩形的宽度
        *           height: 矩形的高度
        *  @return  N/A
        */
        Rectangle( double posX, double posY, double width, double height );

        /*
        *  @brief   ~Rectangle: 析构函数
        *  @param   N/A
        *  @return  N/A
        */
        ~Rectangle();

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


        //>>>----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //get & set functions

        double posX() { return this->m_posX; }
        void setPosX( double posX ) { this->m_posX = posX; }

        double posY() { return this->m_posY; }
        void setPosY( double posY ) { this->m_posY = posY; }

        double width() { return this->m_width; }
        void setWidth( double width ) { this->m_width = width; }

        double height() { return this->m_height; }
        void setHeight( double height ) { this->m_height = height; }

        double angle() { return this->m_angle; }
        void setAngle( double angle ) { this->m_angle = angle; }

        //<<<----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    private:
        double m_posX;      // 矩形的X坐标
        double m_posY;      // 矩形的Y坐标
        double m_width;     // 矩形的宽度
        double m_height;    // 矩形的高度
        double m_angle;     // 矩形的角度
    };
}//End of namespace SDK

#endif // RECTANGLE_HPP
