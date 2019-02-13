#include <iostream>

#include <ZType>
#include <ZVariant>


int main()
{
    zyxcba::ZVariant v{"1"},v1{"12"};
    std::cout<< (v!=v1);
//    v.addToMap(1,"Smile");

////    zyxcba::ZVariant v1;
////    v1.addToMap(1,v);

//    v1 = std::move(v);

//    std::cout<<"V: "<<v.isValid()<<std::endl;
//    //std::cout<<"V1: "<<v1.getString()<<std::endl;

//    for(auto it = v1.getIntegerVariantMap().cbegin(); it != v1.getIntegerVariantMap().cend(); ++it)
//    {
//        std::cout << it->second<<std::endl;
//    }

    //zyxcba::ZVariant v2 = v1;

//    v2 = std::move(v1);
//    std::cout<<v2.isValid()<<std::endl;
//    std::cout<<"v1 isValid:"<<v1.isValid()<<std::endl;
//    std::cout<<"v2 string:"<<v2.getLength()<<std::endl;

    //std::string k("S1");
    //zyxcba::ZVariant v1(k);
    //zyxcba::ZVariant v2(std::string("sadasd"));
    //zyxcba::ZVariant v3(zyxcba::ZVariant(1212));
    //v2.addToList(zyxcba::ZVariant(100));
    //v2.addToList(zyxcba::ZVariant(100));
    //v2 = v1;
    //std::cout << v2.variantTypeString() <<std::endl;
    //std::cout << v2.getString()<<std::endl;
    //    v.addToList(1001212);
    //    v.addToList(100);
    //    v.addToList(100);
    //    v.addToList(1001212);
    //    v.addToList(100);
    //    v.addToList(100);

    //qDebug() << v.getLength();

    //v.setValue(100);
    //v.addToMap(1,zyxcba::ZVariant(100));

    //qDebug() << v.isIntegerVariantMap();
    //    /qDebug() << v.getLength();


    return 0;
}
