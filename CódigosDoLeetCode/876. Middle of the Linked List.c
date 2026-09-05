/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    int contador=0, contador2=0;
    for(struct ListNode *atual=head; atual!=NULL; atual=atual->next){
        contador++;
    }
    if(contador % 2 == 0){
        contador = contador/2;
    }else{
        contador = (contador/2)+0.5; 
    };
    struct ListNode *meio;
    for(meio=head; contador2<contador ; meio=meio->next){
        contador2++;
    }
    return meio;
}
