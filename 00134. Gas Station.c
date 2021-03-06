
//	Accepted	3 ms	c
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalGas = 0, totalCosts = 0;
    int maxCostIdx = -1, maxCost = -1;
    for(int i=0;i<costSize;i++){
        totalCosts += cost[i];
        if(cost[i] > maxCost){
            maxCostIdx = i;
            maxCost = cost[i];
        }
    }
    
    for(int i=0;i<gasSize;i++){
        totalGas += gas[i];
    }
    
    if(totalGas < totalCosts) return -1;
    
    int tmp = maxCostIdx;
    int tmpMaxgas = gas[tmp];
    int tmpMaxCost = cost[tmp];
    
    while (tmpMaxgas < tmpMaxCost || gas[tmp] >= cost[tmp]) {
        tmp--;
        if(tmp == -1) tmp = gasSize - 1;
        if(tmp == maxCostIdx) break;
        
        
        tmpMaxgas += gas[tmp];
        tmpMaxCost += cost[tmp];
    }
    
    
    return (tmp+1)%gasSize;
}

