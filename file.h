#ifndef FILE_H
#define FILE_H
#include <QFile>
#include <QTextStream>
#include <stdio.h>
#include <vector>
void saveToCSVFile(const std::vector<int>& yValues, const std::vector<int>& y1Values, const QString& filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite)){
        if(!file.isOpen()){
            perror("File Open Fail");
            return;
        }
        QTextStream in(&file);
        QString firstLine;
        if(!in.atEnd()){
            firstLine=in.readLine();
        }
        if(!firstLine.isEmpty()&&firstLine.trimmed()=='y,y1'){
            file.seek(file.size());//移动文件指针到末尾
        }else{
            file.resize(0);
            QTextStream out(&file);
            out<<"y,y1\n";
            for(int i=0;i<yValues.size();i++){
                out<<yValues[i]<<","<<y1Values[i]<<"\n";
            }
            file.close();
            return;
        }

        QTextStream out(&file);
        for(int i=0;i<yValues.size();i++){
                out<<yValues[i]<<","<<y1Values[i]<<"\n";
        }
        file.close();
    }
    else{
        perror("File Open Fail");
    }
}
#endif // FILE_H
