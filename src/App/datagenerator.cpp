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

void DataGenerator::generateData()
{

    MeasuredObj obj[50];
    char objName[10];
    int cnt = 50;
    for ( int i = 0; i < cnt; ++i )
    {
        if ( i < 20 )
        {
            sprintf( objName, "chip_%02d", i + 1 );
        }
        else
        {
            sprintf( objName, "ic_%02d", ( i - 20 ) + 1 );
        }
        obj[i].setName( objName );

        Rectangle body( DataHelper::generateRandomNum(),
                        DataHelper::generateRandomNum(),
                        DataHelper::generateRandomNum(),
                        DataHelper::generateRandomNum() );
        obj[i].setBody( body );
    }

    MeasuredObjList list;
    for ( int i = 0; i < cnt; ++i )
    {
        list.pushTail( obj[i] );
    }
    list.print();

    Board board;
    board.setName( "iphoneX" );
    board.setSizeX( DataHelper::generateRandomNum() );
    board.setSizeY( DataHelper::generateRandomNum() );
    board.setOriginalX( DataHelper::generateRandomNum() );
    board.setOriginalY( DataHelper::generateRandomNum() );
    board.setMeasureObjs( list );

    InspectionData inspectionData;
    inspectionData.setVersion( "V1" );
    inspectionData.setLastEditingTime( DataHelper::generateTime() );
    inspectionData.setBoard( board );

    inspectionData.writeToXml( "../data/V1.xml" );

}
