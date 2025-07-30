#include <iostream>
#include <vector>



int **map; // 퀸을 놓을 수 없는 자리를 표시하는 배열
int N; //입력받는 수
int ans = 0; // 재귀함수임으로 전역변수로 정답 체크.



/*
add 함수
    map함수에,해당(x,y)자리에 퀸을 놓음으로써 다음번에 퀸을 놓을 수 없는 자리를 표시

del함수
    map함수에,해당(x,y)자리에 퀸을 뺌으로써  퀸을 놓을 수 없던 자리를 놓을 수 있는 자리로 표시    

*/
void add(int x,int y){ 

    map[x][y]++;
    for(int i = 1; i <N; i++){

        if(  x+i<N  && y+i<N)  map[x+i][y+i]++;
        if(x+i<N && y-i>=0 ) map[x+i][y-i]++;
        if(x+i<N) map[x+i][y]++;
        
    }
}

void del(int x,int y){

    map[x][y]--;
    for(int i = 1; i <N; i++){
        if(  x+i<N  && y+i<N )  map[x+i][y+i]--;
        if(x+i<N && y-i>=0 ) map[x+i][y-i]--;
        if(x+i<N) map[x+i][y]--;
    }
}


void fn(int cur_step){ //퀸을 놓을 수 있는 자리를 찾아가는 재귀함수

    /*      
            탈출조건.
            마지막 칸까지 어찌저찌 놓을 수 있는 자리가 있어서 마지막 칸을 탐색하는 경우
            
            마지막 칸에서 놓을 수 있는 자리가 있다면 0~N-1까지 N개를 놓을 수 있는 한 가지 경우를 찾은것

    */
    if( N-1 == cur_step){
        for(int i = 0; i<N; i++){
            if(map[cur_step][i] == 0) ans++;
        }
        return;
    }


    /*

        현재 세로칸을 하나씩 살펴보며  놓을 수 있는 칸을 찾습니다.
        현재 자리에 퀸을 놓고, 이후 놓을 수 없는 칸을 모두 표시 한 후
        다음 세로칸으로 넘어 갑니다.
        (해당 칸에 퀸을 놓았다면 현재 가로 축은 경우의 수가 0입니다.)

        이후 백트래킹 진행을 위해 현재 표시했던 이동 불가능 경로 표시를 제거합니다.



    */


    for(int i= 0; i<N; i++){
        if(map[cur_step][i]>0) continue;

        add(cur_step,i);
        fn(cur_step+1);
        del(cur_step,i);

    }
  

}



int main(){
    
    
    std::cin >> N;
    
    // 경계조건 - 1인 경우 바로 1을 출력하고 종료.
    if(N==1){
        std::cout<<1;
        return 0;
    }


    // 전역 변수 map의 크기를 main에서 할당해줍니다.
    map = new int*[N];
    for(int i = 0; i<N; i++){
        map[i] = new int[N](); 
    }


    //체스판의 절반까지를 확인합니다. -- 대칭성을 고려하여 필요계산의 절반을 줄입니다.
    for(int i=0; i<N/2; i++){

        add(0,i);
        fn(1);
        del(0,i);
        
    }
    


    // 입력값이 홀수인경우를 위헤 중간에 놓이는 경우를 따로 계산합니다.
    int temp = ans*2;
    ans = 0;
    add(0,N/2);
    fn(1);
    std::cout<<ans+temp;

     

    
}

