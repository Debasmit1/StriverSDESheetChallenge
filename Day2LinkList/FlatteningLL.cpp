// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node *mergeLL(Node *first,Node *second){
    Node dmyNode(0);
    Node *ptr = &dmyNode;

    first->next=NULL;

    while(first && second){
        if(first->data <= second->data){
            ptr->bottom = first;
            ptr=first;
            first=first->bottom;
        }else{
            ptr->bottom=second;
            ptr=second;
            second=second->bottom;
        }
    }

    if(first){
        ptr->bottom=first;
    }else if(second){
        ptr->bottom=second;
    }
    return dmyNode.bottom;
}

Node *flatten(Node *root)
{
   // Your code here
   if(!root || !root->next){
       return root;
   }

   root->next=flatten(root->next);
   root=mergeLL(root,root->next);

   return root;
}