#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <algorithm>
#include <memory>
#include <vector>
constexpr unsigned int N = 3;
struct tree_node{
    unsigned int color;
    std::vector<std::unique_ptr<tree_node>> children;
    std::vector<std::reference_wrapper<std::unique_ptr<tree_node>>> flat;
};
bool is_embeddable(const tree_node& t1,const tree_node& t2){
    
}
int main(){
    
}