#include "../headers/files_io.h"
#include <iostream>
#include <fstream>
#include <string>



std::shared_ptr<files_io::Node> files_io::ReadFile(std::string fname)
{
    std::ifstream fil(fname, std::ios::binary);
    std::vector<char> content((std::istreambuf_iterator<char>(fil)),std::istreambuf_iterator<char>());
    int len=content.size();


    std::shared_ptr<files_io::Node> parent=std::shared_ptr<files_io::Node>(new files_io::Node("",files_io::NodeType::MAIN));
    std::shared_ptr<files_io::Node> current=parent;


    for(int i=0;i<len;i++)
    {
        int curr=(int)(unsigned char)content[i];
        switch(curr)
        {
            case files_io::NodeType::BEGIN:
            {
                i++;
                int ln=(int)(unsigned char)content[i];
                i++;
                std::string nm(content.begin()+i,content.begin()+i+ln);
                i+=ln-1;
                std::shared_ptr<files_io::Node> nnode=std::shared_ptr<files_io::Node>(new files_io::Node(nm,files_io::NodeType::BEGIN));
                nnode->SetParentNode(current);
                current->AddChildNode(nm,nnode);
            }
            break;

            case files_io::NodeType::END:
            {
                if(current->GetType()==-1)
                    break;
                current=current->GetParentNode();
            }
            break;

            case files_io::NodeType::STRING:
            {
                i++;
                int ln=(int)(unsigned char)content[i];
                i++;
                std::string nm(content.begin()+i,content.begin()+i+ln);
                i+=ln;
                ln=(int)(unsigned char)content[i];
                i++;
                std::string dt(content.begin()+i,content.begin()+i+ln);
                i+=ln-1;
                std::shared_ptr<files_io::Node> nnode=std::shared_ptr<files_io::Node>(new files_io::Node(nm,files_io::NodeType::STRING));
                nnode->SetParentNode(current);
                nnode->SetStringData(dt);
                current->AddChildNode(nm,nnode);



            }
            break;

        }
    }

    return parent;
}
