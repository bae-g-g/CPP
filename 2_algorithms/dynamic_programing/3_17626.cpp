#include <iostream>
#include <vector>
#include <cmath>

/*
백준 17626


*/


int dp[50001];


int dp_fn(int input){
    if(input == 0) return 0; // 예외,탈출 조건 - 0으로 input이 들어온 경우는 계산이 끝난 경우이므로 0을 리턴합니다.

    if(dp[input] == 0) { // input이 0이 아니고 이전에 저장하지않은경우 input의 값음 재귀적으로 호출하여 그 값을 저장합니다.
        int min = input;

        for(int i = int(sqrt(input)); i>=2; i--){  // 제곱에대한 합으로 나타내는 모든 경우중 가장 큰 제곱수에 대해서 반복하여 값을 도출
            int cur = 1 + dp_fn(input - i*i); // input을 제곱인 수 + input - 제곱인수로 나누어 계산
            if( min > cur) min = cur; // 최소값이라면 갱신
        }

        dp[input] = min;
    }

    return  dp[input];



}


int main(){
    
    int N;
    std::cin >> N;
    dp_fn( N ); //N에 대해서  제곱수를 분할하며 dp배열에 저장하며 재귀적으로 호출을 합니다.
    std::cout<<dp[N]<<std::endl;
  
}