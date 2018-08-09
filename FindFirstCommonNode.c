class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(NULL == pHead1 && pHead2)
            return pHead2;
        if(NULL == pHead2 && pHead1)
            return pHead1;
        ListNode* cur=pHead1;
        ListNode* prev=pHead2;
        int length1=0,length2=0;
        while(cur){
            ++length1;
            cur=cur->next;
        }
        while(prev){
            ++length2;
            prev=prev->next;
        }
        ListNode* LengthNode=pHead1;
        ListNode* ShortNode=pHead2;
        int sumlength=0;
        if(length1 > length2){
            LengthNode=pHead1;
            ShortNode=pHead2;
            sumlength=length1-length2;
        }else{
            LengthNode=pHead2;
            ShortNode=pHead1;
            sumlength=length2-length1;
        }
        for(int i=0;i<sumlength;++i){
            LengthNode=LengthNode->next;
        }
        while(LengthNode && ShortNode && (LengthNode!=ShortNode)){
            LengthNode=LengthNode->next;
            ShortNode=ShortNode->next;
        }
        return LengthNode;
    }
};
