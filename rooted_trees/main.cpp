//
//  main.cpp
//  rooted_trees
//
//  Created by 村上候助 on 2017/10/10.
//  Copyright © 2017 村上候助. All rights reserved.
//

#include <iostream>
#include <stdio.h>

#define NIL -1
#define MAX 100005

struct Node {
    int p;
    int l;
    int r;
};

using namespace std;

Node nodes[MAX];
int D[MAX];

void set_depth(int u, int p){
    D[u] = p;
    if(nodes[u].r != NIL){
        set_depth(nodes[u].r, p);
    }
    else if(nodes[u].l != NIL){
        set_depth(nodes[u].l, p+1);
    }
}

void print_children(int u){
    int c = nodes[u].l;
    bool not_first = false;
    while (c!= NIL){
        if(not_first){
            cout << ", ";
        }
        cout << c ;
        c = nodes[c].r;
        not_first = true;
    }
}

int main(int argc, const char * argv[]) {
    int n, i, node_id, num_child, j, child, prev_child, root_id;
    scanf("%d", &n);
    for (i = 0; i < n; i++) nodes[i].p=nodes[i].l = nodes[i].r = NIL;
    for(i = 0; i < n; i++){
        scanf("%d", &node_id);
        scanf("%d", &num_child);
        for(j = 0; j < num_child; j++){
            scanf("%d", &child);
            nodes[child].p = node_id;
            if(j == 0) nodes[node_id].l = child;
            else nodes[prev_child].r = child;
            prev_child = child;
        }
    }
    for (i = 0; i < n; i++){
        if(nodes[i].p == NIL) root_id = i;
    }
    
    set_depth(root_id, 0);

    for(i = 0; i < n; i++){
        cout << "node "<<i;
        cout << ": parent = "<<nodes[i].p;
        cout << ", depth = "<<D[i]<<", ";
        
        if(nodes[i].p == NIL){
            cout<< "root";
        }
        else if(nodes[i].l == NIL){
            cout<<"leaf";
        }
        else{
            cout << "internal leaf";
        }
        cout <<", [";
        print_children(i);
        cout <<"]";
        cout<<endl;
    }
    return 0;
}
