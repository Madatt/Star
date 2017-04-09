#include <iostream>
#include <memory>
#include <string.h>
#include <stdio.h>
#include "headers/files_io.h"


int main()
{
    files_io::Node* parent;
    parent=files_io::ReadFile("test.dat");
    parent->AddChildNode("ultra",files_io::NodeType::SHORT_ARRAY);
    short* arr=new short[5];
    arr[0]=1235;
    arr[1]=21435;
    arr[2]=4435;
    arr[3]=3345;
    arr[4]=435;
    parent->GetChildNode("ultra")->SetShortArrayData(arr,5);

    files_io::WriteFile("test2.dat",parent);
    delete parent;
    return 0;
}
