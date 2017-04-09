#include "../headers/files_io.h"
#include <iostream>
#include <fstream>
#include <string>

files_io::Node::Node(std::string n,NodeType t)
{
    type=t;
    if(t==files_io::NodeType::FILE and n!="FILE")
        type=files_io::NodeType::NONE;
    name=n;
    short_data=NULL;
    string_data=NULL;
}


void files_io::Node::AddChildNode(std::string n,files_io::NodeType t)
{
    if(nodes.find(n)!=nodes.end() or type!=files_io::NodeType::FILE or type!=files_io::NodeType::BEGIN)
        return;
    nodes[n]=new Node(n,t);
    nodes[n]->SetParentNode(this);
    nodes_keys.push_back(n);
}

files_io::Node* files_io::Node::GetChildNode(std::string n)
{
    if(nodes.find(n)==nodes.end() || type!=files_io::NodeType::FILE || type!=files_io::NodeType::BEGIN)
        return NULL;


    return nodes[n];
}

files_io::Node* files_io::Node::GetParentNode()
{
    if(type==files_io::NodeType::NONE || type==files_io::NodeType::FILE )
        return NULL;
    return parent;
};


files_io::Node *files_io::CreateFileNode()
{
    return new files_io::Node("FILE",files_io::NodeType::FILE);
}

files_io::Node::~Node()
{
    if(string_data!=NULL and type==files_io::NodeType::STRING)
    {
        delete[] string_data;
        string_data=NULL;
    }


    if(short_array_data!=NULL and type==files_io::NodeType::SHORT_ARRAY)
    {
        delete[] short_array_data;
        short_array_data=NULL;
    }

    short_data=0;
    int_data=0;

    std::map<std::string,files_io::Node*>::iterator it;

    if(nodes.empty())
        return;

    for(it=nodes.begin();it!=nodes.end();it++)
    {
        if(it->second!=NULL)
        {
            delete it->second;
            it->second=NULL;
        }
        nodes.erase(it);
    }

}



int files_io::Node::GetIntData()
{
    if(type!=files_io::NodeType::INT)
        return 0;

    return int_data;
}

short files_io::Node::GetShortData()
{
    if(type!=files_io::NodeType::SHORT)
        return 0;

    return short_data;
}

char* files_io::Node::GetStringData()
{
    if(type!=files_io::NodeType::STRING)
        return 0;

    return string_data;
}

short* files_io::Node::GetShortArrayData()
{
    if(type!=files_io::NodeType::SHORT_ARRAY)
        return 0;

    return short_array_data;
}

void files_io::Node::SetStringData(std::string d,int s)
{
    if(type!=files_io::NodeType::STRING)
        return;

    if(string_data)
        delete[] string_data;

    string_data = new char[s+1];
    strcpy(string_data, d.c_str());
    size=s;
};

void files_io::Node::SetShortData(short d)
{
    if(type!=files_io::NodeType::SHORT)
        return;

    short_data = d;
};

void files_io::Node::SetShortArrayData(short* d,int s)
{
    if(type!=files_io::NodeType::SHORT_ARRAY)
        return;

    if(short_array_data)
        delete[] short_array_data;

    short_array_data = d;
    size=s;
};

files_io::Node* files_io::ReadFile(std::string fname)
{
    std::ifstream fil(fname, std::ios::binary);
    std::vector<char> content((std::istreambuf_iterator<char>(fil)),std::istreambuf_iterator<char>());
    int len=content.size();


    files_io::Node* parent=files_io::CreateFileNode();
    files_io::Node* current=parent;


    for(int i=0;i<len;i++)
    {
        int curr=(int)(unsigned char)content[i];
        std::string nm="";
        std::string s_data;
        short sh_data;
        short* sha_data;
        int ln=0;

        if(curr!=files_io::NodeType::END)
        {
            i++;
            ln=(int)(unsigned char)content[i];
            i++;
            nm = std::string(content.begin()+i,content.begin()+i+ln);
            i+=ln-1;
        }


        switch(curr)
        {
            case files_io::NodeType::BEGIN:
            {
                current->AddChildNode(nm,files_io::NodeType::BEGIN);
                current=current->GetChildNode(nm);

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
                ln=(int)(unsigned char)content[i];
                s_data="";
                for(int j=0;j<ln;j++)
                {
                    i++;
                    s_data+=(unsigned char)content[i];
                }

                current->AddChildNode(nm,files_io::NodeType::STRING);
                current->GetChildNode(nm)->SetStringData(s_data,ln);

            }
            break;

            case files_io::NodeType::SHORT:
            {
                i++;
                sh_data=0;
                sh_data+=(short)(content[i] <<8);
                i++;
                sh_data+=(short)(content[i]);
                current->AddChildNode(nm,files_io::NodeType::SHORT);
                current->GetChildNode(nm)->SetShortData(sh_data);

            }
            break;

            case files_io::NodeType::SHORT_ARRAY:
            {
                union
                {
                    short tshort;
                    unsigned char tbytes[2];
                };
                i++;
                tbytes[1]=(unsigned char)content[i];
                i++;
                tbytes[0]=(unsigned char)content[i];
                ln=tshort;
                sha_data=new short[ln];
                for(int j=0;j<ln;j++)
                {
                    i++;
                    tbytes[1]=(unsigned char)content[i];
                    i++;
                    tbytes[0]=(unsigned char)content[i];
                    sha_data[j]=tshort;
                }
                current->AddChildNode(nm,files_io::NodeType::SHORT_ARRAY);
                current->GetChildNode(nm)->SetShortArrayData(sha_data,ln);
                sha_data=NULL;

            }
            break;


        }
    }

    return parent;
}

void _WriteFileHelper(std::ofstream& fil,files_io::Node* nd)
{
    int s=nd->GetChildrenCount();
    fil << (unsigned char)nd->GetType();
    fil << (unsigned char)nd->GetName().length();
    for(auto j:nd->GetName())
    {
        fil <<(unsigned char)j;
    }


    switch(nd->GetType())
    {
        case files_io::NodeType::BEGIN:
        {
            for(int i=0;i<s;i++)
                _WriteFileHelper(fil,nd->GetChildNode(i));
            fil << (unsigned char)1;
        }
        break;

        case files_io::NodeType::STRING:
        {
            int l=nd->GetArrayDataSize();
            fil << (unsigned char)(l);
            for(int j=0;j<l;j++)
            {
                fil <<(char)nd->GetStringData()[j];
            }
        }
        break;

        case files_io::NodeType::SHORT:
        {

            union
            {
                short tshort;
                unsigned char tbytes[2];
            };

            tshort=nd->GetShortData();
            fil << tbytes[1];
            fil << tbytes[0];

        }
        break;

        case files_io::NodeType::SHORT_ARRAY:
        {

            union
            {
                short tshort;
                unsigned char tbytes[2];
            };

            short* sha=nd->GetShortArrayData();
            int ln=nd->GetArrayDataSize();
            tshort = ln;
            fil << tbytes[1];
            fil << tbytes[0];
            for(int i=0;i<ln;i++)
            {
                tshort=sha[i];
                fil << tbytes[1];
                fil << tbytes[0];
            }

        }
        break;


    }

}


void files_io::WriteFile(std::string fname,files_io::Node* fnd)
{
    std::ofstream fil(fname, std::ios::binary | std::ios::out);


    if(fnd->GetType()!=files_io::NodeType::FILE)
        return;

    int s=fnd->GetChildrenCount();
    for(int i=0;i<s;i++)
    {
        _WriteFileHelper(fil,fnd->GetChildNode(i));
    }

    fil.close();
}
