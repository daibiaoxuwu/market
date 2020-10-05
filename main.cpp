#include <iostream>
#include <cstdlib>
const int DIGITS = 9;// 1 to 9. no 0.
int rewards[][5] = {{1,5,2},{3,4,7},{3,4,6,8},{2,5,7,8,1}}; // 1 to 9. no 0.
const int REWARD_CNT = 4, PRODUCT_LEN = 5;

const int POPULATION = 50;
const int STOCK_MAX = 10;
const int DAILY_COST = 30;
const int MAX_PRICE = 500;
const int INIT_MONEY = 3000;
const int MEMORY_MAX = 30;

int market[POPULATION + DIGITS][PRODUCT_LEN + 1] = {};

class individual{
public:
    int job[PRODUCT_LEN]{};
    int money = INIT_MONEY;
    int stock[STOCK_MAX][PRODUCT_LEN] = {}; int stockcnt = 0;
    int price = rand() % MAX_PRICE;
    int memory[MEMORY_MAX][PRODUCT_LEN+2] = {}; int memcnt = 0;

    individual() {
        change_job();
    }
    void change_job(){
        for (int & i : job) i = rand() % DIGITS+1;
    }
    void daily(){
        money = std::max(0, money - DAILY_COST);

        //choose product to buy
        int prefer = 0;
        for (int i = 0; i < POPULATION + DIGITS; ++i) {
            if (market[i][PRODUCT_LEN] > money) continue;
            
        }
        
        
    }
};

int eval_value(const int* product){
    for (auto & reward : rewards) {
        int j; for (j = 0; j < PRODUCT_LEN and reward[j] != 0 and product[j] == reward[j]; ++j);
        if(j == PRODUCT_LEN or reward[j] == 0) return MAX_PRICE / PRODUCT_LEN * j;
    }
    return 0;
}
int main() {
    for(auto & i : market) i[PRODUCT_LEN] = 100000;
    for (int i = 0; i < DIGITS; ++i) {
        market[POPULATION + i][PRODUCT_LEN] = 0;
        market[POPULATION + i][0] = i;
        market[POPULATION + i][1] = 0;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
