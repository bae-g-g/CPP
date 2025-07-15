
#include <iostream>

int iteam[101][2]; // 항목들 [0] = 무게   // [1] = 가치


enum  {
    Weight = 0,
    Value = 1
};


int main(){

    int IteamNum;
    int WeightLimit;

    long long WeightSum = 0;
    int ans = 0;


    std::cin >> IteamNum;
    std::cin >> WeightLimit;

    for(int i = 0; i< IteamNum; i++ ){
        std::cin >> iteam[i][Weight]; 
        std::cin >> iteam[i][Value];
    }
}
/*


#include <iostream>

int dp[101][100000]={0}; //항목, 용량무게
int pair[101][2] = { 0 };

int main(){
int N;
int Max_Kg;

std::cin >> N;
std::cin >> Max_Kg;

for(int i = 1; i<=N; i++){

    std::cin >> pair[i][0]; //무게
    std::cin >> pair[i][1]; //가치

}

for(int i = 0; i<= N; i++){
    
    if(i == 0){
        for(int cur_cap = 0 ; cur_cap<=Max_Kg; cur_cap++){
            dp[i][cur_cap] = 0;
        }
    }
    else{
        for(int cur_cap = 0 ; cur_cap<=Max_Kg; cur_cap++){

            dp[i][cur_cap] = dp[i-1][cur_cap];
            if(cur_cap - pair[i][0]>= 0){

                if( dp[i-1][cur_cap-pair[i][0]] + pair[i][1]  > dp[i][cur_cap] ){
                    dp[i][cur_cap] =  dp[i-1][cur_cap-pair[i][0]] + pair[i][1];
                }

            }
            
        }

    }

}
std::cout << dp[N][Max_Kg];

}

*/