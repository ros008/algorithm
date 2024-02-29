//
//  main.cpp
//  5585_BOJ
//
//  Created by Sujin Kim on 2020/08/16.
//  Copyright © 2020 Sujin Kim. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int price, cnt = 0;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    
    cin >> price;
    price = 1000 - price;
    
    for(int i=0; i<6; i++){
        while(price-coin[i] >= 0){
            cnt++;
            price -= coin[i];
            if(price == 0)
                break;
        }
        
    }
    
    cout << cnt;
    
    return 0;
}
