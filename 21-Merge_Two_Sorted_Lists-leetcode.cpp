#include <bits/stdc++.h>
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        vector <int> vec;
        ListNode *temp = NULL,*head = NULL,*tail = NULL; 
        while(list1!=NULL) { 
            vec.push_back(list1->val); 
            list1=list1->next; 
        } 
        
        while(list2!=NULL){ 
            vec.push_back(list2->val); 
            list2=list2->next; 
        } 
        
        sort(vec.begin(),vec.end()); 
        
        for(auto &it:vec) { 
           temp=(ListNode*)malloc(sizeof(ListNode)); 
           temp->val=it; 
           temp->next=NULL; 
           if(head==NULL)head=temp; 
           else tail->next=temp; 
           tail=temp; 
        } 
        return head;
        
}

int main()
{   
    return 0;
}

