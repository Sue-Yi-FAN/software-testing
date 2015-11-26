#include <limits.h>
//#include "gtest/gtest.h>"
#include <string.h>
#include <stdio.h>


void commission();
int calcCommission(unsigned int, unsigned int, unsigned int);

void commission(){
	int locks;
	unsigned int stocks;
	unsigned barrels;
	unsigned int totalLocks = 0;
	unsigned int totalStocks = 0;
	unsigned int totalBarrels = 0;
	//scanf("%d", &locks);

	while(locks != -1){ 
	    scanf("%d %d",&stocks, &barrels);
	    totalLocks = totalLocks + locks;
	    totalStocks = totalStocks + stocks;
	    totalBarrels = totalBarrels + barrels;
	    scanf("%d", &locks);
	}
	//printf("%d", calcCommission(totalLocks, totalStocks, totalBarrels));
}

int calcCommission(unsigned int totalLocks, 
					unsigned int totalStocks, 
					unsigned int totalBarrels){
	unsigned int lockPrice = 45.0;
	unsigned int stockPrice = 30.0;
	unsigned int barrelPrice = 25.0;
	unsigned int sales, lockSales, stockSales, 
				barrelSales, commission;
	lockSales = lockPrice * totalLocks;
	stockSales = stockPrice * totalStocks;
	barrelSales = barrelPrice * totalBarrels;
	sales = lockSales + stockSales + barrelSales;
	//printf("locksSales:%d stockSales:%d barrelSales:%d\n",
		lockSales, stockSales, barrelSales);
	if(sales > 1800.0){
    	commission = 0.10 * 1000.0;           
    	commission = commission + 0.15 * 800.0;
		commission = commission + 0.2 * (sales - 1800.0);
	}
	else if(sales > 1000.0){
        commission = 0.10 * 1000.0;
        commission = commission + 0.15*(sales - 1000.0);
    }
    else{
    	commission = 0.10 * sales;
    }
    return commission;
}

/*Output("Locks sold:",totalLocks);
Output("Stocks sold:",totalStocks);
Output("Barrels sold:",totalBarrels);

Output("Total sales:", sales);
		
Output(“Commission is $”, commission)
	
}*/

int main(int argc, char **argv){
	commission();
	//::testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}