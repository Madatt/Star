#ifndef FILES_IO_H
#define FILES_IO_H
#include <string>
#include <memory>
#include <map>
#include <vector>

namespace files_io
{
    enum NodeType
    {
        MAIN=-1,
        BEGIN=0,
        END=1,
        STRING=2,
        SHORT=3,
    };

    class Node
    {
        std::map<std::string,std::shared_ptr<files_io::Node>> nodes;
        std::shared_ptr<files_io::Node> parent;
        NodeType type=NodeType::MAIN;
        std::string name="";

        std::string string_data;
        int int_data;
        short short_data;
        std::vector<short> short_array_data;


    public:
        Node(std::string n,NodeType t){name=n;type=t;};

        int GetIntData(){return int_data;};
        std::string GetStringData(){return string_data;};
        short GetShortData(){return short_data;};
        std::vector<short> GetShortArrayData(){return short_array_data;};

        std::shared_ptr<files_io::Node> GetChildNode(std::string n){return nodes[n];};
        std::shared_ptr<files_io::Node> GetParentNode(){return parent;};
        NodeType GetType(){return type;};

        void AddChildNode(std::string n,std::shared_ptr<files_io::Node> nd){nodes[n]=nd;};
        void SetParentNode(std::shared_ptr<files_io::Node> nd){parent=nd;};

        void SetStringData(std::string d){string_data=d;};
    };


    std::shared_ptr<files_io::Node> ReadFile(std::string);
}



#endif
