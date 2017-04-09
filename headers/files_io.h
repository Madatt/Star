#ifndef FILES_IO_H
#define FILES_IO_H
#include <cstring>
#include <string>
#include <memory>
#include <map>
#include <vector>
#include <iostream>

namespace files_io
{
    enum NodeType
    {
        NONE=-2,
        FILE=-1,
        BEGIN=0,
        END=1,
        STRING=2,
        SHORT=3,
        INT=4,
        SHORT_ARRAY=5,
    };

    class Node
    {
        friend Node;

        std::map<std::string,files_io::Node*> nodes;
        std::vector<std::string> nodes_keys;
        files_io::Node* parent=NULL;
        NodeType type=NodeType::NONE;
        std::string name="";
        union
        {
            char* string_data;
            int int_data;
            short short_data;
            short* short_array_data;
        };
        int size=0;
        int safe_delete=0;


    public:
        int GetIntData();
        char* GetStringData();
        short GetShortData();
        short* GetShortArrayData();

        files_io::Node* GetChildNode(std::string);
        files_io::Node* GetParentNode();
        NodeType GetType(){return type;};
        std::string GetName(){return name;};
        int GetChildrenCount(){return nodes_keys.size();};
        files_io::Node* GetChildNode(int k){return GetChildNode(nodes_keys[k]);};

        void AddChildNode(std::string,files_io::NodeType );
        void SetParentNode(files_io::Node* nd){parent=nd;};

        void SetStringData(std::string,int);
        void SetShortData(short);
        void SetShortArrayData(short*,int);
        void SetArrayDataSize(int l){size=l;};
        int GetArrayDataSize(){return size;};
        int GetArraySize(){return size;};

        Node(){short_array_data=NULL;string_data=NULL;};
        Node(std::string,NodeType);
        //Node(const Node&);
        ~Node();
    };

    files_io::Node *CreateFileNode();
    files_io::Node *ReadFile(std::string);
    void WriteFile(std::string,files_io::Node* );
}



#endif
