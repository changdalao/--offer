class Solution {
public:
    int jumpFloor(int number) {
        if(number==0)
            return 0;
        if(number==1)
            return 1;
        int jumpone=0;
        int jumptwo=1;
        int jump=0;
        while(number>=1){
            jump=jumpone+jumptwo;
            jumpone=jumptwo;
            jumptwo=jump;
            number--;
        }
        return jump;
    }
};
