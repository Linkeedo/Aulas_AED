/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode lista;
     int sobra = 0;
     lista *anterior;

     lista *cabeça = malloc ( sizeof ( lista ) );
     cabeça->next = NULL;
     cabeça->val = l1->val + l2->val;
     anterior = cabeça;

     if( cabeça->val >= 10){
            sobra = cabeça->val / 10;
            cabeça->val = cabeça->val % 10;
    }

    l1 = l1->next;
    l2 = l2->next;

     while(l1 != NULL || l2 != NULL || sobra != 0){
        lista *novo = malloc ( sizeof ( lista ) );
        novo->next = NULL;
        anterior->next = novo;
        anterior = novo;
        int valorl1 = 0, valorl2 = 0;
        if(l1 != NULL)
            valorl1 = l1->val;
        if(l2 != NULL)
            valorl2 = l2->val;

        novo->val = valorl1 + valorl2 + sobra;
        sobra = 0;

        if( novo->val >= 10){
            sobra = novo->val / 10;
            novo->val = novo->val % 10;
        }
        
        if(l1 != NULL)
            l1 = l1->next;
        if(l2 != NULL)    
            l2 = l2->next;
     };

    return cabeça;
}
