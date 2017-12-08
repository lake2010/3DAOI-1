#include "datagenerator.hpp"

using namespace App;
using namespace Job;
using namespace SDK;

DataGenerator::DataGenerator()
{

}

DataGenerator::~DataGenerator()
{

}

void DataGenerator::generateData( InspectionData& inspectionData,
                                  MeasuredObj obj[] )
{
    // 通过传入的被测物数组对象参数，设置被测对象名称、本体信息（矩形的长宽、坐标）
    char objName[10];
    for ( int i = 0; i < OBJ_CNT; ++i )
    {
        if ( i < CHIP_CNT )
        {
            sprintf( objName, "chip_%02d", i + 1 );
        }
        else
        {
            sprintf( objName, "ic_%02d", ( i - (int)CHIP_CNT ) + 1 );
        }
        obj[i].setName( objName );

        // 创建矩形对象，设置矩形的长宽、坐标
        Rectangle body( DataHelper::generateRandomNum(),
                        DataHelper::generateRandomNum(),
                        DataHelper::generateRandomNum(),
                        DataHelper::generateRandomNum() );
        obj[i].setBody( body );
    }

    // 创建列表对象，在添加指定数量的被测对象
    MeasuredObjList list;
    for ( int i = 0; i < OBJ_CNT; ++i )
    {
        list.pushTail( obj[i] );
    }

    // 创建基板对象，设置基板名称、大小、原点位置、被测对象列表
    Board board;
    board.setName( "iphoneX" );
    board.setSizeX( DataHelper::generateRandomNum() );
    board.setSizeY( DataHelper::generateRandomNum() );
    board.setOriginalX( DataHelper::generateRandomNum() );
    board.setOriginalY( DataHelper::generateRandomNum() );
    board.setMeasureObjs( list );

    // 通过传入的检测数据对象参数，设置版本信息、上次程式编辑时间、基板信息
    inspectionData.setVersion( "V1" );
    inspectionData.setLastEditingTime( DataHelper::generateTime() );
    inspectionData.setBoard( board );
}
