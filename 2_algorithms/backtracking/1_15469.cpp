/*
백준 15469

연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열


1.포문으로  1~N 까지 시작 숫자 정해서 백트래킹
2. 시작값은 바로 스택에 넣고시작
3. 이후 dfs를 돌리는다.
4. while(1)에서 스택에 값을 빼고, 방문했는지 확인,
    4_1  방문을 안했으면 본인 방문표시,백트래킹 배열에 추가 
    4_3 이후 다시 while로 반복시작


*/

#include <iostream>
#include <vector>


int main(){
   int M,N;
   std::cin >> N>>M;
   std::vector<int> dfs_stack;
   std::vector<int> back_arr;
   int * visit = new int[N+1]();

   for(int i = 1; i<=N; i++){
    
    dfs_stack.push_back(i);

    while(1){
        if( dfs_stack.empty()) break;

        if(dfs_stack.back() == 0){
            visit[back_arr.back()] = 0;
            back_arr.pop_back();
            dfs_stack.pop_back();
        }
        else{
            

            int cur = dfs_stack.back();
            dfs_stack.pop_back();
            dfs_stack.push_back(0);
            visit[cur] = 1;
            back_arr.push_back(cur);

            if(back_arr.size() == M){
                for(auto it : back_arr){
                    printf("%d ",it);
                }
                printf("\n");
            }
            else{
                for(int k =N; k>=1; k--){
                    if(visit[k] != 1) dfs_stack.push_back(k);
                }
            }

        }// B경우 
    }

   }

}

/*

1 2 3 4

1 

스택.           | visit.  |. bakc 
B 1            | 1       | 1
B 4 3 2.       | 1.      | 1
B 4 3          | 1       | 1
B 4 3 B 4 3.   | 1 2.    | 1 2
B 4 3 B 4      | 1 2.    | 1 2
B 4 3 B 4 B 4  | 1 2 3.  | 1 2 3
B 4 3 B 4 B B  | 1 2 3 4 | 1 2 3 4
B 4 3 B 4 B    | 1 2 3.  | 1 2 3
B 4 3 B 4      | 1 2.    | 1 2
B 4 3 B        | 1 2 4.  | 1 2 4
B 4 3 B B 3.   | 1 2 4.  | 1 2 4
B 4 3 B B      | 1 2 4 3 | 1 2 4 3
B 4 3 B B B.   | 1 2 4 3 | 1 2 4 3
B 4 3 B B.     | 1 2 4.  | 1 2 4
B 4 3 B        | 1 2.    | 1 2
B 4 3          | 1       | 1
B 4            | 1 3     | 1 3
B 4 B 4 2  

*/