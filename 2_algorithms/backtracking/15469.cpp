/*
백준 15469

연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열



*/

#include <iostream>



int main(){
    int N,M;
    std::cin >> N>>M;

    //-------백트래킹 과정을 저장할 배열선언 ------
    int* back_arr = new int[M]();
    int back_top = 0;

    //------백트래킹을 위한 dfs 배열,변수 선언 -------
    int* dfs_visit = new int[N+1](); 
    int st_size = 1;   
    for(int i=N-M + 1; i<=N; i++){ 
        st_size = st_size*i;
    }
    int* dfs_stack = new int[st_size](); 
    int dfs_top = 0;

    
    //---- 백트래킹--------
    for(int i = 1; i<=N; i++){

        dfs_stack[dfs_top] = i;
        dfs_top++;
        back_top = 0;
        while(1){
            
            if(dfs_top == 0) break;
            
            int cur = dfs_stack[dfs_top];
            dfs_top--;
            dfs_visit[cur] = 1;
            back_arr[back_top] = cur;
            back_top++;
            
            for(int i = N; i>= 0; i--){
                if(dfs_visit[i] == 0){
                    dfs_stack[dfs_top] = i;
                    dfs_top++;
                }
            }
            
              
            

        }

    }



}