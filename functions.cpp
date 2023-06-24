#include "functions.h"

QString parsing(QString inputString){

    qDebug() << inputString;
    QStringList inputString_list = inputString.split('&');
    qDebug() << inputString_list;
    QString NameOfFunc = inputString_list.front();
    inputString_list.pop_front();


    if (NameOfFunc == "start")
        return start(inputString_list.at(0));

    return 0;
}


QString start(QString input){
    return input + " ok";
}

