#include <iostream>
#include <vector>
#include <string>



long long sq(int n){
    
    int ans =1;

    for(int i = 1; i<=n ; i++) ans *=10;
    
    return  ans;

}


void fn(std::vector<long long> graph,long long visit[],int cnt,long long sum, bool &flag    ) {

    if(flag) return; //탈출 조건 1 - 정답이 이미 나온경우

    
    if( cnt  >= graph.size()){ 
    /*
        탈출 조건 2
        알파벳과 숫자를 모두 대응시킨 경우
        여기서 만약 해결이 되는경우 flag를 true로 바꾸고 모든 계산을 중단 시킵니다.
    */  
        if(sum == 0) flag = true;
        return;

    }

    for(int i = 0; i<10; i++){
        /*
        재귀 호출
        0~9까지 반복하며  대응되지 않은 숫자의 경우 대응을 시킨 후 다음 단계로 이동 합니다.
        cnt로 현재 대응 시킨 숫자의 갯수를,
        sum으로 대응 시켜 계산된 값을 전달 합니다.
        */
        if(visit[i]) continue;

        visit[i] = graph[cnt];
                
        fn(graph,visit,cnt+1,sum + visit[i]*i,flag);

        visit[i] = 0;

    }
}



int main(){

    /*
    피연산자 두 개와
    결과에 대한 문자열을 입력받습니다.
    각 알파벳에 해당하는 배열 인덱스공간에[input - 'A'] 자리수 10^n에 맞게  count_arr에 값을 저장합니다.
    -> SWIM인경우   S*10^4  + W*10^3 + I*10^2 + M*10^1
                count_arr['S'-'A'] += 10^4  count_arr['W'-'A'] += 10^3 ......
    이후 백트래킹을 진행하기 위해 입력으로 들어온 알파벳만을 저장하도록 graph라는 벡터에  데이터를 저장합니다. 
    */
    long long count_arr[27] ={};
    std::string operands1;
    std::string operands2;
    std::string result;
    
    std::cin>>operands1>>operands2>>result;

    
    for( int i = 0; i <operands1.length(); i++ ) count_arr[ operands1[i]-'A' ] -= sq(operands1.length()-1-i);
    for( int i = 0; i <operands2.length(); i++ ) count_arr[ operands2[i]-'A' ] -= sq(operands2.length()-1-i);

    for( int i = 0; i <result.length(); i++ ) count_arr[ result[i]-'A' ] += sq(result.length()-1-i);


    std::vector<long long> graph;
    for(int i = 0; i<26; i++){
        if(count_arr[i] != 0)    graph.push_back( count_arr[i] );
    } 


    //-------------------------------------------
    /*
        
        어떤 알파벳을 0~9까지 대응 시키는 경우를 따져야 하기 때문에
        알파벳을 대응시키기 위해 해당 숫자를 사용했는지 안했는지를 나타 내는 visit배열을 선언합니다.
        문제해결상태를 나타내는 flag변수를 선언합니다.

        
    */

    long long visit[10] = {};
    bool flag = false;

    for( int i =0; i<10; i++){

        if(flag) break;

        visit[i] = graph[0];

        fn(graph,visit,1, i*visit[i], flag);

        visit[i] = 0;
    
    }
    
    
    if( flag )      std::cout<<"YES"<< std::endl;
    else            std::cout<<"NO"<<std::endl;
    
    
    


  
}
