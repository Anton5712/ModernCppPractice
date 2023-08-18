#include <iostream>
#include <cstddef>
#include <memory>

struct Node
{
    size_t _key {0};
    size_t _value {0};
    std::shared_ptr<Node> _left  {nullptr};
    std::shared_ptr<Node> _right {nullptr};

    Node(size_t key, size_t value) : _key{key}, _value{value} {};
};

void InsertNode(std::shared_ptr<Node> node, size_t key, size_t value)
{
    if (node == nullptr) {
       auto root = std::make_shared<Node>(key, value);
       return;
    }

    if (key < node->_key) {
        if (node->_left == nullptr)
            node->_left = std::make_shared<Node>(key, value);
        else
            InsertNode(node->_left, key, value );
    }
    else if (key >= node->_key) {
        if (node->_right == nullptr)
            node->_right = std::make_shared<Node>(key, value);
        else
            InsertNode(node->_right, key, value);
    }
}

void PrintTree(std::shared_ptr<Node> node)
{
    if (node == nullptr) 
        return;
    
    PrintTree(node->_left);
    std::cout << "key: " <<node->_key << "; value:" << node->_value << ";" << std::endl;  
    PrintTree(node->_right); 
}

std::shared_ptr<Node> Search(std::shared_ptr<Node> node, size_t key)
{
    if (node == nullptr)
        return node;
    if (node->_key == key)
        return node;
    
    return (key < node->_key) ? Search(node->_left, key) : Search(node->_right, key);
}

std::shared_ptr<Node> GetMaxNode(std::shared_ptr<Node> node)
{
    if (node == nullptr)
        return node;

    if (node->_right == nullptr) 
        return node;
    
    return GetMaxNode(node->_right);
}

std::shared_ptr<Node> GetMinNode(std::shared_ptr<Node> node)
{
    if (node == nullptr)
        return node;

    if (node->_left == nullptr)
        return node;

    return GetMinNode(node->_left);
}

std::shared_ptr<Node> DeleteNode(std::shared_ptr<Node> node, size_t key)
{
    if (node == nullptr)
        return nullptr;
    else if (key < node->_key) node->_left = DeleteNode(node->_left, key);
    else if (key > node->_key) node->_right = DeleteNode(node->_right, key);
    else {
        if (node->_left == nullptr || node->_right == nullptr)
            node = (node->_left == nullptr) ? node->_right : node->_left;
        else {
            auto maxNodeInLeft = GetMaxNode(node->_left);
            node->_key = maxNodeInLeft->_key;
            node->_value = maxNodeInLeft->_value;
            node->_left = DeleteNode(node->_left, maxNodeInLeft->_key);
        }
    }

    return node;
}