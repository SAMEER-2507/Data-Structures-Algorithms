class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++){
            int money=bills[i];
            if(money==5){
                five++;
            }else if(money==10){
                if(!five){
                    return 0;
                }
                five--;
                ten++;
            }else{
                if(ten>0){
                    ten--;
                    if(!five){
                        return 0;
                    }
                    five--;
                }else{
                    if(five<3){
                        return 0;
                    }
                    five-=3;
                }
            }
        }
        return 1;
    }
};