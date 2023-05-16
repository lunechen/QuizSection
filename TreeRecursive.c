#include <stdio.h>
#include <stdlib.h>

struct tNode{
    int data;
    struct tNode *Lchild, *Rchild;
};

struct tNode *insert(struct tNode *curNode, int data){
    //insert
    if (curNode == NULL){
        //create new node
        struct tNode *newData = (struct tNode *) malloc(sizeof (struct tNode));
        newData->data = data;
        newData->Lchild = NULL;
        newData ->Rchild = NULL;

		//print the data
		printf("%d ", data);
        return newData;
    }
    else{   //find proper position
		printf("%d ", curNode -> data);
        if (data < curNode -> data) curNode -> Lchild = insert(curNode -> Lchild, data);
        else curNode ->Rchild = insert(curNode -> Rchild, data);
    }
    return curNode;
}

// walk through the tree
void traverse(struct tNode *curNode){
    if (curNode == NULL)return;

    traverse(curNode -> Lchild);
    printf("%d ", curNode -> data); //in-order
    traverse(curNode -> Rchild);
    
    return;
}


int find(struct tNode *curNode, int target){
	// the last
    if (curNode == NULL){
        return 0;
    }

    if (curNode->data == target){	// found
        return 1;
    }
    
	// find from the right branch
    if (target < curNode->data) find(curNode->Lchild, target);
    else find(curNode->Rchild, target);
}

// delete
void delete_tree(struct tNode* curNode){
    if (curNode == NULL) return;

	// delete the child first
    delete_tree(curNode->Lchild);
    delete_tree(curNode->Rchild);
    
	// self later
	free(curNode);
}


int main(){
	int numQuery = 0;
    int oper, target;
    scanf("%d", &numQuery);

    struct tNode *root = NULL;

    for (int i = 0; i < numQuery; i++){	// for every query
		scanf("%d %d", &oper, &target);
		if (oper == 1){		// case insert
			root = insert(root, target);
			printf("\n");
		}
		else if (oper == 2){	// case find
			if (find(root, target)){	// find
				printf("%d is in tree\n", target);
			}
			else{	//if not found
				printf("%d is not in tree\n", target);
			}
		}
    }

    //free memory
    delete_tree(root);
    return 0;
}
