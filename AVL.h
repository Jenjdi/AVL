#pragma once
#include <iostream>

using namespace std;
template<typename k,typename v>
struct Node{
    Node* _right;
    Node* _left;
    Node* _parent;
    pair<k,v> _kv;
    int _bf;

    Node(const pair<k,v>& kv)
    :_right(nullptr),
    _left(nullptr),
    _kv(kv),
    _parent(nullptr)
    {};
};
template<typename k,typename v>
class AVL{
    typedef Node<k,v> node;
public:
    bool insert(const pair<k,v> kv){
        if(_root== nullptr){
            _root=new node(kv);
            return true;
        }
        node* cur=_root;
        node* parent= nullptr;
        while(cur){
            if(cur->_kv.first>kv.first){
                parent=cur;
                cur=cur->left;
            }
            else if (cur->_kv.first<kv.first){
                parent=cur;
                cur=cur->right;
            } else{
                return false;
            }
        }
        cur=new node(kv);
        if(parent->_kv.first>kv.first){
            parent->left=cur;
        } else {
            parent->right=cur;
        }
        return true;
        while(parent){
            if(cur==parent->_left){
                cur->_bf--;
            }
            else{
                cur->_bf++;
            }
            if(parent->_bf==0){
                break;
            } else if((parent->_bf)==1||(parent->_bf)==-1){
                cur=parent;
                parent=parent->_parent;
            } else if((parent->_bf)==2||(parent->_bf)==-2){
                
            }
        }
    }
    node* leftrotate(node* root){
        node* newroot=root->_right;
        node* T2=newroot->_right;
        root->_left=T2;
        newroot->_right=root;
    }
    node* rightrotate(node* root){
        node* newroot=root->_left;
        node* T2=newroot->_left;
        root->_right=T2;
        newroot->_left=root;
    }
    node* find(const pair<k,v>& kv){
        node* cur=_root;
        while(cur){
            if(cur->_kv.first>kv.first){
                cur=cur->left;
            } else if (cur->_kv.first<kv.first){
                cur=cur->right;
            } else{
                return cur;
            }
        }
        return nullptr;
    }
    bool erase(const pair<k,v>& kv){
        node* cur=_root;
        node* parent=nullptr;

        while(cur){
            if(cur->_kv.first>kv.first){
                parent=cur;
                cur= cur->_left;
            } else if (cur->_kv.first<kv.first){
                parent=cur;
                cur=cur->_right;
            } else{
                if(cur->_left== nullptr){
                    if(cur== parent->_right)
                        parent->_right=cur->_right;
                    else {
                        parent->_left= cur->_right;
                    }
                    delete cur;
                } else if(cur->_right== nullptr){
                    if(cur==parent->_right){
                        parent->_right=cur->_left;
                    } else{
                        parent->_left= cur->_right;
                    }
                    delete cur;
                } else{
                    node* rightMinParent=cur;
                    node* rightMin=cur->_right;
                    while (rightMin->_left){
                        rightMinParent=rightMin;
                        rightMin=rightMin->_left;
                    }
                    swap(rightMin,cur);
                    rightMinParent->_left=rightMin->_right;
                    delete rightMin;
                }
                return true;
            }
        }
    }
private:
    node* _root=nullptr;
};